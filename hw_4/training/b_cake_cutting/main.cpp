#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> slices(n);
  vector<vector<long long>> dp(n, vector<long long>(n, -1));

  for (long long i = 0; i < n; i++) {
    long long val;
    cin >> val;
    slices.at(i) = val;
  }

  if (n == 1) {
    cout << slices.at(0) << endl;
    return 0;
  }

  if (n == 2) {
    cout << max(slices.at(0), slices.at(1)) << endl;
    return 0;
  }

  for (long long i = 0; i < n; i++) {
    dp.at(i).at(i) = slices.at(i);
    dp.at(i).at((i + 1 + n) % n) =
        max(slices.at(i), slices.at((i + 1 + n) % n));
  }

  // for (auto i : slices) {
  //   cout << i << ' ';
  // }
  // cout << endl << endl;
  // for (auto i : dp) {
  //   for (auto j : i) {
  //     cout << j << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  long long take_left = 0;
  long long take_right = 0;
  for (long long k = 2; k != 0; k = (k + 1) % n) {
    // long long delta = n - i;
    for (long long l = 0; l < n; l++) {
      // cout << l << ", " << (k + l) % n << endl;
      long long i = l;
      long long j = (k + l) % n;

      // take right: can be left->(left or down)
      // take_right = slices.at(j) + min(dp.at(i).at((j + n - 2) % n),
      //                                 dp.at((i + 1) % n).at((j + n - 1) %
      //                                 n));
      // take left: can be down->(left or down)
      // take_left = slices.at(i) + min(dp.at((i + 2) % n).at(j),
      //                                dp.at((i + 1) % n).at((j + n - 1) % n));

      take_left = slices.at(i);
      if (slices.at((i + 1) % n) > slices.at(j)) {
        take_left += dp.at((i + 2) % n).at(j);
      } else {
        take_left += dp.at((i + 1) % n).at((j + n - 1) % n);
      }
      // cout << "\ttake_left: " << take_left << endl;

      take_right = slices.at(j);
      if (slices.at(i) > slices.at((j + n - 1) % n)) {
        take_right += dp.at((i + 1) % n).at((j + n - 1) % n);
      } else {
        take_right += dp.at(i).at((j + n - 2) % n);
      }
      // cout << "\ttake_right: " << take_right << endl;

      dp.at(i).at(j) = max(take_left, take_right);

      // for (auto a : dp) {
      //   for (auto b : a) {
      //     cout << b << ' ';
      //     if (b >= 0 && b < 10)
      //       cout << ' ';
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
  }

  // for (auto i : dp) {
  //   for (auto j : i) {
  //     cout << j << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  long long out = 0;
  for (long long i = 0; i < n; i++) {
    // cout << i << ", " << (i + n - 1) % n << endl;
    out = max(out, dp.at(i).at((i + n - 1) % n));
  }
  cout << out << endl;

  return 0;
}
