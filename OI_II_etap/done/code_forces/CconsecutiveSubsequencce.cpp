#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
pair<int, int> dp[N]; // first res, second prev_indx
int a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, mx = 0;
    map<int, int> LastIndx;
    vector<int> res;
    int indx;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (LastIndx[a[i] - 1] == 0)
            dp[i] = {1, -1};
        else
            dp[i] = {dp[LastIndx[a[i] - 1]].first + 1, LastIndx[a[i] - 1]};

        mx = max(mx, dp[i].first);
        LastIndx[a[i]] = i;
    }

    for (int i = n; i > 0; i--)
        if (dp[i].first == mx)
        {
            indx = i;
            break;
        }

    while (indx != -1)
    {
        res.push_back(indx);
        indx = dp[indx].second;
    }

    cout << mx << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}