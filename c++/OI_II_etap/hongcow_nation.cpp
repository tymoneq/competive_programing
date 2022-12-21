#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 1e3 + 10;
vector<int> Graph[MAX_VAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<int> Goverments(k);
    for (int i = 0; i < k; i++)
        cin >> Goverments[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    // n*(n-3)/2 + n-x
    return 0;
}