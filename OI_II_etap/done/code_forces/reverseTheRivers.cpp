#include <cstdio>
typedef long long l;

l ** arr;

int main() {
	l n, k, q; scanf("%lld %lld %lld", &n, &k, &q);
	
	arr = new l*[n];
	for (l i = 0; i < n; i++) arr[i] = new l[k];
	for (l i = 0; i < n; i++) for (l j = 0; j < k; j++) scanf("%lld", &arr[i][j]);
	
	for (l i = 1; i < n; i++) for (l j = 0; j < k; j++) arr[i][j] |= arr[i - 1][j];
	
	while (q--) {
		l m; scanf("%lld", &m);
		l left_pos = 0, right_pos = n - 1;
		while (m--) {
			l r, c; char o; scanf("%lld %c %lld", &r, &o, &c); r--;
			if (o == '<') {
				l le = -1, ri = n, mid;
				while (le + 1 != ri) {
					mid = (le + ri) / 2;
					if (arr[mid][r] < c) le = mid;
					else ri = mid;
				}
				if (le < right_pos) right_pos = le;
			} else {
				l le = -1, ri = n, mid;
				while (le + 1 != ri) {
					mid = (le + ri) / 2;
					if (arr[mid][r] <= c) le = mid;
					else ri = mid;
				}
				if (ri > left_pos) left_pos = ri;
			}
		}
		if (left_pos <= right_pos) printf("%lld\n", left_pos + 1);
		else printf("-1\n");
	}
}