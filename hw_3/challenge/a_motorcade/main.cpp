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

  print(input);

  pre_sum_weight.at(0) = input.at(0).first;
  for (unsigned int i = 1; i < pre_sum_weight.size(); i++) {
    pre_sum_weight.at(i) = pre_sum_weight.at(i - 1) + input.at(i).first;
  }

  print(pre_sum_weight);

  vector<long long> pre_sum_time(num_elements, -1);
  pre_sum_time.at(0) = input.at(0).first;
  for (unsigned int i = 1; i < pre_sum_time.size(); i++) {
    pre_sum_time.at(i) = pre_sum_time.at(i - 1) + input.at(i).first;
  }

  print(pre_sum_time);

  for (unsigned int i = 1; i < pre_sum_weight.size(); i++) {
    long long sum = input.at(i).first;
    long long j = i - 1;
    for (; j >= 0; j--) {
      cout << "isrentreint" << endl;
    }
  }

  return 0;
}
