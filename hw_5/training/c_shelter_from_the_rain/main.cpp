#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
  // return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

bool valid(int x1, int y1, int x2, int y2, int r) {
  double dist = distance(x1, y1, x2, y2);
  double dist_run = r;

  return dist <= dist_run;
}

bool find(int i, int m, int n, vector<bool> &b, vector<int> &p,
          vector<vector<bool>> &adj) {
  for (int j = 0; j < m; j++) {
    // if (i >= (int)adj.size()) {
    //   cout << "-1" << endl;
    //   exit(0);
    // }

    // if (j + n >= (int)adj.at(0).size()) {
    //   cout << "-1" << endl;
    //   exit(0);
    // }

    if (j >= (int)b.size()) {
      cout << "-1" << endl;
      exit(0);
    }

    // if (j >= (int)p.size()) {
    //   cout << "-1" << endl;
    //   exit(0);
    // }

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
    r[i] = pow(r_val * b, 2);
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

  vector<int> p(m, -1);
  int count = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> b(n + m, false);
    if (!find(i, m, n, b, p, adj)) {
      count++;
    }
  }
  cout << count << endl;

  return 0;
}
