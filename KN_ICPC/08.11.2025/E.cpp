#include <bits/stdc++.h>

using namespace std;
int n, m, k;
// car fitrst koniec second kolumna

inline void dfs(pair<int, int> car, set<pair<int, int>> &Vis, vector<vector<int>> &Grid, vector<vector<int>> &Prefsum, int &ans)
{
    // przejście w dół
    if (car.first + 1 <= n && !Vis.count({car.first + 1, car.second}) && Grid[car.first + 1][car.second] == 0)
    {
        Vis.insert({car.first + 1, car.second});
        ans = max(ans, car.first + 1);
        dfs({car.first + 1, car.second}, Vis, Grid, Prefsum, ans);
    }

    // przejście w lewo
    if (car.second > 1 && Prefsum[car.first][car.second - 1] - Prefsum[car.first - k][car.second - 1] == 0 && !Vis.count({car.first, car.second - 1}))
    {
        Vis.insert({car.first, car.second - 1});
        ans = max(ans, car.first);
        dfs({car.first, car.second - 1}, Vis, Grid, Prefsum, ans);
    }

    // przejście w prawo
    if (car.second < m && Prefsum[car.first][car.second + 1] - Prefsum[car.first - k][car.second + 1] == 0 && !Vis.count({car.first, car.second + 1}))
    {
        Vis.insert({car.first, car.second + 1});
        ans = max(ans, car.first);
        dfs({car.first, car.second + 1}, Vis, Grid, Prefsum, ans);
    }
}

void solve()
{

    cin >> n >> m >> k;
    vector<vector<int>> Grid(n + 5, vector<int>(m + 5));
    vector<vector<int>> PrefSum(n + 5, vector<int>(m + 5));
    pair<int, int> car = {1 + k - 1, 1};

    set<pair<int, int>> Vis;
    int ans = 1 + k - 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            if (a == '.')
                Grid[i][j] = 0;
            if (a == 'x')
                Grid[i][j] = 1;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            PrefSum[i][j] = PrefSum[i - 1][j] + Grid[i][j];

    dfs(car, Vis, Grid, PrefSum, ans);
    cout << ans << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
