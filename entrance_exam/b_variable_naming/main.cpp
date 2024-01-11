#include <bits/stdc++.h>

using namespace std;
void print_vec(vector<int> vec)
{
    for (auto i : vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    unsigned int n;
    vector<int> vec;

    cin >> n;

    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int val;
        cin >> val;
        vec.push_back(val);
    }

    map<int, int> hash;
    map<int, int>::iterator it;
    map<int, int>::iterator find_i;
    int val;

    for (int i : vec)
    {
        val = i;
        find_i = hash.find(i);
        it = find_i;

        // exists, has count in it already
        while (it != hash.end())
        {
            find_i->second++;
            val = i * find_i->second;
            it = hash.find(val);
        }
        // dne yet
        hash.insert(make_pair(val, 1));
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}