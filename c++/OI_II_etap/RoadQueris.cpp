#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
pair<int, int> Edge[M];
int R[M], Sajz[M];
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void onion(int a, int b)
{
    if (fint(a) == fint(b))
        return;
    if (Sajz[fint(a)] > Sajz[fint(b)])
        swap(a, b);
    Sajz[fint(b)] += Sajz[fint(a)];
    Sajz[fint(a)] = 0;
    R[fint(a)] = fint(b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
        cin >> Edge[i].first >> Edge[i].second;

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        int ind = 0;
        for (int j = 1; j <= n; j++)
            R[j] = j, Sajz[j] = 1;
        while (fint(a) != fint(b) && ind < m)
        {
            onion(Edge[ind].first, Edge[ind].second);
            ind++;
        }
        if (fint(a) == fint(b))
            cout << ind << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}