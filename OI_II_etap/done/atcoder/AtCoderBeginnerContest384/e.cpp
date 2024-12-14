#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

constexpr int N = 510;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

ll Grid[N][N];
bool Vis[N][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int H, W, P, Q;
    ll X;

    cin >> H >> W >> X >> P >> Q;

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> Grid[i][j];

    ll MXPower = Grid[P][Q];

    set<pair<ll, pair<int, int>>> pq;
    Vis[P][Q] = 1;

    for (int i = 0; i < 4; i++)
    {
        if (P + dx[i] == 0 || P + dx[i] == H + 1 || Q + dy[i] == 0 || Q + dy[i] == W + 1)
            continue;

        pq.insert({Grid[P + dx[i]][Q + dy[i]], {P + dx[i], Q + dy[i]}});
    }

    while (!pq.empty())
    {
        auto w = pq.begin();

        if (Vis[w->second.first][w->second.second])
        {
            pq.erase(pq.begin());
            continue;
        }

        ll power = MXPower / X;
        if (MXPower % X != 0)
            power++;

        if (w->first < power)
        {
            MXPower += w->first;
            Vis[w->second.first][w->second.second] = 1;

            int x = w->second.first;
            int y = w->second.second;
            pq.erase(pq.begin());
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] == 0 || x + dx[i] == H + 1 || y + dy[i] == 0 || y + dy[i] == W + 1)
                    continue;

                pq.insert({Grid[x + dx[i]][y + dy[i]], {x + dx[i], y + dy[i]}});
            }
        }
        else
            break;
    }
    cout << MXPower << '\n';

    return 0;
}