#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, bool>>> adj(n);
	
	for (int i = 0; i < m; i++) {
		char type;
		int u, v;
		cin >> type >> u >> v;
		
		adj[--u].push_back({--v, type == 'S'});
		adj[v].push_back({u, type == 'S'});
	}

	int component_num = 0;
	bool impossible = false;
	vector<int> color(n, -1);

	for (int i = 0; i < n; i++) {
		// haven't visited this node yet.
		if (color[i] == -1) {
			component_num++;
			
			queue<pair<int, bool>> todo;
			todo.push({i, true});

			while (!todo.empty()) {
				// process next node
				pair<int, bool> nxt = todo.front();
				todo.pop();

				// set grass type for nxt.first
				color[nxt.first] = nxt.second;

				// iterate through adjacent nodes
				for (pair<int, bool> u : adj[nxt.first]) {
					bool type = u.second ? nxt.second : !nxt.second;
					
					// haven't visited
					if (color[u.first] == -1) {
						todo.push({u.first, type});
					// creates a contradiction
					} else if (color[u.first] == !type) {
						impossible = true;
						break;
					}
				}
			}
		}
	}


	if (impossible) {
		cout << 0 << endl;
	} else {
		// 2^component_num in binary is 1, followed by component_num zeros.
		cout << 1;
		for (int i = 0; i < component_num; i++) {
			cout << 0;
		}
		cout << endl;
	}
}