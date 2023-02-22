#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef unsigned int ui;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ui x, n, a;
    cin >> x >> n;
    multiset<ui> Sajz;
    ull res = 0;
    for (ui i = 0; i < n; i++)
    {
        cin >> a;
        Sajz.insert(a);
    }
    ui dist = 0;
    for (int i = 1; i < n; i++)
    {
        auto it = Sajz.begin();
        dist = *it;
        it++;
        dist += *it;
        res += dist;
        Sajz.insert(dist);
        Sajz.erase(it);
        Sajz.erase(Sajz.begin());
    }
    cout << res;
    return 0;
}