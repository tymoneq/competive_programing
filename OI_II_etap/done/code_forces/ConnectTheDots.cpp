#include <bits/stdc++.h>
using namespace std;

vector<int> R;

inline int fint(int a) { return R[a] == a ? a : R[a] = fint(R[a]); }

inline void onion(int a, int b)
{
    a = fint(R[a]);
    b = fint(R[b]);
    R[b] = R[a];
}

inline void solve()
{
    int n, m;
    cin >> n >> m;
    R.resize(n + 1);
    set<int> rep;
    vector<vector<int>> IleSkokow(11, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        R[i] = i;

    while (m--)
    {
        int a, d, k;
        cin >> a >> d >> k;
        IleSkokow[d][a]++;
        IleSkokow[d][a + k * d]--;
    }

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= n - i; j++)
        {
            if (IleSkokow[i][j] > 0)
                onion(j, j + i);
            IleSkokow[i][j + i] += IleSkokow[i][j];
        }

    for (int i = 1; i <= n; i++)
        rep.insert(fint(R[i]));

    cout << rep.size() << '\n';
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