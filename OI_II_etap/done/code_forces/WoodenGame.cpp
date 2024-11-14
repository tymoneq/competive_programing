#include <bits/stdc++.h>

using namespace std;

inline vector<int> toBinary(int n)
{
    vector<int> res;

    while (n > 0)
    {
        if (n % 2 == 1)
            res.push_back(1);
        else
            res.push_back(0);
        n /= 2;
    }
    return res;
}

inline void solve()
{
    int n, k;
    cin >> k;
    vector<vector<int>> trees(k);

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> n;
        trees[i] = toBinary(n);
        for (int j = 2; j <= n; j++)
            cin >> a;
    }
    int res = 0;
    int mxIterations = 0;
    for (int i = 0; i < k; i++)
        mxIterations = max(mxIterations, (int)trees[i].size());

    for (int i = 0; i < mxIterations; i++)
    {
        bool oneBit = 0, twoBits = 0;
        for (auto w : trees)
        {
            if (w.size() <= i)
                continue;

            if (w[i] == 1)
            {
                if (!oneBit)
                    oneBit = 1;
                else
                {
                    twoBits = 1;
                    break;
                }
            }
        }
        if (oneBit && !twoBits)
            res = (1 << i) | res;

        else if (twoBits)
        {
            res = (1 << i);
            if (i != 0)
                res |= (1 << i) - 1;
        }
    }
    cout << res << "\n";
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