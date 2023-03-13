#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, n, p;
    cin >> x >> n;
    set<int> Lights;
    multiset<int> Distance;
    Distance.insert(x);
    Lights.insert(0), Lights.insert(x);
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        auto nextlights = Lights.upper_bound(p);
        auto prevlights = nextlights;
        prevlights--;
        int d = *nextlights - *prevlights;
        auto it = Distance.find(d);
        Distance.erase(it);
        int d1 = p - *prevlights, d2 = *nextlights - p;
        Lights.insert(p);
        Distance.insert(d1), Distance.insert(d2);
        cout << (*Distance.rbegin()) << " ";
    }
    return 0;
}