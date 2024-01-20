#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;

    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;

    while (n--)
    {
        unsigned long long i;
        cin >> i;
        pq.push(i);
    }
    unsigned long long max = 0;

    unsigned long long curr_val;
    unsigned long long next_val;
    while (!pq.empty())
    {
        curr_val = pq.top();
        next_val = 0;
        pq.pop();

        if (!pq.empty())
        {
            next_val = pq.top();
            pq.pop();
        }
        else
        {
            cout << max << endl;
            break;
        }

        // cout << curr_val << ", " << next_val << endl;
        max += curr_val * 2;
        max += next_val * 2;
        pq.push(curr_val + next_val);
        // cout << max << endl;
    }

    return 0;
}