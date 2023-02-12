#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1010;
int Grid[M][M];
int n;
queue<pair<int, int>> q;
pair<int, int> v, Start;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    bool isWall = 0;
    pair<int, int> Meta;
    char z;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> z;
            if (z == '.')
                Grid[i][j] = 0;
            else if (z == 'X')
                Grid[i][j] = -1;
            else if (z == '#')
            {
                Grid[i][j] = 1;
                isWall = 1;
            }
            else if (z == 'S')
                Start.first = i, Start.second = j;
            else if (z == 'K')
            {
                Grid[i][j] = 10;
                Meta.first = i, Meta.second = j;
            }
        }
    if (!isWall)
    {
        vector<vector<bool>> Vis(n + 1, vector<bool>(n + 1));
        vector<vector<int>> Dist(n + 1, vector<int>(n + 1));
        vector<vector<char>> Path(n + 1, vector<char>(n + 1));
        q.push(Start);
        Vis[Start.first][Start.second] = 1;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            if (v.first > 1 && !Vis[v.first - 1][v.second] && (Grid[v.first - 1][v.second] == 0 || Grid[v.first - 1][v.second] == 10))
            {
                Vis[v.first - 1][v.second] = 1;
                Dist[v.first - 1][v.second] = Dist[v.first][v.second] + 1;
                Path[v.first - 1][v.second] = 'G';
                q.push({v.first - 1, v.second});
            }
            if (v.first < n && !Vis[v.first + 1][v.second] && (Grid[v.first + 1][v.second] == 0 || Grid[v.first + 1][v.second] == 10))
            {
                Vis[v.first + 1][v.second] = 1;
                Dist[v.first + 1][v.second] = Dist[v.first][v.second] + 1;
                Path[v.first + 1][v.second] = 'D';
                q.push({v.first + 1, v.second});
            }
            if (v.second > 1 && !Vis[v.first][v.second - 1] && (Grid[v.first][v.second - 1] == 0 || Grid[v.first][v.second - 1] == 10))
            {
                Vis[v.first][v.second - 1] = 1;
                Dist[v.first][v.second - 1] = Dist[v.first][v.second] + 1;
                Path[v.first][v.second - 1] = 'L';
                q.push({v.first, v.second - 1});
            }
            if (v.second < n && !Vis[v.first][v.second + 1] && (Grid[v.first][v.second + 1] == 0 || Grid[v.first][v.second + 1] == 10))
            {
                Vis[v.first][v.second + 1] = 1;
                Dist[v.first][v.second + 1] = Dist[v.first][v.second] + 1;
                Path[v.first][v.second + 1] = 'P';
                q.push({v.first, v.second + 1});
            }
        }
        cout << Dist[Meta.first][Meta.second] << "\n";
        cout << 1 << " " << 1 << "\n";
        vector<char> PathRes;
        pair<int, int> Cords;
        Cords = Meta;
        while (Cords != Start)
        {
            PathRes.push_back(Path[Cords.first][Cords.second]);
            if (Path[Cords.first][Cords.second] == 'G')
                Cords.first--;
            else if (Path[Cords.first][Cords.second] == 'D')
                Cords.first++;
            else if (Path[Cords.first][Cords.second] == 'L')
                Cords.second++;
            else if (Path[Cords.first][Cords.second] == 'P')
                Cords.second--;
        }
        for (int i = PathRes.size() - 1; i >= 0; i--)
            cout << PathRes[i];
    }
    
}