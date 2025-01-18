#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    const int INF = 1e9 + 5;
    vector<int> STOdobreSkierowanie;
    vector<int> STOZleSkierowanie;

    vector<vector<int>> Warstwy;

    vector<multiset<int, greater<int>>> DistzSkierowaniem;
    vector<multiset<int, greater<int>>> DistprzeciwnyDoSkierowania;

    vector<vector<int>> SomsiadzSkierowaniem;
    vector<vector<int>> SomsiadprzeciwneSkierowanie;

    multiset<int> VwWarstwie;

    pair<int, int> ans = {1e9 + 5, 0};
    int pierwszaWarstwa = 0;

public:
    inline void read_data()
    {
        cin >> N >> M;

        Warstwy.resize(N + 1);
        DistprzeciwnyDoSkierowania.resize(N + 1);
        DistzSkierowaniem.resize(N + 1);
        STOdobreSkierowanie.resize(N + 1);
        STOZleSkierowanie.resize(N + 1);
        SomsiadprzeciwneSkierowanie.resize(N + 1);
        SomsiadzSkierowaniem.resize(N + 1);

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;

            STOdobreSkierowanie[b]++;
            STOZleSkierowanie[a]++;

            SomsiadzSkierowaniem[a].push_back(b);
            SomsiadprzeciwneSkierowanie[b].push_back(a);
        }
    }

    inline void toposort(vector<int> STO, vector<vector<int>> &Graf)
    {
        queue<int> KolejkaToposort;
        vector<int> MAXWarstwaPrzodek(N + 1);

        FOR(i, N + 1, 1)
        if (STO[i] == 0)
            KolejkaToposort.push(i);

        while (!KolejkaToposort.empty())
        {
            int v = KolejkaToposort.front();
            KolejkaToposort.pop();

            Warstwy[MAXWarstwaPrzodek[v] + 1].push_back(v);

            for (int w : Graf[v])
            {
                STO[w]--;
                MAXWarstwaPrzodek[w] = max(MAXWarstwaPrzodek[w], MAXWarstwaPrzodek[v] + 1);

                if (STO[w] == 0)
                    KolejkaToposort.push(w);
            }
        }
    }

    inline void bfs(vector<int> &STO, vector<vector<int>> &Graf, vector<multiset<int, greater<int>>> &Dist)
    {
        queue<int> KolejkaBfs;
        FOR(i, N + 1, 1)
        if (STO[i] == 0)
        {
            KolejkaBfs.push(i);
            Dist[i].insert(0);
        }

        while (!KolejkaBfs.empty())
        {
            int v = KolejkaBfs.front();
            KolejkaBfs.pop();

            for (int w : Graf[v])
            {
                Dist[w].insert(*Dist[v].begin() + 1);
                STO[w]--;
                if (STO[w] == 0)
                    KolejkaBfs.push(w);
            }
        }
    }

    inline int get_dist(int v)
    {
        int distZskierowaniem = 0;
        int distPrzeciwnySkierowanie = 0;

        if (!DistprzeciwnyDoSkierowania[v].empty())
            distPrzeciwnySkierowanie = *DistprzeciwnyDoSkierowania[v].begin();

        if (!DistzSkierowaniem[v].empty())
            distZskierowaniem = *DistzSkierowaniem[v].begin();

        return distZskierowaniem + distPrzeciwnySkierowanie + 1;
    }

    inline void get_ans()
    {
        for (int i = N; i > 0; i--)
        {
            if (Warstwy[i].size() == 0)
                continue;

            pierwszaWarstwa = max(pierwszaWarstwa, i);
            VwWarstwie.clear();

            for (int w : Warstwy[i])
                VwWarstwie.insert(get_dist(w));

            for (int kandydat : Warstwy[i])
            {
                // usuń go z muliseta

                int dist = get_dist(kandydat);
                auto it = VwWarstwie.find(dist);
                VwWarstwie.erase(it);

                // sprawdz inne V w tej warstwie
                int best_score = 0;
                if (!VwWarstwie.empty())
                    best_score = *VwWarstwie.begin();

                best_score = max({best_score, i - 1, pierwszaWarstwa - i});

                // usun V z grafu zaaktualizuj jego sąsiadów i sprawdz czy nie istnieje scieżka większa niż best_score

                // napoczątku wszystkie V zgodne z Skierowaniem

                for (int somsiad : SomsiadzSkierowaniem[kandydat])
                {
                    auto itr = DistzSkierowaniem[somsiad].find(*DistzSkierowaniem[kandydat].begin() + 1);
                    DistzSkierowaniem[somsiad].erase(itr);

                    best_score = max(best_score, get_dist(somsiad));
                }

                // dodaj dystans ponownie
                for (int somsiad : SomsiadzSkierowaniem[kandydat])
                    DistzSkierowaniem[somsiad].insert(*DistzSkierowaniem[kandydat].begin() + 1);

                for (int somsiad : SomsiadprzeciwneSkierowanie[kandydat])
                {
                    auto itr = DistprzeciwnyDoSkierowania[somsiad].find(*DistprzeciwnyDoSkierowania[kandydat].begin() + 1);
                    DistprzeciwnyDoSkierowania[somsiad].erase(itr);

                    best_score = max(best_score, get_dist(somsiad));
                }

                // dodaj dystans ponownie
                for (int somsiad : SomsiadprzeciwneSkierowanie[kandydat])
                    DistprzeciwnyDoSkierowania[somsiad].insert(*DistprzeciwnyDoSkierowania[kandydat].begin() + 1);

                if (best_score < ans.first)
                {
                    ans.first = best_score;
                    ans.second = kandydat;
                }

                // dodaj go z powrotem
                VwWarstwie.insert(dist);
            }
        }
    }

    inline void solve()
    {
        read_data();
        toposort(STOdobreSkierowanie, SomsiadzSkierowaniem);
        bfs(STOdobreSkierowanie, SomsiadzSkierowaniem, DistzSkierowaniem);
        bfs(STOZleSkierowanie, SomsiadprzeciwneSkierowanie, DistprzeciwnyDoSkierowania);

        get_ans();

        cout << ans.second << ' ' << ans.first - 1 << '\n';
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