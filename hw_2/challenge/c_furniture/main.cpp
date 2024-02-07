#include <bits/stdc++.h>

using namespace std;

struct comp {
  constexpr bool operator()(pair<int, int> const &a,
                            pair<int, int> const &b) const noexcept {
    // if (a.first != b.first) {
    //   return a.first > b.first;
    // }
    return a.second - a.first < b.second - b.first;
  }
};

int main() {
  int L;
  cin >> L;
  vector<priority_queue<pair<int, int>, vector<pair<int, int>>, comp>> vec(L);

  int n, k;
  cin >> n >> k;
  int count = 0;

  int a, b, c, d;
  int top, bot;
  while (n--) {
    cin >> a >> b >> c >> d;
    a -= 1;
    c -= 1;
    top = min(a, c);
    bot = max(a, c);
    auto my_pair = make_pair(top, bot);

    for (int i = top; i <= bot; i++) {
      vec.at(i).push(my_pair);
    }
  }

  for (auto i : vec) {
    // cout << "BEFORE: " << endl;
    // while (!i.empty()) {
    //   auto my_pair = i.top();
    //   i.pop();

    // cout << "\t(" << my_pair.first << ", " << my_pair.second << ")" <<
    // endl;
    while (i.size() > (unsigned int)k) {
      auto top_pair = i.top();
      // cout << "Top: " << top_pair.first << ',' << top_pair.second << endl;
      i.pop();
      count++;
      for (int j = top_pair.first; j <= top_pair.second; j++) {
        auto my_pq = vec.at(j);
        if (my_pq.top().first == top_pair.first &&
            my_pq.top().second == top_pair.second) {
          // cout << "popping" << top_pair.first << ',' << top_pair.second
          //      << " at " << j << endl;
          vec.at(j).pop();
        }
      }
    }
  }
  // }
  cout << count << endl;

  return 0;
}
