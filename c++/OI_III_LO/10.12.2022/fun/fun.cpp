#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b;
    long long res = 0;
    cin >> t;
    int n = pow(10, 6);
    vector<int> v;
    vector<int> how_many(n + 1);
    vector<bool> Table(n + 1);
    for (int i = 2; i * i <= n; i++)
        if (!Table[i])
            for (int j = i * i; j <= n; j += i)
                Table[j] = 1;
    for (int i = 2; i <= n; i++)
        if (!Table[i])
            v.push_back(i);

    for (auto el : v)
        for (int j = el; j <= n; j += el)
            how_many[j] += 1;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            res += how_many[j];
        cout << res << "\n";
        res = 0;
    }
}