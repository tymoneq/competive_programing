#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  ll h; cin >> h;
  vector<pair<ll, ll>> seg(n);
  for(int i = 0; i < n; i++) cin >> seg[i].first >> seg[i].second;
  vector<ll> prefH(n, 0), pref(n + 1, 0);
  for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + seg[i - 1].second - seg[i - 1].first;
  for(int i = 1; i < n; i++){
    prefH[i] = prefH[i - 1] + seg[i].first - seg[i - 1].second;
  }
  ll res = 0;
  int najd = n - 1;
  for(int i = n - 1; i >= 0; i--){
    if(i == n - 1){
        res = max(res, seg[i].second - seg[i].first + h);
    }
    else{
        while(najd > i && h - (prefH[najd] - prefH[i]) <= 0) najd--;
      //  cout << najd << " " << prefH[najd] << endl;
        res = max(res, pref[najd + 1] - pref[i] + h);
    }
  }
  cout << res << "\n";
  
  return 0;
}
