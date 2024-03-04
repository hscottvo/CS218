#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int find(int node, vector<int> &parent) {
  if (parent.at(node) == node) {
    return node;
  } else {
    parent.at(node) = find(parent.at(node), parent);
    return parent.at(node);
  }
}

// parent: parent.at(i) is the top of union tree that i belongs to
// size: size.at(i) is the height of the tree that i belongs to
void union_set(int x, int y, vector<int> &parent, vector<int> &size,
               unordered_set<int> &visited) {
  if (find(x, parent) != find(y, parent)) {
    if (size.at(x) > size.at(y)) {
      parent.at(parent.at(y)) = parent.at(x);
      parent.at(y) = parent.at(x);
      size.at(x) = max(size.at(x), size.at(y) + 1);
      size.at(y) = size.at(x);
    } else {
      parent.at(parent.at(x)) = parent.at(y);
      parent.at(x) = parent.at(y);
      size.at(y) = max(size.at(y), size.at(x) + 1);
      size.at(x) = size.at(y);
    }
    visited.insert(x);
    visited.insert(y);
  }
}

bool test(int x, int y, vector<int> &parent) {
  return find(x, parent) == find(y, parent);
}

struct cmp {
  bool operator()(const pair<int, pair<int, int>> &l,
                  const pair<int, pair<int, int>> &r) {
    return l.first > r.first;
  }
};

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> shyness(r);
  vector<int> parent(r * c);
  unordered_set<int> visited;

  for (unsigned int i = 0; i < parent.size(); i++) {
    parent.at(i) = i;
  }
  vector<int> size(r * c, 1);

  int val;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> val;
      shyness.at(i).push_back(val);
    }
  }

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 cmp>
      pq;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c - 1; j++) {
      auto left = shyness.at(i).at(j);
      auto right = shyness.at(i).at(j + 1);
      pq.push(make_pair(min(left, right), make_pair(i * c + j, i * c + j + 1)));
    }
  }

  for (int i = 0; i < r - 1; i++) {
    for (int j = 0; j < c; j++) {
      auto top = shyness.at(i).at(j);
      auto bot = shyness.at(i + 1).at(j);
      pq.push(make_pair(min(top, bot), make_pair(i * c + j, (i + 1) * c + j)));
    }
  }

  long total_cost = 0;
  while (!pq.empty()) {
    auto elem = pq.top();
    pq.pop();

    auto l = elem.second.first;
    auto r = elem.second.second;
    auto cost = elem.first;

    if (!test(l, r, parent)) {
      union_set(l, r, parent, size, visited);
      total_cost += cost;
    }
  }

  cout << total_cost << endl;

  return 0;
}
