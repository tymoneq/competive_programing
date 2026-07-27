#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    vector<int> A(4);
    for (int i = 0; i < 4; i++)
      cin >> A[i];
    sort(A.begin(), A.end());

    long long area = A[0] * A[2];
    cout << area << "\n";
  }
  return 0;
}