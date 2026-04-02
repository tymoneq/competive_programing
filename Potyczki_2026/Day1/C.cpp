#include <bits/stdc++.h>
#include <cstdint>
#include <sys/types.h>

using namespace std;

pair<uint32_t, uint32_t> A[5] = {
    {23, 24}, {24, 25}, {25, 26}, {26, 27}, {27, 29}};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  uint32_t x, d, h, m;
  cin >> x >> d >> h >> m;

  x--;

  uint32_t cost = 0;
  if (x == 4 && (d < 29 || (d == 29 && h < 2)))
    cost = 60;
  uint32_t end_day = A[x].second;

  uint32_t res = 0;

  //  dodaj minuty

  res += 60 - m;
  h++;
  res += (24 - h) * 60;
  d++;
  if (d <= end_day)
    res += ((end_day - d) + 1) * 24 * 60;

  res -= cost;

  cout << res << "\n";

  return 0;
}
