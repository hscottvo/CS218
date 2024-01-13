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

int main()
{
    int weight, num_items, max_item, curr_weight, curr_val;
    cin >> weight >> num_items >> max_item;
    weight++;

    vector<int> weights;
    vector<int> values;
    vector<vector<int>> counts(weight, vector<int>(num_items, 0));
    vector<int> dp(weight, -1);
    weights.reserve(num_items);
    values.reserve(num_items);
    dp.at(0) = 0;

    while (num_items--)
    {
        cin >> curr_weight >> curr_val;
        weights.push_back(curr_weight);
        values.push_back(curr_val);
    }

    // print(weights);
    // print(values);
    // for (auto i : counts)
    // {
    //     print(i);
    // }
    // print(dp);

    for (int i = 1; (unsigned int)i < dp.size(); i++)
    {
        // cout << "Weight " << i << ":" << endl;
        int max_val = -1;
        int max_idx = -1;
        // int max_prev_idx = -1;
        int prev_count = -1;
        for (unsigned int j = 0; j < weights.size(); j++)
        {
            int move_weight = weights.at(j);
            int move_value = values.at(j);

            // invalid: too expensive
            if (i - move_weight < 0)
            {
                continue;
            }

            int prev_idx = i - move_weight;
            int prev_value = dp.at(prev_idx);

            // else
            // {
            //     cout << "\tCan use move (" << move_weight << ", " << move_value << ") at weight " << i << endl;
            // }
            if (counts.at(prev_idx).at(j) == max_item)
            {
                continue;
            }
            // else
            // {
            //     cout << "\tCan use move (" << move_weight << ", " << move_value << ") at count " << counts.at(prev_idx).at(j) << endl;
            // }

            int new_value = move_value + prev_value;
            // cout << "\tTrying move (" << move_weight << ", " << move_value;
            // cout << ") gives value " << prev_value << " + " << move_value;
            // cout << " = " << new_value << " from weight " << prev_idx;
            // cout << " with count " << counts.at(prev_idx).at(j);
            // cout << endl;
            if (new_value > max_val)
            {
                max_val = new_value;
                max_idx = j;
                // max_prev_idx = prev_idx;
                prev_count = counts.at(prev_idx).at(j);
            }
        }
        if (max_idx != -1)
        {
            dp.at(i) = max_val;
            for (unsigned int k = 0; k < counts.at(0).size(); k++)
            {
                counts.at(i).at(k) = counts.at(i - weights.at(max_idx)).at(k);
            }
            // cout << "\n\tBefore counts: ";
            // print(counts.at(i));
            counts.at(i).at(max_idx) = prev_count + 1;
            // cout << "\n\tAfter counts:";
            // print(counts.at(i));
            // cout << "\tUsing move (" << weights.at(max_idx) << ", " << values.at(max_idx);
            // cout << ") gives value " << dp.at(i - weights.at(max_idx)) << " + " << values.at(max_idx);
            // cout << " = " << dp.at(i) << " from weight " << i - weights.at(max_idx);
            // // cout << " with count " << counts.at(i - weights.at(max_idx)).at(max_idx);
            // cout << "\n\tCurrent counts: ";
            // print(counts.at(i));
            // cout << "\n\tPrevious counts: ";
            // print(counts.at(i - weights.at(max_idx)));
            // cout << endl;
        }
        else
        {
            dp.at(i) = 0;
        }
    }

    // cout << "weights: \t";
    // print(weights);
    // cout << "values: \t";
    // print(values);
    // // for (auto i : counts)
    // for (unsigned int i = 0; i < counts.size(); i++)
    // {
    //     cout << i << ":\t";
    //     print(counts.at(i));
    // }
    // cout << endl;

    // cout << "max items: " << max_item << endl;

    // print(dp);
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}