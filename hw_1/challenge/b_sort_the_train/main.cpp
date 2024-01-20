#include <bits/stdc++.h>

using namespace std;

void print(vector<unsigned long long> vec)
{
    for (auto i : vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

// probably bubble sort
int main()
{
    int n;
    cin >> n;

    vector<unsigned long long> vec;
    vec.reserve(n);

    unsigned long long val;
    while (n--)
    {
        cin >> val;
        vec.push_back(val);
    }
    unsigned int num_swaps = 0;
    print(vec);

    for (unsigned int i = 0; i < vec.size() - 1; i++)
    {
        for (unsigned int j = 0; j < vec.size() - 1; j++)
        {
            if (vec.at(j) <= vec.at(j + 1))
            {
                continue;
            }
            else
            {
                // cout << "i: " << i << " j: " << j << endl;
                swap(vec.at(j), vec.at(j + 1));
                num_swaps++;
                print(vec);
            }
        }
    }

    cout << num_swaps << endl;

    return 0;
}