#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N;
    vector<vector<int>> Drzewo;
    vector<int> Sajz;
    vector<int> Parent;
    unordered_map<int, vector<int>> Type;
    vector<char> Ans;
    vector<bool> Off;

public:
    inline void read_data()
    {
        cin >> N;

        Drzewo.resize(N + 1);
        Sajz.resize(N + 1);
        Parent.resize(N + 1);
        Ans.resize(N + 1);
        Off.resize(N + 1);

        FOR(i, N, 1)
        {
            int from, to;
            cin >> from >> to;

            Drzewo[from].push_back(to);
            Drzewo[to].push_back(from);
        }
    }

    inline void sajz_dfs(int v, int p)
    {
        Sajz[v] = 1;
        Parent[v] = p;

        for (int w : Drzewo[v])
            if (w != p && !Off[w])
            {
                sajz_dfs(w, v);
                Sajz[v] += Sajz[w];
            }
    }

    inline int find_centroid(int v, const int &tree_sajz)
    {

        for (int w : Drzewo[v])
        {
            if (Off[w])
                continue;

            if (Parent[v] == w && tree_sajz - Sajz[v] > (tree_sajz + 1) / 2)
                return find_centroid(w, tree_sajz);

            if (Parent[v] != w && Sajz[w] > (tree_sajz + 1) / 2)
                return find_centroid(w, tree_sajz);
        }

        return v;
    }

    inline void centroid_decomposition(int v, int tree_sajz, int prev_type)
    {
        sajz_dfs(v, v);

        int centr = find_centroid(v, tree_sajz);

        // check if tree is valid

        Type[prev_type + 1].push_back(centr);

        Off[centr] = true;

        for (int w : Drzewo[centr])
        {
            if (Off[w])
                continue;

            if (Parent[v] == w && tree_sajz - Sajz[v] >= (tree_sajz + 1) / 2)
            {
                Off[w] = true;
                Type[prev_type + 2].push_back(w);
                int new_tree_sajz = tree_sajz - Sajz[centr];
                centroid_decomposition(w, new_tree_sajz, prev_type + 2);
            }
            if (Parent[v] != w && Sajz[w] >= (tree_sajz + 1) / 2)
            {
                Off[w] = true;
                Type[prev_type + 2].push_back(w);
                int new_tree_sajz = Sajz[w];
                centroid_decomposition(w, new_tree_sajz, prev_type + 2);
            }
        }

        for (int w : Drzewo[centr])
        {
            if (Off[w])
                continue;

            if (Parent[v] == w)
            {
                int new_tree_sajz = tree_sajz - Sajz[centr];
                centroid_decomposition(w, new_tree_sajz, prev_type + 1);
            }

            if (Parent[v] != w)
            {
                int new_tree_sajz = Sajz[w];
                centroid_decomposition(w, new_tree_sajz, prev_type + 1);
            }
        }
    }

    inline void solve()
    {
        read_data();

        centroid_decomposition(1, N, -1);

        if (Type.size() > 26)
        {
            cout << "Impossible!\n";
            return;
        }

        for (auto w : Type)
            for (int v : w.second)
                Ans[v] = 'A' + w.first;

        FOR(i, N + 1, 1)
        cout << Ans[i] << ' ';

        cout << '\n';
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