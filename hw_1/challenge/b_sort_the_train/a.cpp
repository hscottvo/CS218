#include <bits/stdc++.h>

using namespace std;
unsigned long long num_swaps = 0;
void print(vector<unsigned long long> vec)
{
    for (auto i : vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void sort(vector<unsigned long long> &vec, int start, int end)
{
    // cout << "start: " << start << " end: " << end << endl;
    // cout << "end - start: " << end - start << endl;
    // cout << "Sorting: ";
    // for (int i = start; i < end; i++)
    // {
    //     cout << vec.at(i) << ' ';
    // }
    // cout << endl;
    if (end - start == 1)
    {
        return;
    }
    else if (end - start == 2)
    {
        if (vec.at(start) > vec.at(start + 1))
        {
            swap(vec.at(start), vec.at(start + 1));
            num_swaps++;
        }
        return;
    }

    int l_start = start;
    int l_end = (end + start) / 2;
    int r_start = l_end;
    int r_end = end;

    sort(vec, l_start, l_end);
    sort(vec, r_start, r_end);

    vector<unsigned long long> ret;
    ret.reserve(end - start);

    int l_index = l_start;
    int r_index = r_start;

    while (true)
    {
        if (l_index < r_start && r_index < end)
        {
            // merge things
            if (vec.at(l_index) <= vec.at(r_index))
            {
                // no swap
                ret.push_back(vec.at(l_index));
                l_index++;
            }
            else
            {
                // left bigger than right
                ret.push_back(vec.at(r_index));
                num_swaps += r_start - l_index;
                r_index++;
            }
        }
        else if (l_index >= r_start && r_index < end)
        {
            // keep adding r_index
            // no swap
            ret.push_back(vec.at(r_index));
            r_index++;
        }
        else if (r_index >= end && l_index < r_start)
        {
            // keep adding l_index
            ret.push_back(vec.at(l_index));
            l_index++;
        }
        else
        {
            // exit?
            break;
        }
    }

    // cout << "Sorting: ";
    // for (int i = start; i < end; i++)
    // {
    //     cout << vec.at(i) << ' ';
    // }
    for (unsigned long long i = 0; i < ret.size(); i++)
    {
        vec.at(start + i) = ret.at(i);
    }
    // cout << "Turns into ";
    // for (int i = start; i < end; i++)
    // {
    //     cout << vec.at(i) << ' ';
    // }
    // cout << endl;
    // // print(ret);
    // print(vec);
}

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
    // unsigned int num_swaps = 0;
    sort(vec, 0, vec.size());

    // print(vec);
    // cout << "num_swaps: " << num_swaps << endl;
    cout << num_swaps << endl;
    return 0;
}