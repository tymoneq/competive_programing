#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    ll res;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        res = 0;
        for (int l = 0; l < s.size(); l++)
            for (int r = l + 1; r < s.size(); r++)
                for (int x = l; x <= r; x++)
                {
                    map<int, int> Sums;
                    Sums[s[x] - '0']++;
                    for (int y = x + 1; y <= r; y++)
                    {
                        Sums[s[y] - '0']++;
                        if (Sums[0] == Sums[1])
                        {
                            res++;
                            res %= mod;
                        }
                    }
                }
        cout << res << "\n";
    }

    return 0;
}