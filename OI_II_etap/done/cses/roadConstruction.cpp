#include <bits/stdc++.h>

using namespace std;
const int M = 1e5 + 10;
int R[M], Sajz[M];
int numOfComponents, mxsaiz;
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void join(int a, int b)
{
    if (fint(a) == fint(b))
        return;
    if (Sajz[a] > Sajz[b])
        swap(a, b);
    Sajz[fint(b)] += Sajz[fint(a)];
    mxsaiz = max(mxsaiz, Sajz[fint(b)]);
    numOfComponents--;
    Sajz[fint(a)];
    R[fint(a)] = fint(b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        R[i] = i;
        Sajz[i] = 1;
    }
    numOfComponents = n;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        join(a, b);
        cout << numOfComponents << ' ' << mxsaiz << "\n";
    }
    return 0;
}