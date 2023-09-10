#include <bits/stdc++.h>

using namespace std;
constexpr int M = 5e5 + 10;
vector<int> Graph[M];
int STO[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        STO[a]++, STO[b]++;
    }
    vector<int> Vertex;
    for (int i = 1; i <= n; i++)
        if (STO[i] == 1)
            Vertex.push_back(i);
    cout << Vertex.size() - 2 << "\n";
    for (int i = 0; i < Vertex.size() - 2; i++)
        cout << Vertex[i] << ' ' << Vertex[i + 1] << "\n";
    return 0;
}