#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;

int p[N], cnt[N], mp[N];

int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}

int main()
{
    int t, n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        bool f = true;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            p[i] = i, cnt[i] = 1, mp[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a]++, mp[b]++;
            int f1 = find(a), f2 = find(b);
            if (f1 != f2)
            {
                p[f1] = f2;
                cnt[f2] += cnt[f1];
                cnt[f1] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] % 2 == 1)
            {
                f = 0;
            }
            if (mp[i] > 2)
            {
                f = 0;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
}