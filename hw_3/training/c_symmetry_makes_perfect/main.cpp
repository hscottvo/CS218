#include <bits/stdc++.h>

using namespace std;

int SIZE = 6;

int main() {
  int n, k;

  cin >> n >> k;

  vector<int> costs;
  costs.reserve(n);
  while (k--) {
    int val;
    cin >> val;
    costs.push_back(val);
  }

  string str;
  cin >> str;

  // cout << str << endl;
  SIZE = (int)str.size();
  vector<int> chars;
  chars.reserve(SIZE);

  for (auto i : str) {
    chars.push_back(i - 'a');
  }
  for (int i = 0; i < (int)str.size(); i++) {
    // cout << str.at(i) << ", " << chars.at(i) << ", " << costs.at(chars.at(i))
    //      << endl;
  }

  vector<vector<int>> dp(SIZE, vector<int>(SIZE, -1));
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      dp.at(i).at(j) = i * SIZE + j;
    }
  }

  for (int i = 0; i < SIZE; i++) {
    dp.at(i).at(i) = 0;
  }
  for (int i = 0; i < SIZE - 1; i++) {
    dp.at(i + 1).at(i) = 0;
  }

  for (int i = 1; i < SIZE; i++) {
    int delta = SIZE - i;
    for (int j = 0; j < delta; j++) {
      // row: starting letter
      // col: ending letter
      int row = j;
      int col = j + i;
      // cout << "row: " << row << ", col: " << col << endl;
      // dp.at(row).at(col) = i;
      if (chars.at(row) == chars.at(col)) {
        dp.at(row).at(col) = dp.at(row + 1).at(col - 1);
      } else {
        int left = INT_MAX;
        int down = INT_MAX;
        left = dp.at(row).at(col - 1) + costs.at(chars.at(col));
        down = dp.at(row + 1).at(col) + costs.at(chars.at(row));
        dp.at(row).at(col) = min(left, down);
      }
    }
  }

  // cout << endl;
  // for (auto i : dp) {
  //   for (auto j : i) {
  //     cout << j << '\t';
  //   }
  //   cout << endl;
  // }
  cout << dp.at(0).at(SIZE - 1) << endl;

  return 0;
}
