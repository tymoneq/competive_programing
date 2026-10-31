#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n,k;

int subt(ll v){
    ll suma = 0;
    ll lv = v;
    while(2*lv <= n){
        lv*=2;
    }
    ll rv = v;
    while(true){
        if((2*rv) + 1<= n) rv = (rv *2) + 1;
        else if(2*rv <= n) rv *= 2;
        else break;
    }
    while(rv != v && lv != v){
        suma += rv - lv + 1;
        rv /= 2;
        lv /= 2;
    }
    return suma;
}
int ft(int level, ll v){
    if(n >= 2*v && level + 1 <= k && k <= n - subt(2*v)) 
        return ft(level + 1, 2*v);
    if(n >= 2*v + 1 && level + 1 <= k && k <= n - subt(2*v + 1)) 
        return ft(level + 1, 2*v + 1);
    return v;
}

int sd(int level, ll v){
    cout << level << " " << v << endl;
    if(n >= 2*v + 1 && level + 1 <= k && k <= n - subt(2*v + 1)) 
        return ft(level + 1, 2*v + 1);
    if(n >= 2*v && level + 1 <= k && k <= n - subt(2*v)) 
        return ft(level + 1, 2*v);
    return v;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;
  //cout << sd(1, 1) - ft(1, 1) + 1 << "\n";
  //cout << sd(1, 1) << " " << ft(1, 1);
  //cout << endl << subt(6) << endl;
  cout << sd(1,1);
  return 0;
}
