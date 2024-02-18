#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> in;
  in.reserve(n);
  vector<int> dp(n, 1);
  vector<int> lis(n, 1);
  vector<int> lis_reversed(n, 1);

  while (n--) {
    int val;
    cin >> val;

    in.push_back(val);
  }

  lis.at(0) = 1;
  lis_reversed.at(in.size() - 1) = 1;

  for (int i = 1; i < (int)lis.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (in.at(j) < in.at(i)) {
        lis.at(i) = max(lis.at(i), lis.at(j) + 1);
      }
    }
  }

  for (int i = (int)lis_reversed.size() - 2; i >= 0; i--) {
    for (auto j = i + 1; j < (int)lis_reversed.size(); j++) {
      if (in.at(j) < in.at(i)) {
        lis_reversed.at(i) = max(lis_reversed.at(i), lis_reversed.at(j) + 1);
      }
    }
  }

  for (int i = 1; i < (int)lis.size() - 1; i++) {
    int left = 0;
    int right = 0;
    for (auto j = 0; j < (int)i; j++) {
      if (in.at(j) < in.at(i)) {
        left = max(left, lis.at(j));
      }
    }
    for (int j = i + 1; j < (int)in.size(); j++) {
      if (in.at(j) < in.at(i)) {
        right = max(right, lis_reversed.at(j));
      }
    }
    if (left > 0 && right > 0) {
      dp.at(i) = left + right + 1;
    }
  }

  int out = 0;

  for (auto i : dp) {
    out = max(out, i);
  }

  cout << out << endl;

  return 0;
}
