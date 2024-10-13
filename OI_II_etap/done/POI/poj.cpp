#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k, a;
    cin >> n >> k;
    vector<vector<pair<int, ll>>> ANS(n);
    multiset<pair<ll, int>> M;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        M.insert({a, i});
    }

    for (int i = 0; i < n; i++)
    {
        if (M.size() == 0)
            break;
        auto f = (M.begin());
        if (f->first > k)
        {
            ANS[i].push_back({f->second, k});
            ll w = f->first - k;
            M.insert({w, f->second});
            M.erase(f);
        }
        else if (f->first == k)
        {
            ANS[i].push_back({f->second, k});
            M.erase(f);
        }
        else
        {
            ANS[i].push_back({f->second, f->first});
            ll w = k - f->first;
            M.erase(f);
            if (M.size() == 0)
                break;
            auto it = M.lower_bound({w, 0});
            if (it != M.end())
            {
                ll v = it->first - w;
                ANS[i].push_back({it->second, w});
                M.insert({v, it->second});
                M.erase(it);
            }

            else
            {
                it--;
                ANS[i].push_back({it->second, it->first});
                M.erase(it);
            }
        }
    }

    if (M.size() == 0)
    {
        cout << "TAK\n";
        for (auto &e : ANS)
        {
            cout << e.size() << " ";
            for (auto &w : e)
                cout << w.first << " " << w.second << " ";

            cout << "\n";
        }
    }
    else
        cout << "NIE\n";
    return 0;
}