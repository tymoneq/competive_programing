#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll INF = 1e18;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    int c;
    cin >> n >> k >> c;
    ll ind = 0;
    ll num = 0;
    while (ind < k)
    {
        num++;
        if (gcd(num, n) == 1)
            ind++;
    }
    cout << num << " ";
    while (ind < k + c - 1)
    {
        num++;
        if (gcd(num, n) == 1)
        {
            cout << num << " ";
            ind++;
        }
    }

    return 0;
}