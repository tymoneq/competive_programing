#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 20;

ll Pref[N], Suf[N], Ans[N];
pair<int, int> Occurance[N];
bool type[N]; // 1 - programer 0 - tester
pair<int, bool> bad;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, a, b;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vector<pair<int, int>> Candidates;
        ll ans = 0;
        Occurance[0] = {n, m};
        bad.first = numeric_limits<int>::max();
        for (int i = 1; i <= n + m + 1; i++)
        {
            cin >> a;
            Candidates.push_back({a, 0});
        }
        for (auto &el : Candidates)
            cin >> el.second;

        for (int i = 1; i <= m + n + 1; i++)
        {
            if (Candidates[i].first > Candidates[i].second && Occurance[i - 1].first > 0)
            {
                b = Candidates[i].first;
                Occurance[i] = Occurance[i - 1];
                Occurance[i].first--;
                type[i] = 1;
            }
            else if (Candidates[i].first > Candidates[i].second && Occurance[i - 1].first == 0)
            {
                b = Candidates[i].second;
                Occurance[i] = Occurance[i - 1];
                Occurance[i].second--;
                if (i < bad.first)
                    bad = {i, 0};
                type[i] = 0;
            }
            else if (Candidates[i].first < Candidates[i].second && Occurance[i - 1].second > 0)
            {
                b = Candidates[i].second;
                Occurance[i] = Occurance[i - 1];
                Occurance[i].second--;
                type[i] = 0;
            }
            else if (Candidates[i].first < Candidates[i].second && Occurance[i - 1].second == 0)
            {
                b = Candidates[i].first;
                Occurance[i] = Occurance[i - 1];
                Occurance[i].first--;
                if (i < bad.first)
                    bad = {i, 1};
                type[i] = 1;
            }
            Pref[i] = Pref[i - 1] + b;
        }
        Ans[n + m + 1] = Pref[n + m];
        Suf[n + m + 1] = Pref[n + m + 1] - Pref[n + m];

        for (int i = n + m; i > 0; i--)
        {
            if (i > bad.first)
                Ans[i] = Pref[i - 1] + Suf[i + 1];
            else if (i == bad.first)
            {
            }
            else if (i < bad.first && type[i] == bad.second)
            {

                b = abs(Candidates[bad.first].first - Candidates[bad.first].second);
                Ans[i] = Pref[i - 1] + Suf[i + 1] + b;
            }
            Suf[i] = Pref[i] - Pref[i - 1];
        }
        for (int i = 1; i <= n + m + 1; i++)
            cout << Ans[i] << " ";

        cout << "\n";
        for (int i = 1; i <= n + m + 1; i++)
            Pref[i] = 0, Suf[i] = 0, Ans[N], Occurance[i] = {0, 0}, type[i] = 0;
    }

    return 0;
}