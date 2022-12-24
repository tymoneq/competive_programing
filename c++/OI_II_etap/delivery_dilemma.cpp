#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 1e5 + 10;
int Courier[MAX_VAL];
pair<int, int> Petya[MAX_VAL];
bool Visited[MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, res = 0, a, tmp = 0, mx = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        res = 0, tmp = 0, mx = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> Courier[j];

        for (int j = 0; j < n; j++)
        {
            cin >> a;
            Petya[j] = make_pair(a, j);
        }
        sort(Petya, Petya + n);
        for (int j = 0; j < n; j++)
        {
            if (Petya[j].first >= Courier[Petya[j].second])
            {
                res = max(res, Courier[Petya[j].second]);
                continue;
            }
            tmp += Petya[j].first;
            if (tmp > Courier[Petya[j].second])
            {
                for (int k = 0; k < n; k++)
                    if (!Visited[k])
                        mx = max(mx, Courier[k]);
                res = mx;
                break;
            }
            Visited[Petya[j].second] = 1;
            res = tmp;
        }
        for (int j = 0; j < n; j++)
            Visited[j] = 0;
        cout << res << "\n";
    }
    return 0;
}