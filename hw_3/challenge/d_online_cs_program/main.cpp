#include <bits/stdc++.h>

using namespace std;

struct course {
  int id;
  int price;
  int rating;
  int parent;
  int value;
};

void print(course c) {
  cout << "Course " << c.id << ": price=" << c.price << ", rating=" << c.rating
       << ", parent=" << c.parent << ", value=" << c.value << endl;
}

int main() {
  int m, n;
  cin >> m >> n;

  vector<course> vec;
  vec.reserve(n);
  int price, rating, parent;
  int id = 0;

  while (n--) {
    cin >> price >> rating >> parent;
    vec.push_back({id, price, rating, parent - 1, price * rating});
    id++;
  }

  for (auto i : vec) {
    print(i);
  }

  return 0;
}
