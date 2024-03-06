#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool valid(int x1, int y1, int x2, int y2, int r) {
  double dist = distance(x1, y1, x2, y2);
  // double dist_run = double(r) * double(b);
  double dist_run = r;
  // cout << "Dist: " << dist << ", Dist Run: " << dist_run << endl;

  return dist <= dist_run;
  // return false;
}

// bfs
void calc_levels(vector<vector<bool>> &adj, vector<int> &levels) {
  assert(adj.size() == levels.size());
  unordered_set<int> visited;
  queue<pair<int, int>> bfs;
  bfs.push(make_pair(adj.size() - 2, 0));
  while (!bfs.empty()) {
    auto curr = bfs.front();
    bfs.pop();
    if (visited.find(curr.first) != visited.end()) {
      continue;
    }
    levels.at(curr.first) = curr.second;
    visited.insert(curr.first);
    for (unsigned int i = 0; i < adj.size(); i++) {
      if (adj.at(curr.first).at(i)) {
        bfs.push(make_pair(i, curr.second + 1));
      }
    }
  }
}

int main() {
  int n, m, b;

  cin >> n >> m >> b;

  vector<int> x(n + m);
  vector<int> y(n + m);
  vector<int> r(n);

  vector<vector<bool>> adj(n + m + 2, vector<bool>(n + m + 2, false));

  for (int i = 0; i < n; i++) {
    int x_val, y_val, r_val;
    cin >> x_val >> y_val >> r_val;
    x[i] = x_val;
    y[i] = y_val;
    r[i] = r_val * b;
  }

  for (int i = 0; i < m; i++) {
    int x_val, y_val;
    cin >> x_val >> y_val;
    x[n + i] = x_val;
    y[n + i] = y_val;
  }

  for (int i = 0; i < n; i++) {
    // cout << "Looking at " << (char)(i + 'a') << endl;
    for (int j = n; j < n + m; j++) {
      // int x1, y1, x2, y2, r_val, b;
      int x1 = x[i];
      int y1 = y[i];
      int x2 = x[j];
      int y2 = y[j];
      int r_val = r[i];
      if (valid(x1, y1, x2, y2, r_val)) {
        adj[i][j] = true;
      }
    }
  }

  for (int i = n; i < n + m; i++) {
    adj[i][adj.size() - 1] = true;
  }
  for (int i = 0; i < n; i++) {
    adj[adj.size() - 2][i] = true;
  }

  // // cout << "  a b c d e 1 2 3 4 5 s t" << endl;
  // cout << "  a b c 1 2 3 s t" << endl;
  // for (unsigned int i = 0; i < adj.size(); i++) {
  //   if ((int)i < n) {
  //     cout << char(i + 'a') << ' ';
  //   } else if ((int)i < n + m) {
  //     cout << (int)i - n + 1 << ' ';
  //   } else if (i == adj.size() - 2) {
  //     cout << "s ";
  //   } else {
  //     cout << "t ";
  //   }
  //   for (unsigned int j = 0; j < adj[i].size(); j++) {
  //     cout << adj[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  vector<int> levels(n + m + 2);
  vector<int> parent(n + m + 2, -1);
  for (int i = 0; i < n; i++) {
    parent.at(i) = adj.size() - 2;
  }
  calc_levels(adj, levels);

  // cout << "Levels: ";
  // for (auto i : levels) {
  //   cout << i << ' ';
  // }
  // cout << endl;

  stack<int> dfs;
  int s = adj.size() - 2;
  int t = adj.size() - 1;
  dfs.push(adj.size() - 2);
  while (!dfs.empty()) {
    int curr = dfs.top();
    if (curr == t) {
      queue<pair<int, int>> path;
      int parent_node = parent.at(t);
      int current_node = t;
      bool valid = false;
      if (adj.at(parent_node).at(current_node)) {
        // path.push(make_pair(parent_node, current_node));
        valid = true;
      }

      // adj.at(parent_node).at(current_node) = false;
      // adj.at(current_node).at(parent_node) = true;
      while (valid && parent_node != -1) {
        valid = valid && adj.at(parent_node).at(current_node);
        if (!valid) {
          break;
        }

        path.push(make_pair(parent_node, current_node));
        current_node = parent_node;
        parent_node = parent.at(current_node);
        //   adj.at(parent_node).at(current_node) = false;
        //   adj.at(current_node).at(parent_node) = true;
      }
      if (valid) {
        while (!path.empty()) {
          auto edge = path.front();
          int l = edge.first;
          int r = edge.second;
          // cout << "l: " << l << " r: " << r << endl;
          path.pop();

          swap(adj.at(l).at(r), adj.at(r).at(l));
        }
      }

      // cout << "  a b c d e 1 2 3 4 5 s t" << endl;
      // cout << "  a b c 1 2 3 s t" << endl;
      // for (unsigned int i = 0; i < adj.size(); i++) {
      //   if ((int)i < n) {
      //     cout << char(i + 'a') << ' ';
      //   } else if ((int)i < n + m) {
      //     cout << (int)i - n + 1 << ' ';
      //   } else if (i == adj.size() - 2) {
      //     cout << "s ";
      //   } else {
      //     cout << "t ";
      //   }
      //   for (unsigned int j = 0; j < adj[i].size(); j++) {
      //     cout << adj[i][j] << ' ';
      //   }
      //   cout << endl;
      // }
    }
    dfs.pop();
    for (unsigned int i = 0; i < adj.size(); i++) {
      if (adj.at(curr).at(i) && levels.at(curr) == levels.at(i) - 1) {
        dfs.push(i);
        parent.at(i) = curr;
      }
    }
    calc_levels(adj, levels);
  }

  // cout << "Parents ";
  // for (auto i : parent) {
  //   cout << i << ' ';
  // }
  // cout << endl;

  // // cout << "  a b c d e 1 2 3 4 5 s t" << endl;
  // cout << "  a b c 1 2 3 s t" << endl;
  // for (unsigned int i = 0; i < adj.size(); i++) {
  //   if ((int)i < n) {
  //     cout << char(i + 'a') << ' ';
  //   } else if ((int)i < n + m) {
  //     cout << (int)i - n + 1 << ' ';
  //   } else if (i == adj.size() - 2) {
  //     cout << "s ";
  //   } else {
  //     cout << "t ";
  //   }
  //   for (unsigned int j = 0; j < adj[i].size(); j++) {
  //     cout << adj[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  int out = 0;
  for (int i = 0; i < n; i++) {
    if (adj.at(s).at(i)) {
      out++;
    }
  }
  cout << out << endl;

  return 0;
}
