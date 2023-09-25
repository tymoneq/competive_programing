#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<pair<int, int>, int> Gold;
    int n, w, s, x, y;
    cin >> s >> w >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        Gold.insert(make_pair(make_pair(x, y), 1));
    }
    int ans = 0;

    for (auto el : Gold)
    {
        int tmp = 0;
        for (int X = el.first.first; X <= el.first.first + s; X++)
        {
            for (int Y = el.first.second ; Y <= el.first.second + w; Y++)
            {
                if (Gold.find({X, Y}) != Gold.end())
                    tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;

    return 0;
}