#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e4 + 10;

bool canUse[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> Stacje(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> Stacje[i];

    int mx = 0;
    for (int x = 1; x <= n; x++)
    {

        vector<int> S;
        for (int i = x; i <= n; i++)
        {
            bool can_use = 1;
            for (int j = (S.size() == k ? 1 : 0); j < S.size(); j++)
                if (S[j] == Stacje[i])
                    can_use = 0;

            canUse[i] = can_use;

            if (can_use)
            {
                S.push_back(Stacje[i]);
                if (S.size() > k)
                    S.erase(S.begin());
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (canUse[i])
                ans++;

            canUse[i] = 0;
        }

        mx = max(mx, ans);
    }
    cout << mx << "\n";

    return 0;
}