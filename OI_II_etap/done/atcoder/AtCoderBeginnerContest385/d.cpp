#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;

class Solve
{
protected:
    int n, m;
    map<ll, set<ll>> WspolrzedneX, WspolrzedneY;
    ll StartX, StartY;
    int ileDomowOdwiedzil = 0;
    const char Left = 'L';
    const char Right = 'R';
    const char Up = 'U';
    const char Down = 'D';

public:
    inline void solve()
    {
        cin >> n >> m >> StartX >> StartY;

        FOR(i, n, 0)
        {
            ll DomX, DomY;
            cin >> DomX >> DomY;
            WspolrzedneX[DomX].insert(DomY);
            WspolrzedneY[DomY].insert(DomX);
        }

        while (m--)
        {
            char move;
            ll dist;
            cin >> move >> dist;

            if (move == Up)
            {
                ll newY = StartY + dist;
                auto it = WspolrzedneX[StartX].upper_bound(newY);
                auto itr = WspolrzedneX[StartX].lower_bound(StartY);

                vector<ll> To_remove;

                for (itr; itr != it; itr++)
                {
                    ileDomowOdwiedzil++;
                    To_remove.push_back(*itr);
                }

                for (ll w : To_remove)
                {
                    WspolrzedneX[StartX].erase(w);
                    WspolrzedneY[w].erase(StartX);
                }
                StartY = newY;
            }
            else if (move == Down)
            {
                ll newY = StartY - dist;
                auto it = WspolrzedneX[StartX].upper_bound(StartY);
                auto itr = WspolrzedneX[StartX].lower_bound(newY);

                vector<ll> To_remove;

                for (itr; itr != it; itr++)
                {
                    ileDomowOdwiedzil++;
                    To_remove.push_back(*itr);
                }

                for (ll w : To_remove)
                {
                    WspolrzedneX[StartX].erase(w);
                    WspolrzedneY[w].erase(StartX);
                }
                StartY = newY;
            }
            else if (move == Right)
            {
                ll newX = StartX + dist;
                auto it = WspolrzedneY[StartY].upper_bound(newX);
                auto itr = WspolrzedneY[StartY].lower_bound(StartX);

                vector<ll> To_remove;

                for (itr; itr != it; itr++)
                {
                    ileDomowOdwiedzil++;
                    To_remove.push_back(*itr);
                }

                for (ll w : To_remove)
                {
                    WspolrzedneY[StartY].erase(w);
                    WspolrzedneX[w].erase(StartY);
                }
                StartX = newX;
            }
            else if (move == Left)
            {
                ll newX = StartX - dist;
                auto it = WspolrzedneY[StartY].upper_bound(StartX);
                auto itr = WspolrzedneY[StartY].lower_bound(newX);

                vector<ll> To_remove;

                for (itr; itr != it; itr++)
                {
                    ileDomowOdwiedzil++;
                    To_remove.push_back(*itr);
                }

                for (ll w : To_remove)
                {
                    WspolrzedneY[StartY].erase(w);
                    WspolrzedneX[w].erase(StartY);
                }
                StartX = newX;
            }
        }

        cout << StartX << " " << StartY << " " << ileDomowOdwiedzil << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;
    solution.solve();

    return 0;
}