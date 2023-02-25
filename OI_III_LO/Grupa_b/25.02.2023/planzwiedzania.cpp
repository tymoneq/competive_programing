#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int Mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n1, n2, a;
    cin >> n1 >> n2;
    if (n1 > n2)
        swap(n1, n2);
    vector<int> N1(n1);
    unordered_map<int, vector<int>> N2;
    for (int i = 0; i < n1; i++)
        cin >> N1[i];
    for (int i = 0; i < n2; i++)
    {
        cin >> a;
        N2[a].push_back(i);
    }
    bool fint = 0, cor = 0;
    ull ans = 0;
    int ind;
    for (int k = n1; k > 0; k--)
    {
        ans = 0;
        if (fint)
            break;
        for (int i = 0; i <= n1 - k; i++)
        {
            cor = 1;
            ind = -1;
            for (int j = i; j < k; j++)
            {
                auto it = upper_bound(N2[N1[j]].begin(), N2[N1[j]].end(), ind);
                if (it == N2[N1[j]].end())
                {
                    cor = 0;
                    break;
                }
                ind = *it;
            }
            if (cor)
            {
                fint = 1;
                ans++;
                ans %= Mod;
            }
        }
    }
    cout << ans;
    return 0;
}