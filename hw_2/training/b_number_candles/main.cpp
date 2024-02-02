#include <bits/stdc++.h>

using namespace std;
template <typename T>
void print(vector<T> vec)
{
    for (T i : vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

bool my_greater(string a, string b)
{
    if (a.size() > b.size())
    {
        return true;
    }
    if (a.size() < b.size())
    {
        return false;
    }

    for (long i = a.size() - 1; i >= 0; i--)
    {
        if (a.at(i) > b.at(i))
        {
            return true;
        }
        if (a.at(i) < b.at(i))
        {
            return false;
        }
    }

    return false;
}

int main()
{
    int m;
    cin >> m;

    vector<int> costs(9);
    for (int i = 0; i < 9; i++)
    {
        int val;
        cin >> val;
        costs.at(i) = val;
    }

    // print(costs);
    vector<string> dp(m + 1, "0");

    string max;

    for (unsigned int i = 1; i < dp.size(); i++)
    {
        max = dp.at(i);
        for (unsigned int j = 0; j < costs.size(); j++)
        {
            int curr_cost = costs.at(j);
            string candidate_max = "0";
            if (i >= (unsigned int)curr_cost)
            {
                candidate_max = dp.at(i - curr_cost) + to_string(j + 1);
            }

            if (my_greater(candidate_max, max))
            {
                max = candidate_max;
            }
        }
        dp.at(i) = max;
    }

    string out = "0";
    for (string i : dp)
    {
        if (my_greater(i, out))
        {
            out = i;
        }
    }
    for (int i = (int)out.size() - 1; i >= 1; i--)
    {
        cout << out.at(i);
    }

    cout << endl;

    return 0;
}
