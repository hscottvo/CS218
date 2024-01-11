#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print_board(vector<vector<int>> &board)
{
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

pair<int, int> read_pair()
{
    string str;
    cin >> str;
    int col = str.at(0) - 'a';
    int row = (int)str.at(1) - '0' - 1;
    return pair(row, col);
}

bool in_bounds(pair<int, int> in)
{
    int a = in.first;
    int b = in.second;

    if (a < 0 || b < 0 || a > 7 || b > 7)
    {
        return false;
    }
    return true;
}
bool is_valid(pair<int, int> coord, vector<vector<int>> &board)
{
    if (!in_bounds(coord))
        return false;

    int a = coord.first;
    int b = coord.second;

    return board.at(a).at(b) != -1;
}

void solve_path(pair<int, int> start, pair<int, int> end, int num_moves, vector<vector<int>> &board)
{
    int row = start.first;
    int col = start.second;
    int curr_num_moves = board.at(row).at(col);

    // if better path already was here
    if (curr_num_moves <= num_moves && curr_num_moves != -2)
        return;
    else
    {
        board.at(row).at(col) = num_moves;
    }

    // if else

    // recursive call
    pair<int, int> a = make_pair(row - 1, col - 2);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row - 2, col - 1);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row + 1, col + 2);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row + 2, col + 1);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row - 1, col + 2);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row - 2, col + 1);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row + 1, col - 2);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);

    a = make_pair(row + 2, col - 1);
    if (is_valid(a, board))
        solve_path(a, end, num_moves + 1, board);
}

void solve(unsigned int n, int board_num)
{
    vector<vector<int>> board(8, vector<int>(8, -2));
    for (unsigned int i = 0; i < n; i++)
    {
        pair<int, int> blocked = read_pair();
        board.at(blocked.first).at(blocked.second) = -1;
    }

    pair<int, int> start_coords = read_pair();
    pair<int, int> end_coords = read_pair();
    int row = start_coords.first;
    int col = start_coords.second;
    board.at(row).at(col) = 0;

    pair<int, int>
        a = make_pair(row - 1, col - 2);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row - 2, col - 1);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row + 1, col + 2);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row + 2, col + 1);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row - 1, col + 2);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row - 2, col + 1);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row + 1, col - 2);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    a = make_pair(row + 2, col - 1);
    if (is_valid(a, board))
        solve_path(a, end_coords, 1, board);

    // cout << "done" << endl;
    // print_board(board);

    int final = board.at(end_coords.first).at(end_coords.second);
    if (final == -2)
    {
        cout << "Board " << board_num << ": not reachable" << endl;
    }
    else
    {
        cout << "Board " << board_num << ": " << board.at(end_coords.first).at(end_coords.second) << " moves" << endl;
    }
    // cout << board.at(end_coords.first).at(end_coords.second) << endl;
}

int main()
{
    int n;
    int board_num = 1;
    cin >> n;

    while (n != -1)
    {
        solve(n, board_num);
        board_num++;

        cin >> n;
    }

    return 0;
}