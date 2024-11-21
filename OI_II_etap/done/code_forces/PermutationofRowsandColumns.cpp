#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int K = 107, H = 881, MOD = 1e9 + 123;

inline ll pot(ll val, ll p)
{
    ll w = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
            w *= val;

        val *= val;
        p /= 2;
        val %= MOD;
        w %= MOD;
    }

    return w;
}

inline ll hashing(int val)
{
    ll hash = val += K;
    return pot(hash, H);
}

inline void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Grid[i][j];

    set<ll> RowsHash, ColumnHash;
    // hashing elements
    for (int i = 0; i < n; i++)
    {
        ll hash = 0;

        for (int j = 0; j < m; j++)
        {
            hash += hashing(Grid[i][j]);
            hash %= MOD;
        }
        RowsHash.insert(hash);
    }

    for (int j = 0; j < m; j++)
    {
        ll hash = 0;

        for (int i = 0; i < n; i++)
        {
            hash += hashing(Grid[i][j]);
            hash %= MOD;
        }
        ColumnHash.insert(hash);
    }

    // answering querry
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Grid[i][j];

    for (int i = 0; i < n; i++)
    {
        ll hash = 0;

        for (int j = 0; j < m; j++)
        {
            hash += hashing(Grid[i][j]);
            hash %= MOD;
        }
        if (RowsHash.count(hash))
            RowsHash.erase(hash);
    }

    for (int j = 0; j < m; j++)
    {
        ll hash = 0;

        for (int i = 0; i < n; i++)
        {
            hash += hashing(Grid[i][j]);
            hash %= MOD;
        }
        if (ColumnHash.count(hash))
            ColumnHash.erase(hash);
    }

    if (ColumnHash.size() == 0 && RowsHash.size() == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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