#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x, y, w, k;
    cin >> w >> k;
    vector<pair<int, int>> Res;
    for (int x = 100; x <= 100; x++)
    {
        for (int y = 0; y < 99; y++)
        {
            if ((y + w) * 100 + x / 100 == k * (x + y))
            {
                Res.push_back(make_pair(x / 100, y));
            }
        }
    }
    if (Res.size() == 0)
        cout << "brak";
    else
        for (auto el : Res)
        {
            cout << el.first << " " << el.second << " ";
        }
    return 0;
}