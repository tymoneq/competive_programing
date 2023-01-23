#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> Nums;
vector<long long> Pref;
int n;
inline bool valid(int val)
{
    long long sum = Pref[val];
    for (int i = val + 1; i < n; i++)
    {
        if (sum >= Nums[i].first)
            sum += Nums[i].first;
        else
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, lo, hi, mid, ans;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n;
        vector<int> Res;
        Pref.resize(n);
        Nums.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> Nums[i].first;
            Nums[i].second = i + 1;
        }
        sort(Nums.begin(), Nums.end());
        Pref[0] = Nums[0].first;
        for (int i = 1; i < n; i++)
            Pref[i] = Pref[i - 1] + Nums[i].first;
        lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (valid(mid))
                hi = mid - 1, ans = mid;
            else
                lo = mid + 1;
        }
        for (int i = ans; i < n; i++)
            Res.push_back(Nums[i].second);
        cout << Res.size() << "\n";
        sort(Res.begin(), Res.end());
        for (int w : Res)
            cout << w << ' ';

        cout << "\n";
    }
    return 0;
}