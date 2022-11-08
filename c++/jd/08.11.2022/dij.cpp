#include <bits/stdc++.h>

using namespace std;
vector<int> waga;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
    int s, t;
    cin >> s >> t;
    vector<int> kopiec;
    make_heap(kopiec.begin(), kopiec.end());

    return 0;
}