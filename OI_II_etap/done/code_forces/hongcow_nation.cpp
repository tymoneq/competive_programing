#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 1e3 + 10;
vector<int> Tree[MAX_VAL];
bool Visited[MAX_VAL];
int sizee;
int Goverments[MAX_VAL];
inline void Find_cycle(int v)
{
    Visited[v] = 1;
    sizee++;
    for (int w : Tree[v])
        if (!Visited[w])
            Find_cycle(w);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, a, b, res = 0;
    cin >> n >> m >> k;
    vector<int> cp;
    for (int i = 0; i < k; i++)
    {
        cin >> Goverments[i];
        Goverments[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        --a;
        --b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    for (int i = 0; i < k; i++)
    {
        sizee = 0;
        Find_cycle(Goverments[i]);
        cp.push_back(sizee);
    }
    sort(cp.begin(), cp.end());
    for (int i = 0; i < n; i++)
        if (!Visited[i])
        {
            sizee = 0;
            Find_cycle(i);
            cp.back() += sizee;
        }
    for (int i = 0; i < cp.size(); i++)
        res += cp[i] * (cp[i] - 1) / 2;
    cout << res - m;
    return 0;
}