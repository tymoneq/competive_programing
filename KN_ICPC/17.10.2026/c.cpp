#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;

void trivia(int n, int m) {
  set<vector<int>> A;
  vector<int> buf(m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> buf[j];
    }
    A.insert(buf);
  }

  for (auto &el : A) {
    for (auto w : el) {
      cout << w << " ";
    }
  }
  cout << "\n";
}

void solve() {

  int n, m;
  cin >> n >> m;

  if (n % 2 == 0) {
    trivia(n, m);
    return;
  }

  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> A[i][j];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}