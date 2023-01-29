#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 7;
int Songs[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> S;
    for (int i = 1; i <= n; i++)
        cin >> Songs[i];
    int head = 0, tail = 1, res = 0;
    while (head < n)
    {
        head++;
        if (binary_search(S.begin(), S.end(), Songs[head]))
        {
            while (tail < head && binary_search(S.begin(), S.end(), Songs[head]))
            {
                auto it = find(S.begin(), S.end(), Songs[tail]);
                S.erase(it);
                tail++;
            }
            S.insert(Songs[head]);
            res = max(res, head - tail + 1);
        }
        else
        {
            S.insert(Songs[head]);
            res = max(res, head - tail + 1);
        }
    }
    cout << res;
    return 0;
}