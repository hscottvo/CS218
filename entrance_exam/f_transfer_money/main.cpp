#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n_nodes, n_edges;
    int a, b, weight;
    int start, end;

    cin >> n_nodes >> n_edges;

    vector<double> dists(n_nodes, DBL_MAX);
    vector<bool> visited(n_nodes, false);

    vector<map<int, double>> edges(n_nodes);

    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b >> weight;
        a--;
        b--;
        edges.at(a).insert(make_pair(b, 1 - weight / 100.0));
        edges.at(b).insert(make_pair(a, 1 - weight / 100.0));
    }

    cin >> start >> end;
    start--;
    end--;

    dists.at(start) = 0;
    visited.at(start) = true;

    // djikstra's with multiplying edges instead of adding
    // prio queue with sort key being the so far dist, and val being the node num (prob have to use pair)
    // skip if visited already
    // priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
    for (auto i : edges.at(start))
    {
        pq.push(make_pair(i.second, i.first));
    }

    while (!pq.empty())
    {
        auto curr_node = pq.top();
        int node_num = curr_node.second;
        double weight = curr_node.first;

        pq.pop();

        if (visited.at(node_num))
        {
            continue;
        }

        visited.at(node_num) = true;
        dists.at(node_num) = weight;

        for (auto i : edges.at(node_num))
        {
            pq.push(make_pair(i.second * weight, i.first));
        }
        if (node_num == end)
        {
            // took how to print with precision from https://stackoverflow.com/questions/22515592/how-to-use-setprecision-in-c
            cout << fixed << showpoint << setprecision(7) << 100.0 / weight << endl;
            return 0;
        }
    }

    return 0;
}