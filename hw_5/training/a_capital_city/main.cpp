#include <iostream>
// #include <unordered_set>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int find(int key, vector<int> &parent, vector<int> &size) {
  cout << "Looking for " << key << endl;
  if (parent.at(key) != key) {
    cout << '\t' << key << "'s parent is " << parent.at(key) << endl;
    return find(parent.at(key), parent, size);
  } else {
    cout << key << " is the root. Returning..." << endl;
    return key;
  }

  return 0;
}

bool same_set(int x, int y, vector<int> &parent, vector<int> &size) {
  return find(x, parent, size) == find(y, parent, size);
}

void union_set(int x, int y, vector<int> &parent, vector<int> &size) {
  int x_prime = find(x, parent, size);
  int y_prime = find(y, parent, size);
  if (x_prime != y_prime) {
    parent.at(x_prime) = y_prime;
    size.at(y_prime) += size.at(x_prime);
  }
}

int main() {
  int m, n;
  cin >> n >> m;

  vector<unordered_set<int>> reachable(n + 1);
  vector<vector<int>> graph(n + 1);

  // vector<int> size(n + 1, 1);

  int start, dest;
  while (m--) {
    cin >> start >> dest;
    graph.at(start).push_back(dest);
    // if (!same_set(start, dest, parent, size)) {
    //   union_set(start, dest, parent, size);
    // }
  }

  // for (auto i : graph) {
  //   for (auto j : i) {
  //     cout << j << ' ';
  //   }
  //   cout << endl;
  // }

  unordered_set<int> visited;

  for (int i = 1; i <= n; i++) {
    queue<int> q;
    visited = unordered_set<int>();
    q.push(i);
    // reachable.at(i).insert(i);

    while (!q.empty()) {
      int val = q.front();
      q.pop();

      if (visited.find(val) != visited.end()) {
        continue;
      } else {
        visited.insert(val);
        reachable.at(val).insert(i);

        for (auto j : graph.at(val)) {
          if (visited.find(j) == visited.end()) {
            q.push(j);
          }
        }
      }
    }
  }

  vector<int> out;
  for (unsigned int i = 1; i < reachable.size(); i++) {
    // cout << i.size() << endl;
    if ((int)reachable.at(i).size() == n) {
      out.push_back(i);
    }
    // for (auto j : i) {
    //   cout << j << ' ';
    // }
    // cout << endl;
  }

  cout << out.size() << endl;
  for (auto i : out) {
    cout << i << ' ';
  }
  // cout << endl;

  return 0;
}
