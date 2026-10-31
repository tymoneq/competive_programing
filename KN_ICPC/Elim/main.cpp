#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  ll x, y;
  cin >> x >> y;

  ll gcd_1 = gcd(x, y);
  ll lcm_1 = x * y / gcd_1;

  ll res = 0;
  ll val = lcm_1 / gcd_1;
 
  

  cout << 1 << " " << val << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
