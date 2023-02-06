#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 5e5 + 10, MOD = 1e9 + 7;
ll Pref[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll r = 1;
    for (int i = 0; i < n; i++)
        cin >> Pref[i];

    for (int i = 0; i < n; i++)
    {
        r = 1;
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                r *= Pref[j];
                r %= MOD;
            }
        cout << r << ' ';
    }
}