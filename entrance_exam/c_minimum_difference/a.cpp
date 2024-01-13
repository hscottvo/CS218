#include <bits/stdc++.h>

using namespace std;

void print(vector<int> vec)
{
    for (auto i : vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> read_vec(int n)
{
    vector<int> ret;
    ret.reserve(n);
    while (n--)
    {
        int val;
        cin >> val;
        ret.push_back(val);
    }
    return ret;
}

vector<int> deltas_vec(vector<int> values)
{
    vector<int> ret;
    ret.reserve(values.size() - 1);
    for (unsigned int i = 0; i < values.size() - 1; i++)
    {
        ret.push_back(values.at(i + 1) - values.at(i));
    }
    // cout << "deltas: " << endl
    //      << '\t';
    // print(ret);
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> vec = read_vec(n);
    if (vec.size() == 2)
    {
        cout << vec.at(1) - vec.at(0) << endl;
        return;
    }
    // cout << "vec: ";
    // print(vec);
    vector<int> deltas = deltas_vec(vec);
    int middle_idx = deltas.size() / 2;
    int curr_delta = deltas.at(middle_idx);
    int min_delta = curr_delta;
    int min_idx = middle_idx;

    for (int dist_from_mid = 1; middle_idx - dist_from_mid >= 0; dist_from_mid++)
    {
        int left_idx = middle_idx - dist_from_mid;
        int right_idx = middle_idx + dist_from_mid;
        if (vec.at(left_idx) > 0 && deltas.at(left_idx) < min_delta)
        {
            min_idx = left_idx;
            min_delta = deltas.at(left_idx);
        }
        if (deltas.at(right_idx) < min_delta)
        {
            min_idx = right_idx;
            min_delta = deltas.at(right_idx);
        }
    }
    // cout << "delta: " << min_delta << " idx: " << min_idx << endl;

    int big = vec.at(min_idx + 1);
    int small = vec.at(min_idx);
    // cout << "big: " << big << " small: " << small << endl;
    vec.erase(vec.begin() + min_idx, vec.begin() + min_idx + 2);

    queue<int> left_q;
    queue<int> right_q;

    for (unsigned int i = 0; i < vec.size() / 2; i++)
    {
        left_q.push(vec.at(i));
    }
    for (unsigned int i = vec.size() - 1; i >= vec.size() / 2; i--)
    {
        right_q.push(vec.at(i));
    }
    while (!left_q.empty())
    {
        big *= 10;
        big += left_q.front();
        // cout << left_q.front() << ' ';
        left_q.pop();
    }
    // cout << endl;

    while (!right_q.empty())
    {
        small *= 10;
        small += right_q.front();
        // cout << right_q.front() << ' ';
        right_q.pop();
    }
    // cout << endl;

    // choose 1st digit somehow for each
    // put smallest val on big and biggest val on small for rest?
    // cout << "big: " << big << " small: " << small << endl;
    cout << big - small << endl;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        solve();
    }

    return 0;
}

// 203 198
// 920 831
// 0 1 2 3 8 9
// 301 298

// 2 3 4 6 8 9
// 426 398
// why doesn't:
// 3__ 2__
// work?

// 0 4 5 7 8 9
// 507 498

// 0 1 2 3 5 6 7 9
// why doens't:
// 2___ 1___
// work?
// 3015 2976
// 39

// 0 1 2 3 5 6 7 9
// 3015 2976
// 139
// 6012 5973

// 0 1 3 5 6 7
// 601 573 = 28
// 701 653 = 48

// 1 2 5 6 7 8

// 1 2 5 7 8 9
// 2
