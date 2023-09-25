#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 1.5e5 + 10;
ll Cows[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> Cows[i];
    cin >> q;
    long long res = 0;
    for (int i = 0; i < q; i++)
    {
        res = 0;
        cin >> a >> b;
        vector<long long> C;
        for (int j = 1; j <= n; j++)
        {
            if (j == a)
                C.push_back(b);
            else
                C.push_back(Cows[j]);
        }
        sort(C.begin(), C.end());
        for (ll j = 0; j < C.size(); j++)
            res += C[j] * (j + 1);

        cout << res << "\n";
    }
    return 0;
}