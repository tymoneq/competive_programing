#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

struct Point
{
    int PointX, PointY;
};

class Solve
{
protected:
    ll res = 0;
    int n;
    const int MAXY = 11;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> MST_kolejka; // first cost, second id
    set<int> WykorzystaneV;
    vector<vector<int>> Punkty;
    vector<Point> Wspolrzedne;

public:
    inline void read_data()
    {
        cin >> n;
        Punkty.resize(MAXY);
        Wspolrzedne.resize(n);

        FOR(i, n, 0)
        {
            int x, y;
            cin >> x >> y;
            Wspolrzedne[i] = {x, y};
            Punkty[y].push_back(i);
        }

        FOR(i, MAXY, 0)
        sort(Punkty[i].begin(), Punkty[i].end(), [this](const int lhs, const int rhs)
             {
            const Point& pa = Wspolrzedne[lhs];
            const Point& pb = Wspolrzedne[rhs]; 
            
            return pa.PointX < pb.PointX ; });
    }

    inline ll calcCost(const int lhsID, const int rhsID)
    {
        ll xDiff = Wspolrzedne[lhsID].PointX - Wspolrzedne[rhsID].PointX;
        ll yDiff = Wspolrzedne[lhsID].PointY - Wspolrzedne[rhsID].PointY;

        return (xDiff * xDiff) + (yDiff * yDiff);
    }

    inline int find_the_same_x(const int &id, const int AktualnyY)
    {
        int lo = 0, hi = Punkty[AktualnyY].size() - 1, mid;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (Wspolrzedne[id].PointX == Wspolrzedne[Punkty[AktualnyY][mid]].PointX)
                return Punkty[AktualnyY][mid];

            if (Wspolrzedne[id].PointX < Wspolrzedne[Punkty[AktualnyY][mid]].PointX)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }

    inline int find_bigger_X(const int &id, const int AktualnyY)
    {
        int lo = 0, hi = Punkty[AktualnyY].size() - 1, mid, ans = -1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Wspolrzedne[id].PointX < Wspolrzedne[Punkty[AktualnyY][mid]].PointX)
            {
                ans = Punkty[AktualnyY][mid];
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
    inline int find_smaller_X(const int &id, const int AktualnyY)
    {
        int lo = 0, hi = Punkty[AktualnyY].size() - 1, mid, ans = -1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Wspolrzedne[id].PointX > Wspolrzedne[Punkty[AktualnyY][mid]].PointX)
            {
                ans = Punkty[AktualnyY][mid];
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }

    inline void dodaj_do_kolejki(const int id_nowego_punktu, const int id_starego_punktu)
    {
        if (id_nowego_punktu != -1 && id_nowego_punktu != id_starego_punktu)
        {
            ll koszt = calcCost(id_nowego_punktu, id_starego_punktu);
            MST_kolejka.push({koszt, id_nowego_punktu});
        }
    }

    inline void dodaj_kandydatow(const int &id)
    {
        FOR(i, MAXY, 0)
        {
            if (Punkty[i].size() == 0)
                continue;

            // znajdz punkt o tym samym X
            int id_tego_samego_x = find_the_same_x(id, i);
            dodaj_do_kolejki(id_tego_samego_x, id);

            // znajdz punkt o  wiekszym x
            int id_wiekszego_x = find_bigger_X(id, i);
            dodaj_do_kolejki(id_wiekszego_x, id);

            // znajdz punkt o mniejszym x

            int id_mniejszego_x = find_smaller_X(id, i);
            dodaj_do_kolejki(id_mniejszego_x, id);
        }
    }

    inline void solve()
    {
        read_data();
        int id_pierwszego_punktu = -1;

        FOR(i, MAXY, 0)
        if (Punkty[i].size() > 0)
        {
            id_pierwszego_punktu = Punkty[i][0];
            break;
        }

        WykorzystaneV.insert(id_pierwszego_punktu);
        dodaj_kandydatow(id_pierwszego_punktu);

        while (!MST_kolejka.empty() && WykorzystaneV.size() < n)
        {
            auto punkt = MST_kolejka.top();
            MST_kolejka.pop();

            if (WykorzystaneV.count(punkt.second))
                continue;

            res += punkt.first;
            WykorzystaneV.insert(punkt.second);

            dodaj_kandydatow(punkt.second);
        }

        cout << res << '\n';
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