#include <bits/stdc++.h>

using namespace std;
vector<int> Dijkstra(int src, int n, vector<vector<pair<int, int>>> &Graf)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> Dist(n, numeric_limits<int>::max());
	pq.push(make_pair(0, src));
	Dist[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for (auto i = Graf[u].begin(); i != Graf[u].end(); i++)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (Dist[v] > Dist[u] + weight)
			{
				Dist[v] = Dist[u] + weight;
				pq.push(make_pair(Dist[v], v));
			}
		}
	}
	return Dist;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> Graf(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Graf[a].push_back(make_pair(b, c));
		Graf[b].push_back(make_pair(a, c));
	}
	vector<int> Distance = Dijkstra(0, n, Graf);
	for (int i = 0; i < n; i++)
		cout << i << " " << Distance[i] << "\n";
	
	return 0;
}