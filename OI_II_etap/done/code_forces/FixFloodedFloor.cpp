#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int n;
    vector<vector<char>> Array;
    const char Damaged = '.';
    const char Undamaged = '#';
    vector<set<int>> graph;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<int> STO;
    string ANS[3] = {"Unique", "Multiple", "None"};
    vector<bool> Vis;

public:
    inline void
    read_data()
    {
        cin >> n;
        Array.resize(2, vector<char>(n));
        FOR(i, 2, 0)
        FOR(j, n, 0)
        cin >> Array[i][j];
    }

    inline void add_edge(int v, int w)
    {
        graph[v].insert(w);
        graph[w].insert(v);
    }

    inline void construct_graph()
    {
        graph.resize(n + n);
        STO.resize(n + n);
        Vis.resize(n + n);
        FOR(i, 2, 0)
        FOR(j, n, 0)
        {
            if (Array[i][j] == Undamaged)
                continue;
            FOR(k, 4, 0)
            {
                if (i + dx[k] >= 2 || i + dx[k] < 0 || j + dy[k] < 0 || j + dy[k] >= n)
                    continue;

                if (Array[i + dx[k]][j + dy[k]] == Undamaged)
                    continue;

                if (i == 0 && dx[k] == 0)
                    add_edge(j, j + dy[k]);

                else if (i == 0 && dx[k] == 1)
                    add_edge(j, j + dy[k] + n);

                else if (i == 1 && dx[k] == 0)
                    add_edge(j + n, j + dy[k] + n);

                else if (i == 1 && dx[k] == -1)
                    add_edge(j + n, j + dy[k]);
            }
        }

        FOR(i, n + n, 0)
        STO[i] = graph[i].size();
    }

    inline void dfs(int v, int &cnt)
    {
        cnt++;
        Vis[v] = 1;
        for (int w : graph[v])
            if (!Vis[w])
                dfs(w, cnt);
    }

    inline string solve()
    {

        string ans = "Multiple";
        read_data();
        construct_graph();

        FOR(i, n + n, 0)
        {
            int x, y;
            if (i < n)
            {
                x = 0;
                y = i;
            }
            else
            {
                x = 1;
                y = i - n;
            }

            if (Array[x][y] == Undamaged)
                continue;
            if (!Vis[i])
            {

                int cnt = 0;
                dfs(i, cnt);

                if (cnt % 2 == 1)
                    ans = ANS[2];
            }
        }
        if (ans == ANS[2])
            return ans;

        set<int> Nieodwiedzone;
        FOR(i, n + n, 0)
        if (graph[i].size() > 0)
            Nieodwiedzone.insert(i);

        queue<int> toposort_kolejka;
        FOR(i, n + n, 0)
        if (STO[i] == 1)
            toposort_kolejka.push(i);

        while (!toposort_kolejka.empty())
        {
            int v = toposort_kolejka.front();
            toposort_kolejka.pop();

            if (Nieodwiedzone.count(v))
                Nieodwiedzone.erase(v);
            else
                continue;

            for (int w : graph[v])
            {
                if (Nieodwiedzone.count(w))
                    Nieodwiedzone.erase(w);
                    for (int u : graph[w])
                    {
                        STO[u]--;
                        if (STO[u] == 1)
                            toposort_kolejka.push(u);
                    }
                
            }
        }

        if (Nieodwiedzone.size() == 0)
            ans = ANS[0];

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        Solve solution;

        cout << solution.solve() << '\n';
    }

    return 0;
}