#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int N;
    ll res = 0;
    ll all_cost = 0;

    const int States = 3;

    struct edge
    {
        ll to, cost;
    };

    vector<vector<edge>> Galaktyka;

    vector<vector<ll>> dp;

    vector<ll> STO;

public:
    inline void read_data()
    {
        cin >> N;

        Galaktyka.resize(N + 1);
        STO.resize(N + 1);

        dp.resize(N + 1, vector<ll>(States));

        FOR(i, N, 1)
        {
            ll from, to, cost;
            cin >> from >> to >> cost;

            STO[from]++;
            STO[to]++;

            Galaktyka[from].push_back({to, cost});
            Galaktyka[to].push_back({from, cost});

            all_cost += cost;
        }
    }

    inline void calc_dp(int v, int p)
    {
        // liść
        if (Galaktyka[v].size() == 1)
            return;

        // dfs w dół drzewa
        ll kraw_ojca = 0;
        for (auto w : Galaktyka[v])
        {
            if (w.to != p)
                calc_dp(w.to, v);

            if (w.to == p)
                kraw_ojca = w.cost;
        }

        // zliczanie wyników stan 0

        pair<ll, ll> mx_zysk = {0, 0};

        for (auto w : Galaktyka[v])
            if (w.to != p)
            {
                dp[v][0] += max(dp[w.to][0], dp[w.to][2]);
                if (w.cost > mx_zysk.first)
                {
                    mx_zysk.second = mx_zysk.first;
                    mx_zysk.first = w.cost;
                }
                else if (w.cost > mx_zysk.second)
                    mx_zysk.second = w.cost;
            }

        if (mx_zysk.first != 0 && mx_zysk.second != 0)
            dp[v][0] += mx_zysk.first + mx_zysk.second;

        // stan 1

        ll suma_wynikow = 0;
        ll mx_state_1 = 0;

        for (auto w : Galaktyka[v])
            if (w.to != p)
                suma_wynikow += max({dp[w.to][0], dp[w.to][1], dp[w.to][2]});

        for (auto w : Galaktyka[v])
            if (w.to != p)
            {
                suma_wynikow -= max({dp[w.to][0], dp[w.to][1], dp[w.to][2]});
                suma_wynikow += w.cost;
                suma_wynikow += max({dp[w.to][0], dp[w.to][2]});

                mx_state_1 = max(mx_state_1, suma_wynikow);

                suma_wynikow += max({dp[w.to][0], dp[w.to][1], dp[w.to][2]});
                suma_wynikow -= w.cost;
                suma_wynikow -= max({dp[w.to][0], dp[w.to][2]});
            }

        if (mx_zysk.first != 0)
            dp[v][1] = mx_state_1 + kraw_ojca;

        if (kraw_ojca == 0)
            dp[v][1] = 0;

        // liczenie stanu 2

        ll best_son = 0;
        ll mx = 0;

        for (auto w : Galaktyka[v])
            if (w.to != p && dp[w.to][1] > mx)
            {
                mx = dp[w.to][1];
                best_son = w.to;
            }

        if (best_son != 0)
        {
            mx_zysk = {0, 0};
            dp[v][2] += mx;

            for (auto w : Galaktyka[v])
                if (w.to != p && w.to != best_son)
                {
                    dp[v][2] += max(dp[w.to][0], dp[w.to][2]);

                    if (w.cost > mx_zysk.first)
                    {
                        mx_zysk.second = mx_zysk.first;
                        mx_zysk.first = w.cost;
                    }
                    else if (w.cost > mx_zysk.second)
                        mx_zysk.second = w.cost;
                }

            if (mx_zysk.first != 0 && mx_zysk.second != 0)
                dp[v][2] += mx_zysk.first + mx_zysk.second;
        }
    }

    inline void solve()
    {
        read_data();

        bool gwiazda = false;

        ll cnt = 0;

        FOR(i, N + 1, 1)
        {
            if (STO[i] == N - 1)
            {
                gwiazda = true;
            }
            if (STO[i] == 1)
                cnt++;
        }

        if (gwiazda)
        {
            ll gwiazd;

            FOR(i, N + 1, 1)
            if (STO[i] == N - 1)
            {
                gwiazd = i;
                break;
            }

            sort(Galaktyka[gwiazd].begin(), Galaktyka[gwiazd].end(), [this](edge &lhs, edge &rhs)
                 { return lhs.cost > rhs.cost; });

            res += Galaktyka[gwiazd][0].cost + Galaktyka[gwiazd][1].cost;
        }
        else if (cnt == 2)
        {
            // scieżka

            pair<ll, ll> id = {-1, -1};
            if (N % 2 == 0)
            {
                FOR(i, N + 1, 1)
                if (STO[i] == 1)
                {
                    if (id.first == -1)
                        id.first = i;

                    else
                        id.second = i;
                }

                all_cost -= min(Galaktyka[id.first][0].cost, Galaktyka[id.second][0].cost);
            }

            res = all_cost;
        }
        else
        {
            // dp

            calc_dp(1, 0);

            res = max({dp[1][0], dp[1][1], dp[1][2]});
        }

        cout << res << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}