#include <bits/stdc++.h>

using namespace std;

void print(vector<pair<long long, long long>> vec) {
  for (auto i : vec) {
    cout << "(" << i.first << ", " << i.second << ")\n";
  }
}
void print(vector<long long> vec) {
  for (auto i : vec) {
    cout << i << ' ';
  }
  cout << endl;
}

void print(vector<double> vec) {
  for (auto i : vec) {
    cout << i << ' ';
  }
  cout << endl;
}

int main() {
  long long W, L, n;
  cin >> W >> L >> n;
  long long num_elements = n + 1;

  vector<pair<long long, long long>> input;
  input.reserve(num_elements);
  input.push_back(pair(0, 0));
  vector<long long> pre_sum_weight(num_elements, -1);
  pre_sum_weight.at(0) = 0;

  while (n--) {
    long long weight, speed;
    cin >> weight >> speed;
    input.push_back(make_pair(weight, speed));
  }

  // print(input);
  //
  // pre_sum_weight.at(0) = input.at(0).first;
  // for (unsigned int i = 1; i < pre_sum_weight.size(); i++) {
  //   pre_sum_weight.at(i) = pre_sum_weight.at(i - 1) + input.at(i).first;
  // }
  //
  // print(pre_sum_weight);
  //
  // vector<long long> pre_sum_time(num_elements, -1);
  // pre_sum_time.at(0) = input.at(0).first;
  // for (unsigned int i = 1; i < pre_sum_time.size(); i++) {
  //   pre_sum_time.at(i) = pre_sum_time.at(i - 1) + input.at(i).first;
  // }
  //
  // print(pre_sum_time);
  vector<double> dp(num_elements, -1);
  vector<long long> weights(num_elements, -1);
  dp.at(0) = 0;
  weights.at(0) = W;

  for (unsigned int i = 1; i < input.size(); i++) {
    // cout << "i: " << i << endl;
    long long amt = W;

    // assume run i'th car by itself.
    long long min_speed = input.at(i).second;
    dp.at(i) = ((double)L / min_speed) * 60 + dp.at(i - 1);

    long long j = i;
    for (; j >= 0; j--) {
      if (j == 0)
        break;

      if (input.at(j).first > amt) {
        break;
      }
      amt -= input.at(j).first;
      min_speed = min(input.at(j).second, min_speed);
      double new_val = ((double)L / min_speed) * 60 + dp.at(j - 1);

      if (new_val < dp.at(i)) {
        dp.at(i) = new_val;
        weights.at(i) = amt;
      }
      // cout << "\tamt: " << amt << " j: " << j << endl;
    }
    // cout << "\tFrom " << j + 1 << " to " << i << endl;
  }
  // print(dp);
  cout << fixed << showpoint << setprecision(8) << dp.at(dp.size() - 1) << endl;

  return 0;
}
