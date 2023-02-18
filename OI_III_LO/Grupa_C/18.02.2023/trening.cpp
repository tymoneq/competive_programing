#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> V(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        V[i] = {a, b};
    }
    set<pair<int, int>> S;
    int x;
    for (int i = 0; i < n; i++)
    {
        x = gcd(abs(V[i].first), abs(V[i].second));
        a = V[i].first / x;
        b = V[i].second / x;
        if (!S.count({a, b}))
        {
            res++;
            S.insert({a, b});
        }
    }
    cout << res;
    return 0;
}