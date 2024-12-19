#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;

struct edge
{
    int to, weight;
};

class Brut
{
protected:
    vector<ll> DistFromBitek, DistFromBajtyna;
    set<int> TypyRestauracji;
    vector<vector<int>> IndexyRestauracjiTypu;
    int n, r, q;
    vector<vector<edge>> Bitowo;
    const ll INF = 1e17;

public:
    Brut(int _n, int _r)
    {
        this->n = _n;
        this->r = _r;

        DistFromBajtyna.resize(n + 1);
        DistFromBitek.resize(n + 1);
        Bitowo.resize(n + 1);
        IndexyRestauracjiTypu.resize(r + 1);
    }

    inline void dfs(int v, int p, vector<ll> &Dystanse)
    {
        for (auto w : Bitowo[v])
            if (w.to != p)
            {
                Dystanse[w.to] = Dystanse[v] + w.weight;
                dfs(w.to, v, Dystanse);
            }
    }

    inline void solve()
    {

        FOR(i, n + 1, 1)
        {
            int a;
            cin >> a;
            IndexyRestauracjiTypu[a].push_back(i);
            TypyRestauracji.insert(a);
        }

        FOR(i, n - 1, 0)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            Bitowo[from].push_back({to, weight});
            Bitowo[to].push_back({from, weight});
        }

        cin >> q;

        while (q--)
        {
            int przystanekBitka, przystanekBajtyny, typRestauracji;
            cin >> przystanekBitka >> przystanekBajtyny >> typRestauracji;

            if (!TypyRestauracji.count(typRestauracji))
            {
                cout << -1 << '\n';
                continue;
            }

            dfs(przystanekBitka, przystanekBitka, DistFromBitek);
            dfs(przystanekBajtyny, przystanekBajtyny, DistFromBajtyna);

            ll minimalnyKoszt = INF;

            for (int restauracja : IndexyRestauracjiTypu[typRestauracji])
            {
                minimalnyKoszt = min(minimalnyKoszt, DistFromBajtyna[restauracja] + DistFromBitek[restauracja]);
            }

            FOR(i, n + 1, 1)
            {
                DistFromBajtyna[i] = 0;
                DistFromBitek[i] = 0;
            }

            cout << minimalnyKoszt << '\n';
        }
    }
};

class LCA
{

protected:
    int n;
    vector<vector<edge>> Bitowo;
    vector<int> PreOrder, Parent, Depth;
    vector<ll> PrefSum;
    vector<vector<int>> BinaryLifting;
    const int MAXLOG = 19;

public:
    inline void dfs(int v, int p, int &cnt)
    {
        assert(p != -1), assert(v != -1);

        PreOrder[v] = cnt;
        Depth[v] = Depth[p] + 1;
        Parent[v] = p;
        BinaryLifting[v][0] = p;

        if (v != 1)
            FOR(i, MAXLOG, 1)
            {
                BinaryLifting[v][i] = BinaryLifting[BinaryLifting[v][i - 1]][i - 1];
            }
        for (auto w : Bitowo[v])
            if (w.to != p)
            {
                PrefSum.push_back(PrefSum[PreOrder[v]] + w.weight);
                cnt++;
                dfs(w.to, v, cnt);
            }
    }
    LCA(vector<vector<edge>> _Bitowo, int _n)
    {

        this->Bitowo = _Bitowo;
        this->n = _n;
        PreOrder.resize(n + 1);
        Parent.resize(n + 1);
        Depth.resize(n + 1);
        PrefSum.push_back(0);
        Depth[0] = -1;
        BinaryLifting.resize(n + 1, vector<int>(MAXLOG + 1, 0));
        FOR(i, MAXLOG, 0)
            BinaryLifting[1][i] = 0;
        
        int cnt = 0;
        Depth[0] = -1;
        dfs(1, 0, cnt);
    }

    inline int getLca(int leftVertex, int rightVertex)
    {
        if (leftVertex == rightVertex)
            return leftVertex;

        // I want leftVertex to be lower than right one
        if (Depth[leftVertex] > Depth[rightVertex])
            swap(leftVertex, rightVertex);

        for (int i = MAXLOG - 1; i >= 0; i--)
            if (BinaryLifting[leftVertex][i] != -1 && Depth[BinaryLifting[leftVertex][i]] <= Depth[rightVertex])
                leftVertex = BinaryLifting[leftVertex][i];

        if (leftVertex == rightVertex)
            return leftVertex;

        for (int i = MAXLOG - 1; i >= 0; i--)
            if (BinaryLifting[leftVertex][i] != -1 && BinaryLifting[rightVertex][i] != -1 && (BinaryLifting[rightVertex][i] != BinaryLifting[leftVertex][i]))
            {
                leftVertex = BinaryLifting[leftVertex][i];
                rightVertex = BinaryLifting[rightVertex][i];
            }

        return BinaryLifting[leftVertex][0];
    }

    inline ll calculate_path(int _pozycjaBitka, int _pozycjaBajtyny)
    {
        int lca_bitek_restauracja = getLca(_pozycjaBitka, _pozycjaBajtyny);

        ll ans = PrefSum[PreOrder[_pozycjaBitka]] + PrefSum[PreOrder[_pozycjaBajtyny]] - (2 * PrefSum[PreOrder[lca_bitek_restauracja]]);

        return ans;
    }
};

class SolveWhenREqualsTo1
{
protected:
    int n, r, q;
    vector<vector<edge>> Bitowo;
    const ll INF = 1e17;

public:
    SolveWhenREqualsTo1(int _n, int _r)
    {
        this->n = _n;
        this->r = _r;
        Bitowo.resize(n + 1);
    }

    inline void solve()
    {

        FOR(i, n, 0)
        {
            int a;
            cin >> a;
        }

        FOR(i, n - 1, 0)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            Bitowo[from].push_back({to, weight});
            Bitowo[to].push_back({from, weight});
        }
        cin >> q;
        LCA lca(Bitowo, n);
        while (q--)
        {
            int przystanekBitka, przystanekBajtyny, typRestauracji;
            cin >> przystanekBitka >> przystanekBajtyny >> typRestauracji;

            if (typRestauracji != 1)
            {
                cout << -1 << '\n';
                continue;
            }

            cout << lca.calculate_path(przystanekBitka, przystanekBajtyny) << '\n';
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r;
    cin >> n >> r;

    if (r != 1)
    {
        Brut brut(n, r);
        brut.solve();
    }
    else if (r == 1)
    {
        SolveWhenREqualsTo1 solution(n, r);
        solution.solve();
    }

    return 0;
}