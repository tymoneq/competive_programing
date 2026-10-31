#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m, k, ans = 0, q;
map<pair<ll, ll>, ll> res;
ll max_pw2;
ll calc_sz(ll x, ll pow2) {
      while (x * 2 + 1 <= (1LL << max_pw2)) {
        x = (x * 2 + 1);
      }
      ll odj = max(x - n, 0LL);
      odj = min(odj, (1LL << pow2));
      ll sz = 2 * (1LL << pow2) - 1;
      sz -= odj;
      return sz - 1;
}
ll rec(ll x, ll lev, ll sz, ll pow2) {
       if (res.find({lev, sz}) != res.end()) {
             return res[{lev, sz}];
       }
       ll resl = 0, resr = 0;
       if (x * 2 <= n) {
           ll szl = calc_sz(x * 2, pow2 - 1);
           resl = rec(x * 2, lev + 1, szl, pow2 - 1);
       }
       if (x * 2 + 1 <= n) {
           ll szr = calc_sz(x * 2 + 1, pow2 - 1);
           resr = rec(x * 2 + 1, lev + 1, szr, pow2 - 1);
       }
       ll good = 0;
       if (n - sz >= k && lev <= k) good = 1;
       return res[{lev, sz}] = resl + resr + good;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  ll pow2 = 0;
  while ((1LL << (pow2 + 1)) <= n) pow2++;
  max_pw2 = pow2 + 1;
  ans = rec(1, 1, n - 1, pow2);
  cout << ans;
}
