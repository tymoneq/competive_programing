#include <bits/stdc++.h>

using namespace std;



void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    d[x]++;
    d[y]++;
  }
  sort(d.begin(), d.end());
  if (d[0] == 0)
    cout << "Brain Melt\n";
  else if (d[n - 1] == n - 1 && d[n - 2] == 1)
    cout << 2 << "\n";
  else
    cout << "Many\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
