#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[200001];
vector<int> adj[200001];
vector<vector<int>> ans;

bool dfs(int x, int pre) {
	visited[x] = true;
	vector<int> curr;
	for (int i : adj[x]) {
		if (i != pre) {
			if (visited[i]) {  // non spanning tree edge
				if (x < i) { curr.push_back(i); }
			} else if (dfs(i, x)) {
				curr.push_back(i);  // spanning tree edge
			}
		}
	}

	for (int i = 0; i < curr.size() / 2; i++) {
		ans.push_back({curr[2 * i], x, curr[2 * i + 1]});
	}
	if (curr.size() % 2 == 0) { return true; }
	if (pre != -1) { ans.push_back({curr[curr.size() - 1], x, pre}); }
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) { dfs(i, -1); }
	}

	cout << ans.size() << "\n";
	for (auto a : ans) { cout << a[0] << " " << a[1] << " " << a[2] << "\n"; }
}