#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int G[n][m]{-1};
    pair<int, int> start, meta;
    for (int i = 0; i < m; i++)
    {
        string znak;
        cin >> znak;
        for (int j = 0; j < znak.size(); j++)
        {

            if (znak[j] == 'S')
            {
                start = make_pair(i, j);
                G[i][j] = 0;
            }
            else if (znak[j] == 'W')
            {
                meta = make_pair(i, j);
                G[i][j] = 10;
            }
            else if (znak[j] == '!')
            {
                G[i][j] = 1;
            }

            else if (znak[j] == '#')
                G[i][j] = -1;
        }
    }
    queue<pair<int, int>> Q;
    int P[n][m]{0};
    Q.push(start);
    bool visited[n][m]{false};
    visited[start.first][start.second] = true;
    P[start.first][start.second] = 0;
    while (!Q.empty())
    {
        pair<int, int> index;
        index = Q.front();
        Q.pop();
        if (!visited[index.first][index.second])
        {
            if (G[index.first - 1][index.second] == -1)
            {
                visited[index.first - 1][index.second] = true;
            }
            else if (G[index.first][index.second - 1] == -1)
            {
                visited[index.first][index.second - 1] = true;
            }
            else if (G[index.first + 1][index.second] == -1)
            {
                visited[index.first + 1][index.second] = true;
            }
            else if (G[index.first][index.second + 1] == -1)
            {
                visited[index.first][index.second + 1] = true;
            }

            /*
            ####################################################
            */

            if (G[index.first - 1][index.second] == 1)
            {
                visited[index.first - 1][index.second] = true;
                Q.push(make_pair(index.first - 1, index.second));
                P[index.first - 1][index.second] = 1 + P[index.first][index.second];
            }
            else if (G[index.first][index.second - 1] == 1)
            {
                visited[index.first][index.second - 1] = true;
                Q.push(make_pair(index.first, index.second - 1));
                P[index.first][index.second - 1] = 1 + P[index.first][index.second];
            }
            else if (G[index.first + 1][index.second] == 1)
            {
                visited[index.first + 1][index.second] = true;
                Q.push(make_pair(index.first + 1, index.second));
                P[index.first + 1][index.second] = 1 + P[index.first][index.second];
            }
            else if (G[index.first][index.second + 1] == 1)
            {
                visited[index.first][index.second + 1] = true;
                Q.push(make_pair(index.first, index.second + 1));
                P[index.first][index.second + 1] = 1 + P[index.first][index.second];
            }
            /*
                    ####################################################
                    */
            if (G[index.first - 1][index.second] == 10)
            {
                visited[index.first - 1][index.second] = true;
                P[index.first - 1][index.second] = P[index.first][index.second] + 1;
                break;
            }
            else if (G[index.first][index.second - 1] == 10)
            {
                visited[index.first][index.second - 1] = true;
                P[index.first][index.second - 1] = P[index.first][index.second] + 1;
                break;
            }
            else if (G[index.first + 1][index.second] == 10)
            {
                visited[index.first + 1][index.second] = true;
                P[index.first + 1][index.second] = P[index.first][index.second] + 1;
                break;
            }
            else if (G[index.first][index.second + 1] == 10)
            {
                visited[index.first][index.second + 1] = true;
                P[index.first][index.second + 1] = P[index.first][index.second] + 1;
                break;
            }
        }
    }

    cout << P[meta.first][meta.second] << "\n";
    return 0;
}