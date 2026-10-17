#include <bits/stdc++.h>
#include <ios>

using namespace std;

constexpr int N = 2e5 + 10;
typedef long long ll;

struct edge {
  int to;
  int id;
};

vector<edge> G[N];
int Color[N];
int Parent[N];
ll ans;

void dfs(int v, int edge_id) {
  Color[v] = 1;

  for (auto &e : G[v]) {
    if (e.id == edge_id)
      continue;

    int u = e.to;

    if (Color[u] == 1) {
      ++ans;
    }

    if (Color[u] == 0) {
      Parent[u] = v;
      dfs(u, e.id);
    }
  }

  Color[v] = 2;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    G[a].emplace_back(edge{b, i});
    G[b].emplace_back(edge{a, i});
  }

  dfs(1, -1);
  cout << ans << "\n";

  return 0;
}