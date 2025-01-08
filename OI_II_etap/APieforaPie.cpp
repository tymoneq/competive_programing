#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

struct Cow
{
    int BessieTaste, ElsieTaste, id;
};

struct CowBessieComparator
{
    bool operator()(const Cow &lhs, const Cow &rhs) const
    {
        return lhs.BessieTaste < rhs.BessieTaste;
    }
};
struct CowElsieComparator
{
    bool operator()(const Cow &lhs, const Cow &rhs) const
    {
        return lhs.ElsieTaste < rhs.ElsieTaste;
    }
};

class Solve
{
protected:
    const int INF = 1e9 + 5;
    int N, D;
    vector<vector<int>> Graf;
    vector<int> Dist;
    vector<bool> Vis;
    vector<bool> OnTheGraph;
    set<Cow, CowElsieComparator> Bessie;
    set<Cow, CowBessieComparator> Elsie;
    queue<Cow> KolejkaTworzenieGrafu;
    queue<int> KolejkaBFS;

public:
    inline void add_to_que(int bessie, int elsie, int i)
    {
        KolejkaBFS.push(i);
        Dist[i] = 1;
        Vis[i] = true;
        OnTheGraph[i] = true;
        KolejkaTworzenieGrafu.push({bessie, elsie, i});
    }

    inline void read_data()
    {
        cin >> N >> D;

        OnTheGraph.resize(N + N + 2);
        Dist.resize((N + 1) * 2, INF);
        Vis.resize((N + 1) * 2);
        Graf.resize((N + 1) * 2);

        FOR(i, N + 1, 1)
        {
            int bessie, elsie;
            cin >> bessie >> elsie;

            if (elsie == 0)
                add_to_que(bessie, elsie, i);
            else
                Bessie.insert({bessie, elsie, i});
        }
        FOR(i, N + 1, 1)
        {
            int bessie, elsie;
            cin >> bessie >> elsie;

            if (bessie == 0)
                add_to_que(bessie, elsie, i + N);
            else
                Elsie.insert({bessie, elsie, i + N});
        }
    }

    inline void solve()
    {
        read_data();

        while (!KolejkaTworzenieGrafu.empty())
        {
            Cow krowa = KolejkaTworzenieGrafu.front();
            KolejkaTworzenieGrafu.pop();
            vector<Cow> To_erase;

            if (krowa.id > N)
            {
                auto PierwszaNajwieksza = Bessie.upper_bound(krowa);
                if (PierwszaNajwieksza == Bessie.begin())
                    continue;

                PierwszaNajwieksza--;

                while (PierwszaNajwieksza->ElsieTaste >= max((krowa.ElsieTaste - D), 1))
                {
                    if (OnTheGraph[PierwszaNajwieksza->id])
                        continue;

                    OnTheGraph[PierwszaNajwieksza->id] = true;

                    To_erase.push_back(*PierwszaNajwieksza);
                    Graf[krowa.id].push_back(PierwszaNajwieksza->id);
                    KolejkaTworzenieGrafu.push(*PierwszaNajwieksza);

                    if (PierwszaNajwieksza == Bessie.begin())
                        break;
                    PierwszaNajwieksza--;
                }

                // for (auto it : To_erase)
                //     Bessie.erase(it);
            }
            else
            {
                auto PierwszaNajwieksza = Elsie.upper_bound(krowa);
                if (PierwszaNajwieksza == Elsie.begin())
                    continue;

                PierwszaNajwieksza--;

                while (PierwszaNajwieksza->BessieTaste >= max((krowa.BessieTaste - D), 1))
                {
                    if (OnTheGraph[PierwszaNajwieksza->id])
                        continue;

                    OnTheGraph[PierwszaNajwieksza->id] = true;

                    To_erase.push_back(*PierwszaNajwieksza);
                    Graf[krowa.id].push_back(PierwszaNajwieksza->id);
                    KolejkaTworzenieGrafu.push(*PierwszaNajwieksza);

                    if (PierwszaNajwieksza == Elsie.begin())
                        break;

                    PierwszaNajwieksza--;
                }

                // for (auto it : To_erase)
                //     Elsie.erase(it);
            }
        }

        while (!KolejkaBFS.empty())
        {
            int v = KolejkaBFS.front();
            KolejkaBFS.pop();

            for (int w : Graf[v])
                if (!Vis[w])
                {
                    Dist[w] = Dist[v] + 1;
                    Vis[w] = true;
                    KolejkaBFS.push(w);
                }
        }

        FOR(i, N + 1, 1)
        {
            if (Dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << Dist[i] << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("2.in", "r", stdin);

    // freopen("piepie.in", "r", stdin);
    // freopen("piepie.out", "w", stdout);

    Solve solution;
    solution.solve();

    return 0;
}