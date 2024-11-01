#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct lot
{
    int time, cost;
};

struct loty
{
    int time, cost, city;
};

inline int upperBound(vector<lot> &a, int timer)
{
    int lo = 0, hi = a.size() - 1, mid, ans = a.size();

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if (a[mid].time > timer)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return ans;
}

inline bool sorto(lot &lhs, lot &rhs) { return lhs.time < rhs.time; }

inline bool sortLoty(loty &lhs, loty &rhs) { return lhs.time < rhs.time; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, d, f, t, c;
    ll res = 0;

    cin >> n >> m >> k;

    vector<vector<lot>> Przyloty(n + 1), Odloty(n + 1);
    vector<int> minOdloty(n + 1, numeric_limits<int>::max()), minPrzyloty(n + 1, numeric_limits<int>::max());
    vector<vector<int>> PrefSumPrzyloty(n + 1);
    vector<loty> przyloty, odloty;

    for (int i = 0; i < m; i++)
    {
        cin >> d >> f >> t >> c;
        if (f == 0)
        {
            Przyloty[t].push_back({d, c});
            przyloty.push_back({d, c, t});
        }
        else
        {
            Odloty[f].push_back({d, c});
            odloty.push_back({d, c, f});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        sort(Przyloty[i].begin(), Przyloty[i].end(), sorto);
        sort(Odloty[i].begin(), Odloty[i].end(), sorto);
    }

    int pocz = 0, koniec = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++)
    {
        if (Odloty[i].size() == 0 || Przyloty[i].size() == 0)
        {
            koniec = -100;
            break;
        }
        pocz = max(pocz, Odloty[i][0].time);
        koniec = min(koniec, Przyloty[i][Przyloty[i].size() - 1].time);
    }

    if (pocz + k >= koniec)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        PrefSumPrzyloty[i].resize(Przyloty[i].size());
        PrefSumPrzyloty[i][Przyloty[i].size() - 1] = Przyloty[i][Przyloty[i].size() - 1].cost;

        for (int j = Przyloty[i].size() - 2; j >= 0; j--)
            PrefSumPrzyloty[i][j] = min(PrefSumPrzyloty[i][j + 1], Przyloty[i][j].cost);
    }

    sort(odloty.begin(), odloty.end(), sortLoty);
    sort(przyloty.begin(), przyloty.end(), sortLoty);

    int l = 0, r = przyloty.size() - 1;
    while (l < odloty.size() && odloty[l].time <= pocz)
    {
        minOdloty[odloty[l].city] = min(odloty[l].cost, minOdloty[odloty[l].city]);
        l++;
    }
    l--;

    while (r >= 0 && pocz + k < przyloty[r].time)
        r--;
    r++;

    for (int i = 1; i <= n; i++)
    {
        res += minOdloty[i];

        int indx = upperBound(Przyloty[i], przyloty[r].time - 1);
        minPrzyloty[i] = PrefSumPrzyloty[i][indx];
        res += PrefSumPrzyloty[i][indx];
    }

    ll res2 = res;
    while (l + 1 < odloty.size() && odloty[l + 1].time + k < koniec)
    {

        l++;

        if (odloty[l].cost < minOdloty[odloty[l].city])
        {
            res2 += odloty[l].cost - minOdloty[odloty[l].city];
            minOdloty[odloty[l].city] = odloty[l].cost;
        }

        while (r < przyloty.size() && odloty[l].time + k >= przyloty[r].time)
        {
            res2 -= minPrzyloty[przyloty[r].city];
            int indx = upperBound(Przyloty[przyloty[r].city], przyloty[r].time);
            res2 += PrefSumPrzyloty[przyloty[r].city][indx];
            minPrzyloty[przyloty[r].city] = PrefSumPrzyloty[przyloty[r].city][indx];
            r++;
        }
        res = min(res, res2);
    }

    cout << res << "\n";
    return 0;
}