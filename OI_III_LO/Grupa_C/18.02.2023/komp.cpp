#include <bits/stdc++.h>

using namespace std;
constexpr int M = 8640010;
int Runing[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    unordered_map<int, pair<int, int>> RuningorStop;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        b++;
        RuningorStop[a].first++;
        RuningorStop[b].second++;
        Runing[a] = max(2, Runing[a]);
        Runing[b] = max(Runing[b], 1);
    }
    int maxruning = 0, maxnotrunnng = 0, onecount = 0, current = 0, curstop = 0;
    for (int i = 0; i <= 8640000; i++)
    {
        if (Runing[i] == 2)
        {
            onecount += RuningorStop[i].first;
            onecount -= RuningorStop[i].second;
        }
        else if (Runing[i] == 1)
        {
            onecount += RuningorStop[i].first;
            onecount -= RuningorStop[i].second;
        }

        if (onecount > 0)
        {
            current++;
            curstop = 0;
            maxruning = max(maxruning, current);
        }
        else if (onecount == 0)
        {
            curstop++;
            current = 0;
            maxnotrunnng = max(maxnotrunnng, curstop);
        }
    }
    cout << maxnotrunnng << "\n"
         << maxruning;
    return 0;
}