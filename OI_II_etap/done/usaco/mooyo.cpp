#include <bits/stdc++.h>

using namespace std;
constexpr int M = 100;
int Grid[M][10];
bool Vis[M][10];
int main()
{
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    char z;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
        {
            cin >> z;
            Grid[i][j] = z - '0';
        }

    // flood fill next gravity
    bool runing = 1, gravity;
    int countt;
    queue<pair<int, int>> q;
    while (runing)
    {
        gravity = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 10; j++)
                if (Grid[i][j] != 0)
                {
                    q.push({i, j});
                    countt = 1;
                    Vis[i][j] = 1;
                    while (!q.empty())
                    {
                        pair<int, int> v = q.front();
                        q.pop();
                        if (v.first > 0 && !Vis[v.first - 1][v.second] && Grid[v.first - 1][v.second] == Grid[i][j])
                        {
                            countt++;
                            Vis[v.first - 1][v.second] = 1;
                            q.push({v.first - 1, v.second});
                        }
                        if (v.first < n - 1 && !Vis[v.first + 1][v.second] && Grid[v.first + 1][v.second] == Grid[i][j])
                        {
                            countt++;
                            Vis[v.first + 1][v.second] = 1;
                            q.push({v.first + 1, v.second});
                        }
                        if (v.second > 0 && !Vis[v.first][v.second - 1] && Grid[v.first][v.second - 1] == Grid[i][j])
                        {
                            countt++;
                            Vis[v.first][v.second - 1] = 1;
                            q.push({v.first, v.second - 1});
                        }
                        if (v.second < 9 && !Vis[v.first][v.second + 1] && Grid[v.first][v.second + 1] == Grid[i][j])
                        {
                            countt++;
                            Vis[v.first][v.second + 1] = 1;
                            q.push({v.first, v.second + 1});
                        }
                    }
                    for (int r = 0; r < n; r++)
                        for (int c = 0; c < 10; c++)
                            Vis[r][c] = 0;
                    if (countt >= k)
                    {
                        q.push({i, j});
                        Vis[i][j] = 1;
                        while (!q.empty())
                        {
                            pair<int, int> v = q.front();
                            q.pop();
                            if (v.first > 0 && !Vis[v.first - 1][v.second] && Grid[v.first - 1][v.second] == Grid[i][j])
                            {
                                Grid[v.first - 1][v.second] = 0;
                                q.push({v.first - 1, v.second});
                            }
                            if (v.first < n - 1 && !Vis[v.first + 1][v.second] && Grid[v.first + 1][v.second] == Grid[i][j])
                            {

                                Grid[v.first + 1][v.second] = 0;
                                q.push({v.first + 1, v.second});
                            }
                            if (v.second > 0 && !Vis[v.first][v.second - 1] && Grid[v.first][v.second - 1] == Grid[i][j])
                            {

                                Grid[v.first][v.second - 1] = 0;
                                q.push({v.first, v.second - 1});
                            }
                            if (v.second < 9 && !Vis[v.first][v.second + 1] && Grid[v.first][v.second + 1] == Grid[i][j])
                            {

                                Grid[v.first][v.second + 1] = 0;
                                q.push({v.first, v.second + 1});
                            }
                        }
                        Grid[i][j] = 0;
                    }
                }
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < 10; j++)
                if (Grid[i][j] != 0)
                {
                    int ind = i + 1;
                    while (ind < n && Grid[ind][j] == 0)
                    {
                        gravity = 1;
                        swap(Grid[ind - 1][j], Grid[ind][j]);
                        ind++;
                    }
                }
        if (!gravity)
            runing = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << Grid[i][j];
        cout << "\n";
    }

    return 0;
}