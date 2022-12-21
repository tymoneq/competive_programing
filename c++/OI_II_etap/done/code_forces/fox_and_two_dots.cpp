#include <bits/stdc++.h>

using namespace std;
const int MAX_VAl = 55;
char Board[MAX_VAl][MAX_VAl];
bool Visited[MAX_VAl][MAX_VAl];
struct dfs
{
    int parent_x = 0;
    int parent_y = 0;
    int x = 0;
    int y = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    dfs tmp, new_cords;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> Board[i][j];

    stack<dfs> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (Visited[i][j] == 1)
                continue;
            tmp.x = i;
            tmp.y = j;
            q.push(tmp);
            Visited[i][j] = 1;
            while (!q.empty())
            {
                auto v = q.top();
                q.pop();
                if (Board[v.x + 1][v.y] == Board[i][j] && Visited[v.x + 1][v.y] && v.x + 1 != v.parent_x)
                {
                    cout << "Yes";
                    return 0;
                }
                if (Board[v.x - 1][v.y] == Board[i][j] && Visited[v.x - 1][v.y] && v.x - 1 != v.parent_x)
                {
                    cout << "Yes";
                    return 0;
                }
                if (Board[v.x][v.y + 1] == Board[i][j] && Visited[v.x][v.y + 1] && v.y + 1 != v.parent_y)
                {
                    cout << "Yes";
                    return 0;
                }
                if (Board[v.x][v.y - 1] == Board[i][j] && Visited[v.x][v.y - 1] && v.y - 1 != v.parent_y)
                {
                    cout << "Yes";
                    return 0;
                }

                if (Board[v.x + 1][v.y] == Board[i][j] && !Visited[v.x + 1][v.y])
                {
                    new_cords.parent_x = v.x;
                    new_cords.parent_y = v.y;
                    new_cords.x = v.x + 1;
                    new_cords.y = v.y;
                    q.push(new_cords);
                    Visited[v.x + 1][v.y] = 1;
                }
                if (Board[v.x - 1][v.y] == Board[i][j] && !Visited[v.x - 1][v.y])
                {
                    new_cords.parent_x = v.x;
                    new_cords.parent_y = v.y;
                    new_cords.x = v.x - 1;
                    new_cords.y = v.y;
                    q.push(new_cords);
                    Visited[v.x - 1][v.y] = 1;
                }
                if (Board[v.x][v.y + 1] == Board[i][j] && !Visited[v.x][v.y + 1])
                {
                    new_cords.parent_x = v.x;
                    new_cords.parent_y = v.y;
                    new_cords.x = v.x;
                    new_cords.y = v.y + 1;
                    q.push(new_cords);
                    Visited[v.x][v.y + 1] = 1;
                }
                if (Board[v.x][v.y - 1] == Board[i][j] && !Visited[v.x][v.y - 1])
                {
                    new_cords.parent_x = v.x;
                    new_cords.parent_y = v.y;
                    new_cords.x = v.x;
                    new_cords.y = v.y - 1;
                    q.push(new_cords);
                    Visited[v.x][v.y - 1] = 1;
                }
            }
        }
    }
    cout << "No";
    return 0;
}