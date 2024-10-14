#include <bits/stdc++.h>

using namespace std;

constexpr int MAXSUM = 750010;

bool dp[MAXSUM];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p;
    cin >> p;
    vector<int> items(p);
    for (int &e : items)
        cin >> e;

    int suma = accumulate(items.begin(), items.end(), 0);

    dp[0] = 1;
    for (int i = 1; i <= p; i++)
        for (int j = 0; j <= (suma / 2); j++)
        {

            if (items[i - 1] > j)
                continue;

            else
                dp[j] = dp[j - items[i - 1]];
        }
    int maxCloseToHalf = 0;
    for (int j = suma / 2; j >= 0; --j)
    {
        if (dp[j])
        {
            maxCloseToHalf = j;
            break;
        }
    }
    int startszy = suma - 2 * maxCloseToHalf + maxCloseToHalf;

    cout << startszy << " " << maxCloseToHalf << "\n";
    return 0;
}