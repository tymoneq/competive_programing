#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    const char Blocked = '#';
    const char Empty = '.';
    const char House = '@';
    const char Left = 'L';
    const char Right = 'R';
    const char Up = 'U';
    const char Down = 'D';

    vector<vector<char>> Grid;
    vector<vector<bool>> Vis;
    int ileDomowOdwiedzil = 0;
    int Szerokosc, Wysokosc;
    int StartX, StartY;
    string moves;

public:
    inline void solve()
    {

        cin >> Szerokosc >> Wysokosc >> StartX >> StartY;

        Grid.resize(Szerokosc + 1);
        Vis.resize(Szerokosc + 1);

        FOR(i, Szerokosc + 1, 0)
        {
            Grid[i].resize(Wysokosc + 1);
            Vis[i].resize(Wysokosc + 1);
        }

        FOR(i, Szerokosc + 1, 1)
        FOR(j, Wysokosc + 1, 1)
        cin >> Grid[i][j];

        cin >> moves;

        for (char w : moves)
        {

            if (Grid[StartX][StartY] == House && !Vis[StartX][StartY])
            {
                ileDomowOdwiedzil++;
                Vis[StartX][StartY] = 1;
            }

            if (w == Left && Grid[StartX][StartY - 1] != Blocked)
            {
                StartY--;
            }
            else if (w == Right && Grid[StartX][StartY + 1] != Blocked)
            {
                StartY++;
            }
            else if (w == Up && Grid[StartX - 1][StartY] != Blocked)
            {
                StartX--;
            }
            else if (w == Down && Grid[StartX + 1][StartY] != Blocked)
            {
                StartX++;
            }
        }
        if (Grid[StartX][StartY] == House && !Vis[StartX][StartY])
        {
            ileDomowOdwiedzil++;
            Vis[StartX][StartY] = 1;
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