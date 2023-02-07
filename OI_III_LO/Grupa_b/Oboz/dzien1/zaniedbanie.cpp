#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Tab[12];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("zan0.in", "r", stdin);
    vector<string> V(M);
    vector<pair<int, int>> G(10);
    vector<int> H(10);
    for (int i = 0; i <= 9; i++)
        G[i].second = i;
    for (int i = 1; i <= 20000; i++)
    {
        cin >> V[i];
        G[V[i][0] - '0'].first += 1;
    }
    sort(G.begin(), G.end(), greater<pair<int, int>>());
    int ind = 1;
    for (int i = 0; i < G.size() - 1; i++)
    {
        H[G[i].second] = ind;
        ind++;
    }
    H[G[G.size() - 1].second] = 0;
    for (int i = 1; i <= 20000; i++)
    {
        for (auto w : V[i])
            cout << H[w - '0'];
        cout << "\n";
    }

    return 0;
}