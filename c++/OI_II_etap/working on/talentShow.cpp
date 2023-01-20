#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
double dp[260][M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("talent.in"), fout.open("talent.out");
    int n, W, sum = 0;
    fin >> n >> W;
    vector<pair<int, int>> Cow(n);
    for (int i = 0; i < n; i++)
    {
        fin >> Cow[i].first >> Cow[i].second;
        sum += Cow[i].first;
    }
    sort(Cow.begin(), Cow.end());
    for (int i = 1; i <= n; i++)
        for (int w = 1; w <= sum; w++)
        {
            if (w - Cow[i - 1].first >= 0)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - Cow[i - 1].first] + Cow[i - 1].second);
            else
                dp[i][w] = dp[i - 1][w];
        }
    double mx = 0;
    for (int i = sum; i >= 0; i--)
    {
        if (i < W)
            break;
        mx = max(mx, dp[n][i] / i);
    }
    long long res = floor(mx * 1000);
    fout << res;
    fin.close(), fout.close();
    return 0;
}