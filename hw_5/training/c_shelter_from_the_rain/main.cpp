#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool valid(int x1, int y1, int x2, int y2, int r) {
  double dist = distance(x1, y1, x2, y2);
  double dist_run = r;

  return dist <= dist_run;
}

bool find(int i, int m, int n, vector<bool> &b, vector<int> &p,
          vector<vector<bool>> adj) {
  for (int j = 0; j < m; j++) {
    if (adj.at(i).at(j + n) && !b.at(j)) {
      b.at(j) = true;
      if (p.at(j) == -1 || find(p.at(j), m, n, b, p, adj)) {
        p.at(j) = i;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n, m, b;

  cin >> n >> m >> b;

  vector<int> x(n + m);
  vector<int> y(n + m);
  vector<int> r(n);

  vector<vector<bool>> adj(n + m, vector<bool>(n + m, false));

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
    for (int j = n; j < n + m; j++) {
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

  // cout << "  a b c 1 2 3" << endl;
  // for (unsigned int i = 0; i < adj.size(); i++) {
  //   if ((int)i < n) {
  //     cout << char(i + 'a') << ' ';
  //   } else if ((int)i < n + m) {
  //     cout << (int)i - n + 1 << ' ';
  //   }
  //   for (unsigned int j = 0; j < adj[i].size(); j++) {
  //     cout << adj[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  vector<int> p(m, -1);
  int count = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> b(n, false);
    // cout << find(i, m, n, b, p, adj) << endl;
    if (!find(i, m, n, b, p, adj)) {
      count++;
    }
  }
  cout << count << endl;

  // cout << "  a b c 1 2 3" << endl;
  // for (unsigned int i = 0; i < adj.size(); i++) {
  //   if ((int)i < n) {
  //     cout << char(i + 'a') << ' ';
  //   } else if ((int)i < n + m) {
  //     cout << (int)i - n + 1 << ' ';
  //   }
  //   for (unsigned int j = 0; j < adj[i].size(); j++) {
  //     cout << adj[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  return 0;
}
