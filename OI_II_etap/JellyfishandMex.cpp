#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t, a, mn, res;
    map<int, int> Occ, Cost;
    cin >> t;
    while (t--)
    {
        cin >> n;
        res = 0;
        vector<int> A(n);
        for (int &a : A)
        {
            cin >> a;
            Occ[a]++;
        }

        sort(A.begin(), A.end());
        mn = A[n - 1] + 1;
        if (A[0] != 0)
            mn = 0;
        else
            for (int i = 0; i < n - 1; i++)
                if (A[i] != A[i + 1] && A[i + 1] - 1 != A[i])
                {
                    mn = A[i] + 1;
                    break;
                }

        while (n > 0 && mn > 0)
        {
            for (auto el : Occ)
                if (el.second != 0 && el.first < mn)
                    Cost[el.first] = (el.second - 1) * mn + min(el.first, mn);

            int cost_mn = numeric_limits<int>::max();
            for (auto el : Cost)
                cost_mn = min(cost_mn, el.second);

            for (auto el : Cost)
                if (el.second == cost_mn)
                {
                    res += el.second;
                    mn = min(el.first, mn);
                    n -= Occ[el.first];
                    Occ[el.first] = 0;
                    break;
                }

            Cost.clear();
        }

        cout << res << "\n";

        Occ.clear(), Cost.clear();
    }

    return 0;
}