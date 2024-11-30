#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    // gp_hash_table<int, vector<int>> Cnt;
    map<int, vector<int>> Cnt;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i - 1];
        Cnt[A[i - 1]].push_back(i);
    }

    pair<int, int> res = {0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int w : Cnt[x - A[i]])
            if (w != i + 1)
            {
                res = {i + 1, w};
                break;
            }
        if (res.first != 0)
            break;
    }

    if (res.first == 0)
        cout << "IMPOSSIBLE\n";
    else
        cout << res.first << " " << res.second << "\n";

    return 0;
}