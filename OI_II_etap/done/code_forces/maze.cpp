#include <bits/stdc++.h>

using namespace std;
const int MAX_VAL = 505;

char MAZE[MAX_VAL][MAX_VAL];
bool Visited[MAX_VAL][MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, s = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> MAZE[i][j];

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (MAZE[i][j] == '.')
            {
                s++;
                if (q.empty())
                {
                    q.push(make_pair(i, j));
                    Visited[i][j] = 1;
                }
            }
        }

    int counter = 0;
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        if (MAZE[v.first + 1][v.second] == '.' && !Visited[v.first + 1][v.second])
        {
            counter += 1;
            q.push(make_pair(v.first + 1, v.second));
            Visited[v.first + 1][v.second] = 1;
            if (counter >= s - k)
                MAZE[v.first + 1][v.second] = 'X';
        }
        if (MAZE[v.first - 1][v.second] == '.' && !Visited[v.first - 1][v.second])
        {
            counter += 1;
            q.push(make_pair(v.first - 1, v.second));
            Visited[v.first - 1][v.second] = 1;
            if (counter >= s - k)
                MAZE[v.first - 1][v.second] = 'X';
        }
        if (MAZE[v.first][v.second + 1] == '.' && !Visited[v.first][v.second + 1])
        {
            counter += 1;
            q.push(make_pair(v.first, v.second + 1));
            Visited[v.first][v.second + 1] = 1;
            if (counter >= s - k)
                MAZE[v.first][v.second + 1] = 'X';
        }
        if (MAZE[v.first][v.second - 1] == '.' && !Visited[v.first][v.second - 1])
        {
            counter += 1;
            q.push(make_pair(v.first, v.second - 1));
            Visited[v.first][v.second - 1] = 1;
            if (counter >= s - k)
                MAZE[v.first][v.second - 1] = 'X';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << MAZE[i][j];
        cout << "\n";
    }
    return 0;
}