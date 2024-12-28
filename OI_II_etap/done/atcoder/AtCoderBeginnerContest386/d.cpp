#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct point
{
    int PointX, PointY;
    char typ;
};

class Solve
{
protected:
    int n;
    int m;
    vector<point> Punkty;
    set<pair<int, int>> Czarne;
    bool Correct = 1;
    const char Black = 'B';
    const char White = 'W';

public:
    static bool sorto(const point &lhs, const point &rhs)
    {
        if (lhs.PointX == rhs.PointX)
            return lhs.PointY > rhs.PointY;
        return lhs.PointX > rhs.PointX;
    }
    inline void read_data()
    {
        cin >> n >> m;

        Punkty.resize(m);
        FOR(i, m, 0)
        cin >> Punkty[i].PointX >> Punkty[i].PointY >> Punkty[i].typ;

        sort(Punkty.begin(), Punkty.end(), sorto);
    }
    inline void solve()
    {
        read_data();

        FOR(i, m, 0)
        {
            if (Punkty[i].typ == Black)
                Czarne.insert({Punkty[i].PointY, Punkty[i].PointX});

            else if (Punkty[i].typ == White)
            {
                auto it = Czarne.lower_bound({Punkty[i].PointY, Punkty[i].PointX});
                if (it == Czarne.end())
                    continue;
                else
                    Correct = 0;
            }
        }

        if (Correct)
            cout << "Yes\n";
        else
            cout << "No\n";
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