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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int ans = 0;

    cin >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    vector<PointX> Px(n);
    vector<PointY> Py(m);
    for (auto &a : Px)
        cin >> a.x1 >> a.x2 >> a.y;

    for (auto &b : Py)
        cin >> b.y1 >> b.y2 >> b.x;

    for (auto px : Px)
        for (auto py : Py)
            if (px.x1 <= py.x && px.x2 >= py.x && px.y >= py.y1 && px.y <= py.y2)
                ans = max(ans, min(min(px.x2 - py.x, py.x - px.x1), min(py.y2 - px.y, px.y - py.y1)));

    cout << ans << "\n";
    return 0;
}