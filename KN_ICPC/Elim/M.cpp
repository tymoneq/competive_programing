#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define NoMessage "Time to play Genshin Impact, Teacher Rice!"

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> Ans(n + 1);
  set<string> Rice;
  vector<vector<string>> Groups(n + 1);
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    Groups[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> Groups[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {

    for (int j = 0; j < Groups[i].size(); j++) {

      bool valid = false;
      for (int k = 0; k < int(Groups[i][j].size() - 2; k++) {
        if (Groups[i][j][k] == 'b' && Groups[i][j][k + 1] == 'i' &&
            Groups[i][j][k + 2] == 'e') {
          valid = true;
          break;
        }
      }
      if (valid && !Rice.count(Groups[i][j])) {
        Rice.insert(Groups[i][j]);
        Ans[i].push_back(j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {

    if (Ans[i].empty()) {
      cout << NoMessage << "\n";
      continue;
    }
    for (int w : Ans[i]) {
      cout << Groups[i][w] << "\n";
    }
  }
  return 0;
}
