#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll M = 1e8 + 10;
constexpr ll INF = 1e18;
ll n, k;
bool valid(ll zakres, vector<ll> &Prime, vector<ll> &To_del)
{
    ll tmp = 0;
    for (ll w : Prime)
        tmp += zakres / w;
    ll addd = 0;
    for (ll w : To_del)
        addd += zakres / w;
    ll sum = zakres - tmp + addd;
    return k <= sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<ll> NotPrime;
    vector<ll> Todelete;
    ll tmp, N;
    int ind = 0;
    int c;
    cin >> n >> k >> c;
    N = n;
    set<int> Prime;
    for (int i = 2; i * i <= n; i++)
        if (!NotPrime.count(i))
        {
            if (n % i == 0)
                Prime.insert(i);
            for (int j = i + i; j <= min(n, M); j += i)
                NotPrime.insert(j);
        }
    vector<ll> Prim(Prime.size());
    for (int w : Prime)
        while (n % w == 0 && n != 1)
            n /= w;

    for (int w : Prime)
        Prim[ind] = w, ind++;
    if (n != 1 && !NotPrime.count(n))
        Prim.push_back(n);
    for (int i = 0; i < Prim.size(); i++)
        for (int j = i + 1; j < Prim.size(); j++)
        {
            tmp = Prim[i] / gcd(Prim[i], Prim[j]) * Prim[j];
            Todelete.push_back(tmp);
        }
    ll lo = 1, mid, hi = INF, ans;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid, Prim, Todelete))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << " ";
    ll num = ans;
    ind = 1;
    while (ind < c)
    {
        num++;
        if (gcd(num, N) == 1)
        {
            cout << num << " ";
            ind++;
        }
    }
    return 0;
}