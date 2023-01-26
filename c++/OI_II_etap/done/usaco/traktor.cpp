#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Cell
{
    int i, j;
};
struct Edge
{
    Cell from, to;
    int cost;
};

const int MAX_N = 500;
int parent[MAX_N * MAX_N];
int comp_size[MAX_N * MAX_N]; // size of each component
int n;

int find(int a)
{
    if (a == parent[a])
        return a;

    return parent[a] = find(parent[a]);
}

bool unite(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a == root_b)
        return false;
    if (comp_size[root_a] > comp_size[root_b])
        swap(root_a, root_b);

    parent[root_a] = root_b;
    comp_size[root_b] += comp_size[root_a];
    return comp_size[root_b] >= (n * n + 1) / 2;
}
int field[MAX_N][MAX_N];
int main()
{
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> field[i][j];
    }
    for (int i = 0; i < n * n; i++)
    {
        parent[i] = i;
        comp_size[i] = 1;
    }
    vector<Edge> edges;
    int di[]{-1, 0, 1, 0}, dj[]{0, 1, 0, -1};
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            for (int d = 0; d < 4; d++)
            {
                Cell to = {row + di[d], col + dj[d]};
                // make sure the next cell is in bounds
                // and has a lower height to prevent adding an edge twice
                if (to.i >= 0 && to.i < n && to.j >= 0 && to.j < n && field[row][col] >= field[to.i][to.j])
                    edges.push_back({{row, col}, to, field[row][col] - field[to.i][to.j]});
            }

    // sort edges in increasing order of cost
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.cost < b.cost; });

    for (Edge edge : edges)
        // if the connected component covers at least half the cells
        if (unite(edge.from.i * n + edge.from.j, edge.to.i * n + edge.to.j))
        {
            cout << edge.cost << endl;
            return 0;
        }
}
