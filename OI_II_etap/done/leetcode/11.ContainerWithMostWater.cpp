#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int calcRes(vector<int> &height) {
  const int HEIGHT = 10005;

  int n = height.size();

  array<int, HEIGHT> right;
  array<int, HEIGHT> right_max;

  for (int i = 0; i < HEIGHT; i++)
    right[i] = 0;

  long long res = 0;

  long long right_res = 0;
  long long min_height;

  for (int i = 0; i < n; i++)
    right[height[i]] = i + 1;

  right_max[HEIGHT - 1] = right[HEIGHT - 1];

  for (int i = HEIGHT - 2; i >= 0; i--)
    right_max[i] = max(right_max[i + 1], right[i]);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < height[i]; j++) {
      right_res = 0;
      min_height = j;

      right_res = min_height * (right[j] - (i + 1));

      res = max(res, right_res);
    }
    right_res = height[i] * (right_max[height[i]] - (i + 1));
    res = max(res, right_res);
  }

  return res;
}

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  int res = 0;
  res = calcRes(height);

  cout << res << "\n";

  return 0;
}