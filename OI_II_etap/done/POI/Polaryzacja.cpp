#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
    int operator()(int x) const { return x ^ RANDOM; }
};

class Solve
{
protected:
    int n;
    vector<vector<int>> Bajtocja;
    vector<ll> Sajz, Depth;
    vector<int> Parent;
    static const int MAXN = 2.5e5 + 10;
    bitset<MAXN> Plecak;
    map<int, int> Wartosci;
    ll res = 0;

public:
    inline void sajzDfs(int v, int p)
    {
        Parent[v] = p;
        Sajz[v] = 1;
        for (int w : Bajtocja[v])
            if (w != p)
            {
                sajzDfs(w, v);
                Sajz[v] += Sajz[w];
            }
    }
    inline void DepthDfs(int v, int p)
    {
        for (int w : Bajtocja[v])
            if (w != p)
            {
                Depth[w] = Depth[v] + 1;
                DepthDfs(w, v);
            }
    }

    inline int IsCentroid(int v)
    {
        for (int w : Bajtocja[v])
        {
            if (w == Parent[v] && (Sajz[w] - Sajz[v]) > n / 2)
                return IsCentroid(w);

            else if (w != Parent[v] && (Sajz[w]) > n / 2)
                return IsCentroid(w);
        }
        return v;
    }

    inline int CheckSecondCentroid(int v)
    {
        int ans = -1;
        for (int w : Bajtocja[v])
        {
            if (w == Parent[v] && (Sajz[w] - Sajz[v]) >= ((n + 1) / 2))
                ans = w;

            else if (w != Parent[v] && (Sajz[w]) >= ((n + 1) / 2))
                ans = w;
        }
        return ans;
    }

    inline pair<int, int> fintCentroid(int v, int p)
    {
        sajzDfs(v, p);

        int centr = IsCentroid(v);
        int secondCentroid = CheckSecondCentroid(centr);
        return {centr, {secondCentroid != -1 ? secondCentroid : centr}};
    }

    inline ll plecak()
    {
        Plecak[0] = 1;

        for (auto &el : Wartosci)
            while (el.second > 2)
            {
                Wartosci[el.first * 2]++;
                el.second -= 2;
            }

        for (auto &val : Wartosci)
            for (int cnt = 0; cnt < val.second; cnt++)
                Plecak |= (Plecak << (val.first));

        ll bestVal = 0;
        for (int i = ((n - 1) / 2); i >= 0; i--)
            if (Plecak[i])
            {
                bestVal = i;
                break;
            }

        return bestVal * (n - bestVal - 1);
    }

    inline void calcRes(int v)
    {
        FOR(i, n + 1, 0)
        {
            Depth[i] = 0;
            Sajz[i] = 0;
        }

        ll ans = 0;
        sajzDfs(v, v);
        for (int w : Bajtocja[v])
            Wartosci[Sajz[w]]++;

        DepthDfs(v, v);
        FOR(i, n + 1, 1)
        ans += Depth[i];

        ans += plecak();

        FOR(i, n + 1, 0)
        Plecak[i] = 0;
        res = max(ans, res);
        Wartosci.clear();
    }

    inline void solve()
    {

        cin >> n;
        Bajtocja.resize(n + 1);
        Sajz.resize(n + 1);
        Depth.resize(n + 1);
        Parent.resize(n + 1);

        FOR(i, n, 1)
        {
            int a, b;
            cin >> a >> b;
            Bajtocja[a].push_back(b);
            Bajtocja[b].push_back(a);
        }

        auto centroid = fintCentroid(1, 1);

        calcRes(centroid.first);
        calcRes(centroid.second);

        cout << n - 1 << " " << res << '\n';
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