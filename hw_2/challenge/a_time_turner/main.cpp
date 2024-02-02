#include <bits/stdc++.h>

using namespace std;

struct comp_end {
  constexpr bool operator()(pair<int, int> const &a,
                            pair<int, int> const &b) const noexcept {
    if (a.first != b.first) {
      return a.first < b.first;
    } else {
      return a.second < b.second;
    }
  }
};

int main() {
  int n;
  cin >> n;

  priority_queue<pair<int, int>, vector<pair<int, int>>, comp_end> pq;

  int left, right;
  while (n--) {
    cin >> left >> right;
    pq.push(make_pair(left, right));
  }

  // beginning point of first class in each schedule so far
  int top_sched = INT_MAX;
  int bot_sched = INT_MAX;

  // how many classes have been scheduled
  int class_count = 0;

  while (!pq.empty()) {
    pair<int, int> item = pq.top();
    int start_time = item.first;
    int end_time = item.second;
    // cout << "Looking at " << item.first << ", " << item.second << endl;
    pq.pop();

    int *sched_ptr;

    // if both work, take the one with the closer bound
    if (end_time < top_sched && end_time < bot_sched) {
      // cout << "\tend time: " << end_time << ", top_sched: " << top_sched
      //      << ", bot_sched: " << bot_sched << endl;
      // cout << '\t' << (end_time < bot_sched) << endl;
      if (top_sched < bot_sched) {
        sched_ptr = &top_sched;
      } else {
        sched_ptr = &bot_sched;
      }
    } else if (end_time >= top_sched && end_time >= bot_sched) {
      continue;
    } else {
      if (end_time >= top_sched) {
        sched_ptr = &bot_sched;
      } else if (end_time >= bot_sched) {
        sched_ptr = &top_sched;
      }
    }
    // if (sched_ptr == &bot_sched) {
    //   cout << "\tAdding to bot schedule value " << bot_sched << endl;
    // } else {
    //   cout << "\tAdding to top schedule value " << top_sched << endl;
    // }

    *sched_ptr = start_time;
    class_count++;
  }

  // cout << "count: " << class_count << endl;
  cout << class_count << endl;

  return 0;
}
