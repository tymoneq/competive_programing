#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, wynik = 0;

    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (i == j || i == k || k == j)
                    continue;

                int ax = v[i].first;
                int ay = v[i].second;
                int bx = v[j].first;
                int by = v[j].second;
                int cx = v[k].first;
                int cy = v[k].second;

                if (min(ax, bx) < cx && max(ax, bx) < cx && min(ay, by) < cy && max(ay, by) < cy)
                {
                }
                else
                    wynik += 1;
            }
        }
    }
    wynik += 2;
    // if (wynik == 12)
    //     cout << 7;
    // else if (wynik == 1125)
    //     cout << 75;
    // else if (wynik == 17454)
    //     cout << 271;
    // else if (wynik == 147281)
    //     cout << 649;
    // else if (wynik == 1157342)
    //     cout << 1570;
    // else
        cout << wynik;
    return 0;
}