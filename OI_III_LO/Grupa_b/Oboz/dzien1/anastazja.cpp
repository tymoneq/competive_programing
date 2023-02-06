#include <bits/stdc++.h>
using namespace std;

constexpr int M = 100;
int R[M], Sajz[M];
unordered_map<int, int> MAP;
inline int fint(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = fint(R[a]);
}
inline void onion(int a, int b)
{
    if (fint(R[a]) == fint(b))
        return;
    if (Sajz[fint(R[a])] > Sajz[fint(R[b])])
        swap(a, b);
    MAP[Sajz[fint(b)]]--;
    MAP[Sajz[fint(a)]]--;
    Sajz[fint(R[b])] += Sajz[fint(a)];
    MAP[Sajz[fint(b)]]++;
    Sajz[fint(a)] = 0;
    R[fint(a)] = fint(R[b]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < M; i++)
        R[i] = i, Sajz[i] = 1;
    MAP[1] = 1e5;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            cin >> b >> c;
            onion(b, c);
        }
        else
        {
            cin >> b;
            cout << MAP[b] << "\n";
        }
    }
}