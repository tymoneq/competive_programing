#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<int> skill(n);
	for (int i = 0; i < n; i++) { cin >> skill[i]; }

	vector<int> dp(n, -1);
	for (int i = 0; i < n; i++) {
		// by not joining it to a team, the default value is just skill[i]
		int cur = skill[i];
		for (int j = i; j >= (i - k + 1) && ~j; j--) {
			cur = max(cur, skill[j]);
			/*
			 * update answer: dp[i] = max(dp[i],
			 * the skill of joining this cow to a team + all of the previous
			 * sums)
			 */
			if (j > 0) {
				dp[i] = max(dp[i], dp[j - 1] + (cur * (i - j + 1)));
			} else {
				dp[i] = max(dp[i], cur * (i - j + 1));
			}
		}
	}
	cout << dp[n - 1] << endl;
}