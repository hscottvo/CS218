#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool check(vector<vector<bool>> &vec) {
  for (auto i : vec) {
    for (auto j : i) {
      if (j) {
        return j;
      }
    }
  }

  return false;
}

void kill(vector<vector<bool>> &vec, int val) {
  val--;
  if (val >= 5) {
    val -= 5;
    for (int row = 0; row < vec.size(); row++) {
      vec[row][val] = false;
    }
  } else {
    for (int col = 0; col < vec[0].size(); col++) {
      vec[val][col] = false;
    }
  }
}

queue<int> print_queue(queue<int> in) {
  queue<int> ret;

  while (!in.empty()) {
    cout << in.front() << ' ';
    ret.push(in.front());
    in.pop();
  }

  return ret;
}

void print(vector<vector<bool>> &vec) {
  for (auto i : vec) {
    for (auto j : i) {
      cout << (j ? "o" : "x") << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

bool valid(int row, int col) {
  return row >= 0 && row < 5 && col >= 0 && col < 5;
}

void floodfill(vector<vector<bool>> &vec, int depth) {
  if (depth <= 0) {
    return;
  }
  vector<vector<bool>> ret(5, vector<bool>(5, false));

  int moves_x[] = {-1, 0, 1, 0};
  int moves_y[] = {0, -1, 0, 1};

  for (unsigned int row = 0; row < vec.size(); row++) {
    for (unsigned int col = 0; col < vec[0].size(); col++) {
      if (!vec[row][col]) {
        continue;
      }
      ret[row][col] = true;
      for (int i = 0; i < 4; i++) {
        int move_x = col + moves_x[i];
        int move_y = row + moves_y[i];
        if (valid(move_y, move_x)) {
          ret[move_y][move_x] = true;
        }
      }
    }
  }
  vec = ret;
  floodfill(vec, depth - 1);
}

int main() {
  vector<vector<bool>> alive(5, vector<bool>(5, true));

  int n;
  cin >> n;

  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }

  n--;
  queue<int> curr_queue;
  int curr_val;
  int curr_time;
  int prev_time;
  cin >> curr_time >> curr_val;
  prev_time = curr_time;
  curr_queue.push(curr_val);

  while (n--) {
    cin >> curr_time >> curr_val;
    if (curr_time == prev_time) {
      curr_queue.push(curr_val);
    } else {
      while (!curr_queue.empty()) {
        kill(alive, curr_queue.front());
        curr_queue.pop();
      }
      floodfill(alive, curr_time - prev_time);
      if (!check(alive)) {
        cout << prev_time << endl;
        return 0;
      }
      curr_queue.push(curr_val);
    }
    prev_time = curr_time;
  }

  cout << curr_time + 1 << endl;

  return 0;
}
