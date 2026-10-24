#include <bits/stdc++.h>

using namespace std;

int main() {

  int N, K;
  cin >> N >> K;

  if (K == 1) {
    cout << "S\n";
    return 0;
  }
  if (N == 2 && K % 2 == 1) {
    cout << "S\n";
    return 0;
  } else {
    cout << "N\n";
  }

  return 0;
}