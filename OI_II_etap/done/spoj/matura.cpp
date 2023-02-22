#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2023;
struct ciong
{
    int l, r, dl;
};
inline bool sortoo(ciong &lhs, ciong &rhs) { return lhs.dl > rhs.dl; }
int Sajz[M];
int main()
{
    freopen("dane3.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ciong> V(M);
    for (int i = 0; i < M; i++)
    {
        cin >> V[i].l >> V[i].r;
        V[i].dl = V[i].r - V[i].l + 1;
    }
    sort(V.begin(), V.end(), sortoo);
    Sajz[M - 1] = 1;
    int mx;
    for (int i = M - 2; i >= 0; i--)
    {
        mx = 0;
        for (int j = i + 1; j < M; j++)
            if (V[i].l <= V[j].l && V[j].r <= V[i].r && mx < Sajz[j])
            {
                mx = Sajz[j];
            }
        Sajz[i] = mx + 1;
    }
    mx = 0;
    for (int i = 0; i < M; i++)
        mx = max(mx, Sajz[i]);
    cout << mx;
    return 0;
}