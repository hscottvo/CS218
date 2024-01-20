#include <bits/stdc++.h>

using namespace std;

double a;
double calc(double x)
{
    return x * x * (1.0 / log(x)) + a * x;
}

pair<double, double> idx(double left, double right)
{
    double left_idx = left + (right - left) * (1 / 3.);
    double right_idx = left + (right - left) * (2 / 3.);
    return make_pair(left_idx, right_idx);
}

int main()
{
    cin >> a;
    // cout << setprecision(11) << calc(1.4372) << endl;
    double x[4];
    double y[4];
    x[0] = 1;
    x[3] = 2;

    x[1] = idx(x[0], x[3]).first;
    x[2] = idx(x[0], x[3]).second;

    // double prev_val = calc(1);
    // double max_val = DBL_MIN;
    // double max_idx = -1;

    pair<double, double> idx_pair;

    while (true)
    {
        if (x[2] - x[1] < 0.0000001)
        {
            cout << setprecision(11) << calc(x[2]) << endl;
            return 0;
        }
        // max_val = DBL_MIN;

        idx_pair = idx(x[0], x[3]);
        x[1] = idx_pair.first;
        x[2] = idx_pair.second;

        y[0] = calc(x[0]);
        y[1] = calc(x[1]);
        y[2] = calc(x[2]);
        y[3] = calc(x[3]);

        if (y[1] > y[2])
        {
            x[0] = x[1];
        }
        else
        {
            x[3] = x[2];
        }
    }

    return 0;
}