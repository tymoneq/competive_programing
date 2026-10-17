#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  const int max_N = 3 * n;
  vector<int> arr(n);
  for (int &i : arr)
    cin >> i;
  vector<int> ile(max_N + 7);
  for (int i : arr) {
    ile[i]++;
  }
  int res = 0;
  for (int i = 1; i <= max_N + 2; i++) {
    if (ile[i] > k) {
      res++;

      for (int j = max_N; j > 0; j--) {
        if (ile[j] > 1) {
          ile[j + 1] += ile[j] - 1;
          ile[j] = 1;
        }
      }
    }
  }

  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}