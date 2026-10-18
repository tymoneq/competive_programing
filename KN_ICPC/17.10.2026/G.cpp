#include <array>
#include <bits/stdc++.h>
#include <cmath>
#include <ios>
#include <iostream>

struct Mission {
  int dif;
  int dur;
};
constexpr int MAX_K = 1e6 + 10;
std::array<Mission, MAX_K> Res;

int main() {

  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;

  std::cin >> n;
  int k = 0;

  int B = std::ceil(std::cbrt(static_cast<double>(n)));
  int S = 1;

  while (S < n) {
    int next_S = S * B;

    for (int j = B - 1; j >= 1; j--) {
      int offset = j * S;

      for (int val = n - offset; val > 0; val -= next_S) {

        int dur = S;

        if (val + dur > n) {
          dur = n - val;
        }

        Res[k] = {val, dur};
        k++;
      }
    }
    S = next_S;
  }
  std::cout << k << "\n";
  for (int i = 0; i < k; i++) {
    std::cout << Res[i].dif << ' ' << Res[i].dur << "\n";
  }

  return 0;
}