#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, M, S;
  cin >> H >> M >> S;

  if (H < 2) {
    std::cout << "-";
  } else if (H >= 3) {
    std::cout << "+";
  } else if (H == 2 && M == 30 && S == 0) {
    std::cout << "=";
  } else if (H == 2 && M < 30)
    std::cout << "-";
  else {
    std::cout << "+";
  }

  return 0;
}
