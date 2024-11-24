#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 110, BITSAJZ = 61;
vector<pair<int, int>> adj[N];
int R[N], Sajz[N], COST[N];
vector<int> BinRepresentation[N], BINCOST[N];

inline int fint(int a) { return R[a] == a ? a : fint(R[a]); }
inline void onion(int a, int b)
{
    a = fint(a), b = fint(b);
    if (Sajz[a] < Sajz[b])
        swap(a, b);
    R[b] = a;
    Sajz[a] += Sajz[b];
    Sajz[b] = 0;
}

inline void ChangeToBinary(ll num, int indx)
{
    vector<int> Binary;
    while (num > 0)
    {
        if (num % 2 == 1)
            Binary.push_back(1);
        else
            Binary.push_back(0);
        num /= 2;
    }

    for (unsigned int i = 0; i < Binary.size(); i++)
    {
        BinRepresentation[indx][i] = Binary[i];
        BINCOST[indx][i] = Binary[i];
    }
}
inline int newCost(int a, int b)
{
    a = fint(a), b = fint(b);
    if (Sajz[a] < Sajz[b])
        swap(a, b);

    vector<int> tmp(BITSAJZ, 0);

    for (int i = 0; i < BITSAJZ; i++)
        tmp[i] = BINCOST[a][i] | BINCOST[b][i];

    int cost = 0;
    for (int i = 0; i < BITSAJZ; i++)
        if (tmp[i] == 1)
            cost++;

    return cost;
}
inline void uptCost(int a, int b)
{
    a = fint(a), b = fint(b);
    if (Sajz[a] < Sajz[b])
        swap(a, b);

    for (int i = 0; i < BITSAJZ; i++)
        BINCOST[a][i] |= BINCOST[b][i];

    int cost = 0;
    for (int i = 0; i < BITSAJZ; i++)
        if (BINCOST[a][i] == 1)
            cost++;

    COST[b] = 0;
    COST[a] = cost;
}

inline void solve()
{
    int n;
    int mx = 0;
    cin >> n;
    vector<ll> A(n);
    for (ll &a : A)
        cin >> a;

    // setting structures
    for (int i = 0; i < n; i++)
    {
        R[i] = i, Sajz[i] = 1;
        adj[i].clear();
        BinRepresentation[i].clear();
        BinRepresentation[i].resize(BITSAJZ, 0);
        BINCOST[i].clear();
        BINCOST[i].resize(BITSAJZ, 0);
        COST[i] = 0;
    }

    // creating binary representation of a number
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            mx = 1;
        ChangeToBinary(A[i], i);
        uptCost(i, i);
    }

    // creating graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int cost = 0;
            for (int b = 0; b < BITSAJZ; b++)
                if (BinRepresentation[j][b] == 1 && BinRepresentation[i][b] != 1)
                    cost++;

            adj[i].push_back({j, cost});
        }

    // dsu
    bool newConnections = 1;

    while (newConnections)
    {
        newConnections = 0;
        for (int i = 0; i < n; i++)
            for (auto el : adj[i])
            {
                if (fint(el.first) == fint(i))
                    continue;
                int newScore = Sajz[fint(i)] + Sajz[fint(el.first)] - newCost(i, el.first);
                if (el.second == 0)
                {
                    newConnections = 1;
                    uptCost(i, el.first);
                    onion(i, el.first);
                    mx = max(mx, Sajz[fint(i)] - COST[fint(i)]);
                }
                else if (((Sajz[fint(i)] - COST[fint(i)] < newScore) && (newScore > Sajz[fint(el.first)] - COST[fint(el.first)])))
                {
                    newConnections = 1;
                    uptCost(i, el.first);
                    onion(i, el.first);
                    mx = max(mx, Sajz[fint(i)] - COST[fint(i)]);
                }
            }
    }

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}