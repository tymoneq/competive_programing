#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int A[MAXN];
int B[MAXN];
int dp[MAXN][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, s, x;
  s = 0;
  x = 0;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> B[i];
  }

  dp[n][0] = A[n];
  dp[n][1] = B[n];
  for (int i = n - 1; i > 0; i--) {
        


  }
  return 0;
}