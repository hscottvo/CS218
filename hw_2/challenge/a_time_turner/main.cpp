#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct comp_end {
  constexpr bool operator()(pair<int, int> const &a,
                            pair<int, int> const &b) const noexcept {
    // return a.second < b.second;
    if (a.first != b.first) {
      return a.first < b.first;
    } else {
      return a.second > b.second;
    }
    // return a.first < b.first;
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

    if (top_sched < bot_sched) {
      sched_ptr = &bot_sched;
    } else {
      sched_ptr = &top_sched;
    }
    if (sched_ptr == &bot_sched) {
      // cout << "\tAdding to bot schedule value " << bot_sched << endl;
    } else {
      // cout << "\tAdding to top schedule value " << top_sched << endl;
    }

    if (end_time < *sched_ptr) {
      // cout << "\tCan add to value: " << *sched_ptr << endl;
      *sched_ptr = start_time;
      // cout << "\tNew value: " << *sched_ptr << endl;
      class_count++;
    } else {
      // cout << "\tCan't add" << endl;
    }
  }

  // cout << "count: " << class_count << endl;
  cout << class_count << endl;

  return 0;
}
