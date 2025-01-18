#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    struct edge
    {
        vector<int> Miecze;
        int from, to;
    };

    vector<vector<int>> Graf;
    vector<int> DystanseOd1, DystanseOdN;
    vector<bool> Odwiedzone;
    const int INF = 1e9 + 9;
    vector<edge> Krawedzie;

    int n, m, MaxDystans, iloscMieczy;
    vector<int> MieczeAns;

public:
    inline void read_data()
    {
        cin >> n >> m >> MaxDystans >> iloscMieczy;

        Graf.resize((n + 1) * (1 << iloscMieczy));
        DystanseOd1.resize((n + 1) * (1 << iloscMieczy), INF);
        DystanseOdN.resize((n + 1) * (1 << iloscMieczy), INF);
        Odwiedzone.resize((n + 1) * (1 << iloscMieczy));
        Krawedzie.resize(m);

        vector<int> miecze;
        miecze.resize(iloscMieczy);
        FOR(i, m, 0)
        {
            int a, b;

            cin >> a >> b;
            FOR(j, iloscMieczy, 0)
            cin >> miecze[j];

            Krawedzie[i] = {miecze, a, b};
        }
    }

    inline void create_graph()
    {

        FOR(i, 1 << iloscMieczy, 0)
        FOR(j, m, 0)
        {
            int from = Krawedzie[j].from, to = Krawedzie[j].to;
            Graf[from + (n * i)].push_back(to + (n * i));
            Graf[to + (n * i)].push_back(from + (n * i));
        }
    }

    inline void bfs(vector<int> &Dist, int start)
    {

        queue<int> kolejkaBFS;
        kolejkaBFS.push(start);

        Odwiedzone[start] = true;
        Dist[start] = 0;

        while (!kolejkaBFS.empty())
        {
            int v = kolejkaBFS.front();
            kolejkaBFS.pop();

            for (int w : Graf[v])
                if (!Odwiedzone[w])
                {
                    Odwiedzone[w] = true;
                    Dist[w] = Dist[v] + 1;
                    kolejkaBFS.push(w);
                }
        }
    }

    inline void solve()
    {
        read_data();
        create_graph();

        FOR(miecz, iloscMieczy, 0)
        { // pierwszy bfs
            FOR(i, DystanseOd1.size(), 0)
            DystanseOd1[i] = INF;

            FOR(i, Odwiedzone.size(), 0)
            Odwiedzone[i] = 0;

            bfs(DystanseOd1, 1);

            // drugi bfs
            FOR(i, DystanseOdN.size(), 0)
            DystanseOdN[i] = INF;

            FOR(i, Odwiedzone.size(), 0)
            Odwiedzone[i] = 0;

            bfs(DystanseOdN, n);

            // znajdz najlepszy miecz
            int best_miecz = 0;

            for (auto kraw : Krawedzie)
            {
                int aktualnaMaska = (1 << miecz) - 1;
                FOR(mask, 1 << miecz, 0)
                {
                    int maska2 = aktualnaMaska ^ mask;

                    int dist = DystanseOd1[kraw.from + (n * mask)] + DystanseOdN[kraw.to + (n * maska2)] + 1;
                    dist = min(dist, DystanseOdN[kraw.from + (n * mask)] + DystanseOd1[kraw.to + (n * maska2)] + 1);

                    if (dist <= MaxDystans)
                    {
                        best_miecz = max(best_miecz, kraw.Miecze[miecz]);
                        break;
                    }
                }
            }

            for (auto kraw : Krawedzie)
            {
                if (kraw.Miecze[miecz] != best_miecz)
                    continue;

                int aktualnaMaska = (1 << miecz) - 1;

                bool dobry = false;
                FOR(mask, 1 << miecz, 0)
                {
                    int maska2 = aktualnaMaska ^ mask;

                    int dist = DystanseOd1[kraw.from + (n * mask)] + DystanseOdN[kraw.to + (n * maska2)] + 1;
                    dist = min(dist, DystanseOdN[kraw.from + (n * mask)] + DystanseOd1[kraw.to + (n * maska2)] + 1);

                    if (dist <= MaxDystans)
                    {
                        dobry = true;
                        break;
                    }
                }

                if (!dobry)
                    continue;

                FOR(mask, (1 << iloscMieczy), 0)
                if (mask & (1 << miecz))
                {
                    Graf[kraw.from].push_back(kraw.to + (n * mask));
                    Graf[kraw.to + (n * mask)].push_back(kraw.from);

                    Graf[kraw.to].push_back(kraw.from + (n * mask));
                    Graf[kraw.from + (n * mask)].push_back(kraw.to);
                }
            }

            MieczeAns.push_back(best_miecz);
        }

        for (int miecz : MieczeAns)
            cout << miecz << " ";
        cout << '\n';
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