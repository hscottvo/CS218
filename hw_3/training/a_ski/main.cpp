#include <bits/stdc++.h>

using namespace std;

int max_length = 0;

void solve(vector<vector<int>> &board, vector<vector<int>> &dp, int y, int x) {
  if (y < 0 || (unsigned int)y >= dp.size() || x < 0 ||
      (unsigned int)x >= dp.at(0).size()) {
    return;
  }
  if (dp.at(y).at(x) != -1) {
    return;
  }
  dp.at(y).at(x) = 0;
  int moves_x[] = {-1, 0, 1, 0};
  int moves_y[] = {0, -1, 0, 1};

  for (int i = 0; i < 4; i++) {
    int move_x = x + moves_x[i];
    int move_y = y + moves_y[i];
    if (move_y < 0 || (unsigned int)move_y >= dp.size() || move_x < 0 ||
        (unsigned int)move_x >= dp.at(0).size()) {
      continue;
    }

    if (board.at(move_y).at(move_x) < board.at(y).at(x)) {
      solve(board, dp, move_y, move_x);
      dp.at(y).at(x) = max(dp.at(y).at(x), dp.at(move_y).at(move_x) + 1);
    }
  }
}

int main() {

  int r, c;

  cin >> r >> c;
  vector<vector<int>> board(r, vector<int>(c, -1));
  vector<vector<int>> dp(r, vector<int>(c, -1));

  int val;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // cout << "I: " << i << ", J: " << j << endl;
      cin >> val;
      board.at(i).at(j) = val;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      solve(board, dp, i, j);
      max_length = max(max_length, dp.at(i).at(j));
    }
  }

  // int max_length = 0;
  // for (int i = 0; i < r; i++) {
  //   for (int j = 0; j < c; j++) {
  //     max_length = max(max_length, dp.at(i).at(j));
  //   }
  // }
  cout << max_length + 1 << endl;

  return 0;
}
