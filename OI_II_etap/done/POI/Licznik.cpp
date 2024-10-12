#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

inline bool sorto(pair<ull, ull> &lhs, pair<ull, ull> &rhs) { return lhs.first > rhs.first; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a;
    cin >> n >> m;
    vector<pair<ull, ull>> Licznik(n);

    for (auto &w : Licznik)
        cin >> w.first;
    for (auto &w : Licznik)
        cin >> w.second;

    sort(Licznik.begin(), Licznik.end(), sorto);
    multiset<ull> M;
    ull res = 0;
    while (m--)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            M.insert(a);
        }
        for (int i = 0; i < n; i++)
        {
            auto it = M.lower_bound(Licznik[i].second);
            if (it == M.end())
            {
                cout << "NIE\n";
                return 0;
            }

            res += (*it - Licznik[i].second) * Licznik[i].first;
            Licznik[i].second = *it;
            M.erase(it);
        }
    }
    cout << res << "\n";
    return 0;
}