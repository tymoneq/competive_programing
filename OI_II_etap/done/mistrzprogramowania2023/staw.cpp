#include <bits/stdc++.h>

using namespace std;
constexpr int M = 20;
int Grid[3][M];
int StawPref[M], Connect[M];
bool Vis[3][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    cin >> n;
    char z;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> z;
            Grid[i][j] = z - '0';
        }
    int staw = 0;
    queue<pair<int, int>> que;
    for (int j = 1; j <= n; j++)
    {
        staw = 0;
        if (Grid[0][j] == 1 && Grid[0][j - 1] == 1)
            Connect[j] = 1;
        else if (Grid[0][j] == 1)
            staw++;
        if (Grid[1][j] == 1 && Grid[1][j - 1] == 1 && Grid[0][j] != 1)
            Connect[j] = 1;
        else if (Grid[1][j] == 1 && Grid[0][j] != 1)
            staw++;
        if (Grid[2][j] == 1 && (Grid[2][j - 1] == 1 && Grid[1][j] != 1))
        {
           
        }
        else if (Grid[2][j] == 1 && Grid[1][j] != 1)
            staw++;
        StawPref[j] = StawPref[j - 1] + staw;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << StawPref[b] - StawPref[a - 1] + Connect[a] << "\n";
    }
    return 0;
}