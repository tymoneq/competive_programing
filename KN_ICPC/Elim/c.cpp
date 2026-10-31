#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  cout << x[(n - 1)/2] << " " << y[(n - 1)/2];
  
  return 0;
}
