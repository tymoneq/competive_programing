#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, L, current_v, best_score;
    vector<vector<int>> Drzewo;
    vector<int> Depth;
    vector<bool> Off;
    vector<int> Parent;

    int ans = 0;

public:
    inline void read_data()
    {
        cin >> N >> L;
        Drzewo.resize(N + 1);
        Depth.resize(N + 1);
        Off.resize(N + 1);
        Parent.resize(N + 1);

        FOR(i, N, 1)
        {
            int a, b;
            cin >> a >> b;
            Drzewo[a].push_back(b);
            Drzewo[b].push_back(a);
        }
    }

    inline void depth_dfs(int v, int p)
    {
        Depth[v] = (Off[v] ? 0 : 1);
        Parent[v] = p;

        for (int w : Drzewo[v])
            if (w != p)
            {
                depth_dfs(w, v);
                Depth[v] = max(Depth[v], Depth[w] + (Off[v] ? 0 : 1));
            }
    }

    inline void calc_best_score(int v, int p)
    {
        if (best_score < Depth[v])
        {
            best_score = Depth[v];
            current_v = v;
        }

        vector<int> suma;

        for (int w : Drzewo[v])
            if (w != p)
                suma.push_back(Depth[w]);

        sort(suma.begin(), suma.end(), greater<int>());

        if (suma.size() > 1 && suma[0] + suma[1] + (Off[v] ? 0 : 1) > best_score)
        {
            best_score = suma[0] + suma[1];
            current_v = v;
        }

        for (int w : Drzewo[v])
            if (w != p)
                calc_best_score(w, v);
    }

    inline void upt(int v, int p)
    {
        Off[v] = true;
        int syn = 0;
        int mx = 0;

        for (int w : Drzewo[v])
            if (w != p && Depth[w] > mx)
            {
                syn = w;
                mx = Depth[w];
            }

        if (syn == 0)
            return;

        upt(syn, v);
    }

    inline void solve()
    {
        read_data();

        while (L--)
        {
            best_score = 0;
            depth_dfs(1, 1);
            calc_best_score(1, 1);
            ans += best_score;

            // sprawdz w jaki sposób
            if (Depth[current_v] == best_score)
                upt(current_v, Parent[current_v]);

            else
            {
                vector<pair<int, int>> suma;

                for (int w : Drzewo[current_v])
                    if (w != Parent[current_v])
                        suma.push_back({Depth[w], w});

                sort(suma.begin(), suma.end(), greater<pair<int, int>>());

                Off[current_v] = true;
                upt(suma[0].second, Parent[suma[0].second]);
                upt(suma[1].second, Parent[suma[1].second]);
            }
        }

        cout << ans << '\n';
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