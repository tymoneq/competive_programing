#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, M;
    vector<vector<int>> Graf;
    vector<bool> Vis;
    vector<int> STO;
    int ans = 1;
    map<int, set<int>> Stopnie;
    queue<int> to_remove;

public:
    inline void read_data()
    {
        cin >> N >> M;
        Graf.resize(N + 1);
        Vis.resize(N + 1);

        STO.resize(N + 1);

        FOR(i, M, 0)
        {
            int a, b;
            cin >> a >> b;
            STO[a]++;
            STO[b]++;
            Graf[a].push_back(b);
            Graf[b].push_back(a);
        }
    }
    inline void dfs(int v, int &sajz, const int minSto)
    {
        Vis[v] = 1;
        sajz++;
        for (int w : Graf[v])
            if (!Vis[w] && STO[w] >= minSto)
                dfs(w, sajz, minSto);
    }

    inline void remove_vertexes(int vertex, int i)
    {
        for (int somsiad : Graf[vertex])
        {
            if (STO[somsiad] <= i)
                continue;

            Stopnie[STO[somsiad]].erase(somsiad);
            STO[somsiad]--;

            if (STO[somsiad] == i)
                to_remove.push(somsiad);
            else
                Stopnie[STO[somsiad]].insert(somsiad);
        }
    }

    inline void solve()
    {
        read_data();

        FOR(i, N + 1, 1)
        Stopnie[STO[i]].insert(i);

        for (int i = 1; i * i < M; i++)
        {
            if (Stopnie[i].empty())
                continue;

            FOR(j, N + 1, 1)
            Vis[j] = 0;

            int mxSajze = 0;

            FOR(j, N + 1, 1)
            {
                if (Vis[j] || STO[j] < i)
                    continue;

                int sajz = 0;
                dfs(j, sajz, i);

                mxSajze = max(sajz, mxSajze);
            }

            ans = max(ans, mxSajze * i);

            for (int vertex : Stopnie[i])
                remove_vertexes(vertex, i);

            while (!to_remove.empty())
            {
                int vertex = to_remove.front();
                to_remove.pop();
                remove_vertexes(vertex, i);
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
