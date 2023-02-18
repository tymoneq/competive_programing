#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 8640010;
bool Runing[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            Runing[j] = 1;
    }
    int maxruning = 0, maxnotrunnng = 0, currentrunning = 0, current_stop = 0;
    for (int i = 0; i <= 8640000; i++)
    {
        if (Runing[i])
        {
            currentrunning++;
            maxruning = max(maxruning, currentrunning);
            current_stop = 0;
        }
        else
        {
            current_stop++;
            maxnotrunnng = max(maxnotrunnng, current_stop);
            currentrunning = 0;
        }
    }
    cout << maxnotrunnng << "\n"
         << maxruning;
    return 0;
}