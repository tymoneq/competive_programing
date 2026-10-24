#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  map<int, int> Val = {{0, 0}, {1, 5}, {2, 1}, {3, 6}, {4, 2},
                       {5, 7}, {6, 3}, {7, 8}, {8, 4}};

  int n;
  cin >> n;
  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    cin >> ans[i];
    ans[i] = Val[ans[i]];
  }

  for (auto w : ans)
    cout << w << " ";

  cout << "\n";

  return 0;
}