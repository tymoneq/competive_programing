#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, bool> Prime;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N = 600851475143;

    ll res = 0;

    for (ll i = 2; i <= N; i++)
        if (!Prime[i])
        {
            res = i;
            for (ll j = i + i; j  <= N; j += i)
                Prime[j] = 1;
        }
    cout << res << "\n";
}