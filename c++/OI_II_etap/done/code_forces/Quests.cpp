#include <bits/stdc++.h>

using namespace std;
vector<long long> Revards;
long long c, d;
inline bool validate(int days)
{
    long long sum = 0;
    int i = 0, D = 1, cycle = -1;
    while (D <= d)
    {
        if (i == Revards.size())
        {
            i = 0;
            if (days >= Revards.size())
            {
                D += days - Revards.size() + 1;
                cycle = -1;
                continue;
            }
        }
        else if (cycle == days)
            i = 0, cycle = -1;
        sum += Revards[i];
        i++;
        D++;
        cycle++;
    }

    return sum >= c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, n, lo, hi, mid;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> c >> d;
        Revards.clear();
        Revards.resize(n);
        for (int i = 0; i < n; i++)
            cin >> Revards[i];

        sort(Revards.begin(), Revards.end(), greater<int>());
        if (Revards[0] >= c || validate(d + 1))
            cout << "Infinity\n";
        else if (Revards[0] * d < c)
            cout << "Impossible\n";
        else
        {
            lo = 0, hi = d;
            while (lo < hi)
            {
                mid = lo + (hi - lo + 1) / 2;
                if (validate(mid))
                    lo = mid;
                else
                    hi = mid - 1;
            }
            cout << lo << "\n";
        }
    }
    return 0;
}