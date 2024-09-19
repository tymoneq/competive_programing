#include <bits/stdc++.h>

using namespace std;
struct PointX
{
    int x1, x2, y;
};
struct PointY
{
    int y1, y2, x;
};

inline bool sorto(PointY &lhs, PointY &rhs) { return lhs.x < rhs.x; }
inline bool sortoX(PointX &lhs, PointX &rhs) { return lhs.x1 < rhs.x1; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;

    cin >> n >> m;

    vector<PointX> Px(n);
    vector<PointY> Py(m);

    for (int i = 0; i < n; i++)
        cin >> Px[i].x1 >> Px[i].x2 >> Px[i].y;

    for (int i = 0; i < m; i++)
        cin >> Py[i].y1 >> Py[i].y2 >> Py[i].x;

    sort(Py.begin(), Py.end(), sorto);
    sort(Px.begin(), Px.end(), sortoX);

    int lo = 0, hi = 1e9, mid, ans = 0;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        bool T = 0;
        queue<pair<int, int>> Beginings, Ends;
        set<int> CurrentY;
        for (int i = 0, j = 0; j < m;)
        {

            if (i < n && Px[i].x1 < Py[j].x) // dodawanie odcinków poziomych
            {
                if (Px[i].x2 - Px[i].x1 >= 2 * mid)
                {
                    Beginings.push({Px[i].x1 + mid, Px[i].y});
                    Ends.push({Px[i].x2 - mid, Px[i].y});
                }
                ++i;
            }
            else // liczenie wyników dla odcinków pionowych
            {

                // Adding and removing X axis to set
                while (!Beginings.empty() && Beginings.front().first <= Py[j].x)
                {
                    CurrentY.insert(Beginings.front().second);
                    Beginings.pop();
                }
                while (!Ends.empty() && Ends.front().first < Py[j].x)
                {
                    CurrentY.erase(Ends.front().second);
                    Ends.pop();
                }
                // calculating res
                if (Py[j].y2 - Py[j].y1 >= 2 * mid)
                {
                    auto itBeg = CurrentY.lower_bound(Py[j].y1 + mid);
                    if (itBeg != CurrentY.end() && Py[j].y1 + mid <= *itBeg && *itBeg <= Py[j].y2)
                        T = 1;
                }
                ++j;
            }

            if (T)
                break;
        }

        if (T)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}