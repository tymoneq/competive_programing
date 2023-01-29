#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1510;
int Cost[M][M];
char Grid[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    vector<int> Cols(n + 1);
    vector<int> Rows(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> Grid[i][j];
        cin >> Cols[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> Rows[i];
    long long res = 0;
    for (int i = 1; i <= n; i++)
        Cost[i][n + 1] = Cols[i];
    for (int i = 1; i <= n; i++)
        Cost[n + 1][i] = Rows[i];
    for (int i = n; i > 0; i--)
        for (int j = n; j > 0; j--)
        {
            if (Grid[i][j] == 'R')
                Cost[i][j] = Cost[i][j + 1];
            if (Grid[i][j] == 'D')
                Cost[i][j] = Cost[i + 1][j];
            res += Cost[i][j];
        }
    cout << res << "\n";
    cin >> q;
    int row, col;
    pair<int, int> prev;
    vector<long long> R;
    R.push_back(res);
    for (int k = 0; k < q; k++)
    {
        cin >> row >> col;
        if (row == prev.first && prev.second == col)
        {
            cout << R[k - 1] << "\n";
            continue;
        }
        res -= Cost[row][col];
        if (Grid[row][col] == 'R')
        {
            Grid[row][col] = 'D';
            Cost[row][col] = Cost[row + 1][col];
        }
        else
        {
            Grid[row][col] = 'R';
            Cost[row][col] = Cost[row][col + 1];
        }
        queue<pair<int, int>> Q;

        if (Grid[row][col - 1] == 'R')
            Q.push({row, col - 1});

        if (Grid[row - 1][col] == 'D')
            Q.push({row - 1, col});
        res += Cost[row][col];

        while (!Q.empty())
        {
            auto v = Q.front();
            Q.pop();
            res -= Cost[v.first][v.second];
            if (Grid[v.first][v.second] == 'R')
                Cost[v.first][v.second] = Cost[v.first][v.second + 1];
            else
                Cost[v.first][v.second] = Cost[v.first + 1][v.second];
            res += Cost[v.first][v.second];
            if (Grid[v.first - 1][v.second] == 'D' && v.first - 1 > 0)
                Q.push({v.first - 1, v.second});
            if (Grid[v.first][v.second - 1] == 'R' && v.second - 1 > 0)
                Q.push({v.first, v.second - 1});
        }
        R.push_back(res);
        prev.first = row, prev.second = col;
        cout << res << "\n";
    }
    return 0;
}