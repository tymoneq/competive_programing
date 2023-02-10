#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5+10;
int Num[M], Val[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> Res;
    for (int i = 0; i < n; i++)
        cin >> Num[i];
    Val[0] = 1;
    int mx;
    for (int i = 1; i < n; i++)
    {
        mx = 0;
        for (int j = i - 1; j >= 0; j--)
            if (Num[j] < Num[i])
                mx = max(mx, Val[j]);

        Val[i] = mx + 1;
    }
    mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, Val[i]);
    unordered_map<int, int> m;
    for (int i = n - 1; i >= 0; i--)
    {
        if (m[Val[i] + 1] > Num[i])
        {
            Res.insert(Num[i]);
            m[Val[i]] = max(m[Val[i]], Num[i]);
        }
        else if (Val[i] == mx)
        {
            Res.insert(Num[i]);
            m[mx] = max(Num[i], m[mx]);
        }
    }
    cout << Res.size() << "\n";
    for (int w : Res)
        cout << w << " ";
    return 0;
}