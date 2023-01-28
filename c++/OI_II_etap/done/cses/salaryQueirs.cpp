#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
int Nums[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b;
    cin >> n >> q;
    char z;
    map<int, int> Employes;
    for (int i = 1; i <= n; i++)
    {
        cin >> Nums[i];
        Employes[Nums[i]]++;
    }
    int res;
    for (int i = 0; i < q; i++)
    {
        cin >> z >> a >> b;
        if (z == '!')
        {
            Employes[Nums[a]]--;
            Nums[a] = b;
            Employes[b]++;
        }
        else if (z == '?')
        {
            res = 0;
            auto it = Employes.lower_bound(a);
            while (it->first <= b && it != Employes.end())
            {
                res += it->second;
                it++;
            }

            cout << res << "\n";
        }
    }
    return 0;
}