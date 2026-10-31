#include <bits/stdc++.h>
typedef long long ll;
const ll inf = 1e9 + 7;
using namespace std;

ll ans = 0;
ll n, k;

bool valid(ll subtree_size, ll depth) {
  if (depth > k)
    return false;
  if (subtree_size + k > n) {
    return false;
  }
  return true;
}

void solve() {
  ll depth = 1;
  ll left_size = 0;
  ll right_size = 0;
  ll mid_size = 0;
  ll mid = n;
  ll most_left = 1;
  ll first_right = n / 2 + 1;
  ll max_right = 1;

  while (depth < n) {
    depth *= 2;
    most_left *= 2;
    max_right = max_right * 2 + 1;
  }

  while (depth > 0) {
    if (valid(left_size, depth)) {
      ans += mid - most_left;
    }
    if (valid(mid_size, depth)) {
      ans += 1;
    }
    if (valid(right_size, depth) && first_right <= max_right) {
      ans += max_right - first_right + 1;
    }

    if (mid % 2 == 0) {
      mid = mid + 1;
      if (first_right <= max_right) {
        mid += right_size + 1;
      }
    } else if (mid % 2 == 1) {
      mid = mid + 1 + left_size + 1;
    }

    left_size = (left_size + 1) * 2;
    if (first_right <= max_right) {
      right_size = (right_size + 1) * 2;
      first_right /= 2;
    }

    most_left /= 2;
    mid /= 2;
    depth /= 2;
    max_right /= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  cout << ans << "\n";

  return 0;
}
