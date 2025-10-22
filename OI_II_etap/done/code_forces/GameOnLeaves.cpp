#include <bits/stdc++.h>

using namespace std;

const string AYUSH = "Ayush";
const string ASHISH = "Ashish";

inline void dfs(int v, int p, const vector<vector<int>> &tree, vector<int> &Parent, vector<int> &Sto, vector<int> &Dist)
{
    if (p != v)
    {
        Parent[v] = p;
        Sto[p]++;
        Dist[v] = Dist[p] + 1;
    }

    for (int w : tree[v])
        if (w != p)
            dfs(w, v, tree, Parent, Sto, Dist);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int N, special;
        cin >> N >> special;

        vector<vector<int>> tree(N + 1);
        vector<int> Parent(N + 1), Sto(N + 1), Dist(N + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        if (N == 1)
        {
            cout << AYUSH << "\n";
            continue;
        }

        for (int i = 1; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        bool player = false; // false = AYUSH true = ASHISH

        // dfs
        int p = special;
        dfs(special, p, tree, Parent, Sto, Dist);

        for (int i = 1; i <= N; i++)
            if (Sto[i] == 0)
                pq.push({Dist[i], i});

        if (Sto[special] == 1)
        {
            cout << AYUSH << "\n";
            continue;
        }

        while (!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            Sto[Parent[v]]--;

            if (Sto[Parent[v]] == 0)
                pq.push({Dist[Parent[v]], Parent[v]});

            if (Parent[v] == special && Sto[special] == 1)
            {
                if (player)
                    cout << AYUSH << "\n";
                else
                    cout << ASHISH << "\n";
                break;
            }

            player ^= 1;
        }
    }

    return 0;
}