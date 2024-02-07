#include <bits/stdc++.h>

using namespace std;

void flood_fill(vector<vector<bool>> &alive, int depth) {
  if (depth <= 0) {
    return;
  }
  vector<vector<bool>> ret(5, vector<bool>(5, false));
  int moves_x[] = {-1, 0, 1, 0};
  int moves_y[] = {0, -1, 0, 1};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (alive.at(i).at(j)) {
        ret.at(i).at(j) = true;
        for (int k = 0; k < 4; k++) {
          auto move_x = j + moves_x[k];
          auto move_y = i + moves_y[k];
          if (move_y < 0 || move_y >= 5 || move_x < 0 || move_x >= 5) {
            continue;
          }
          ret.at(move_y).at(move_x) = true;
        }
      }
    }
  }
  alive = ret;
  flood_fill(alive, depth - 1);
}

// returns true if any are alive
bool check_vector(vector<vector<bool>> alive) {
  bool ret = false;

  for (auto i : alive) {
    for (auto j : i) {
      ret = ret || j;
    }
  }
  return ret;
}

int solve(vector<vector<bool>> *alive, int value) {
  int ret = 0;
  if (value >= 5) {
    // do the cols
    value -= 5;
    for (int i = 0; i < 5; i++) {
      if (alive->at(i).at(value)) {
        ret++;
        alive->at(i).at(value) = false;
      }
    }
  } else {
    // do the rows
    for (int i = 0; i < 5; i++) {
      if (alive->at(value).at(i)) {
        ret++;
        alive->at(value).at(i) = false;
      }
    }
  }

  return ret;
  // return 0;
}

int main() {

  int n;
  cin >> n;

  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }

  vector<vector<bool>> alive(5, vector<bool>(5, true));

  queue<pair<int, queue<int>>> time_queues;
  queue<int> val_queue;

  int t, val, prev_t;
  cin >> t >> val;
  val--;
  val_queue.push(val);
  prev_t = t;
  for (int i = 1; i < n; i++) {
    cin >> t >> val;
    val--;

    if (t != prev_t) {
      time_queues.push(make_pair(prev_t, val_queue));
      val_queue = queue<int>();
      val_queue.push(val);
    } else {
      val_queue.push(val);
      if (i == n - 1)
        time_queues.push(make_pair(t, val_queue));
    }

    prev_t = t;
  }

  // queue has been read in now, now to do the calculations

  int curr_time = 0;
  while (!time_queues.empty()) {
    auto i = time_queues.front().second;
    curr_time = time_queues.front().first;
    time_queues.pop();
    while (!i.empty()) {
      int value = i.front();
      i.pop();
      solve(&alive, value);
    }
    if (check_vector(alive)) {
      if (!time_queues.empty()) {
        int next_time = time_queues.front().first;
        flood_fill(alive, next_time - curr_time);
      } else {
        // curr_time += 2;
        break;
      }
    } else {
      // curr_time++;
      if (time_queues.empty()) {
        curr_time = time_queues.front().first;
        break;
      }
    }
  }
  if (check_vector(alive)) {
    // curr_time += 2;
    curr_time++;
  }
  cout << curr_time << endl;

  // vector<vector<bool>> test(5, vector<bool>(5, false));
  //
  // test[2][2] = true;
  // flood_fill(test, 1);
  //
  // for (auto i : test) {
  //   for (auto j : i) {
  //     cout << j << ' ';
  //   }
  //   cout << endl;
  // }

  return 0;
}
