#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 2.5e5 + 10;
const int talentsum = 250000;
int dp[M];
constexpr int INF = 2e9;
int main()
{
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, W;
    cin >> N >> W;

    vector<pair<int, int>> Cows(N);
    for (int i = 0; i < N; i++)
        cin >> Cows[i].first >> Cows[i].second;

    int ind = 0;
    for (int i = 1; i <= talentsum; i++)
        dp[i] = INF;
    for (auto cow : Cows)
        for (int i = talentsum; i >= 0; i--)
            if (dp[i] != INF)
                dp[i + cow.second] = min(dp[i + cow.second], dp[i] + cow.first);
    double ans = 0, tmp;
    for (int T = 1; T <= talentsum; T++)
        if (dp[T] != INF && dp[T] >= W)
        {
            double t = T;
            tmp = t / dp[T];
            ans = max(tmp, ans);
        }
    cout << (int)(ans * 1000);
    return 0;
}