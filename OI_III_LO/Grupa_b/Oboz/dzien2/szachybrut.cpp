#include <bits/stdc++.h>

using namespace std;
struct szachy
{
    char figura;
    int x, y;
};

constexpr int M = 2e5 + 10;
long long Val[M];
szachy Sz[M];
int m;
long long calcFig(char f, int x, int y)
{
    long long tmp = 0;
    if (f == 'W')
        return (m - 1) * 2;
    if (f == 'S')
    {
        if (x - 2 > 0 && y - 1 > 0)
            tmp++;
        if (x - 1 > 0 && y - 2 > 0)
            tmp++;
        if (x + 1 <= m && y - 2 > 0)
            tmp++;
        if (x + 2 <= m && y - 1 > 0)
            tmp++;
        if (x - 2 > 0 && y + 1 <= m)
            tmp++;
        if (x - 1 > 0 && y + 2 <= m)
            tmp++;
        if (x + 2 <= m && y + 1 <= m)
            tmp++;
        if (x + 1 <= m && y + 2 <= m)
            tmp++;
        return tmp;
    }
    if (f == 'K')
    {
        if ((x == m && ((y == m || y == 1))) || ((x == 1 && (y == m || y == 1))))
            return 3;
        if (((x == m || x == 1) && (y != m && y != 1)) || ((x != m && x != 1) && (y == m || y == 1)))
            return 5;
        else
            return 8;
    }
    if (f == 'H')
    {
        tmp += (m - 1) * 2;
        int l, r, d, g;
        l = x - 1;
        r = m - x;
        g = y - 1;
        d = m - y;
        tmp += min(g, r) + min(g, l) + min(l, d) + min(r, d);
        return tmp;
    }
    if (f == 'G')
    {
        int l, r, d, g;
        l = x - 1;
        r = m - x;
        g = y - 1;
        d = m - y;
        return min(g, r) + min(g, l) + min(l, d) + min(r, d);
    }
}
vector<int> Cost(8);
long long upt(int i, int j)
{
    int x1 = Sz[i].x, x2 = Sz[j].x, y1 = Sz[i].y, y2 = Sz[j].y;
    int res = 0;
    if (Sz[i].figura == 'K' && (((x1 + 1 == x2 || x1 - 1 == x2) && (y1 - 1 == y2 || y1 == y2 || y1 + 1 == y2)) || ((x1 == x2 && (y1 - 1 == y2 || y1 + 1 == y2)))))
        res -= 1;

    if (Sz[i].figura == 'W')
    {
        if (x1 == x2)
        {
            if (y1 < y2)
            {
                res = m - y2 + 1;
                Cost[2] = max(res, Cost[2]);
            }
            else
            {
                res = y2;
                Cost[3] = max(res, Cost[3]);
            }
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
            {
                res = m - x2 + 1;
                Cost[0] = max(res, Cost[0]);
            }
            else
            {
                res = x2;
                Cost[1] = max(res, Cost[1]);
            }
        }
        res = 0;
    }

    if (Sz[i].figura == 'S')
    {
        if (x1 - 2 == x2 && y1 - 1 == y2)
            res--;
        if (x1 - 1 == x2 && y1 - 2 == y2)
            res--;
        if (x1 + 1 == x2 && y1 - 2 == y2)
            res--;
        if (x1 + 2 == x2 && y1 - 1 == y2)
            res--;
        if (x1 - 2 == x2 && y1 + 1 == y2)
            res--;
        if (x1 - 1 == x2 && y1 + 2 == y2)
            res--;
        if (x1 + 2 == x2 && y1 + 1 == y2)
            res--;
        if (x1 + 1 == x2 && y1 + 2 == y2)
            res--;
    }
    if (Sz[i].figura == 'H')
    {
        if (x1 == x2)
        {
            if (y1 < y2)
            {
                res = m - y2 + 1;
                Cost[2] = max(res, Cost[2]);
            }
            else
            {
                res = y2;
                Cost[3] = max(res, Cost[3]);
            }
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
            {
                res = m - x2 + 1;
                Cost[0] = max(res, Cost[0]);
            }
            else
            {
                res = x2;
                Cost[1] = max(res, Cost[1]);
            }
        }
        int l, r, d, g;
        l = x1 - 1;
        r = m - x1;
        g = y1 - 1;
        d = m - y1;
        if (abs(x1 - x2) != abs(y1 - y2))
            return 0;
        if (x1 > x2 && y1 > y2)
        {
            res = min(l, g) - abs(x1 - x2) + 1;
            Cost[4] = max(res, Cost[4]);
        }
        if (x1 < x2 && y1 > y2)
        {
            res = min(r, g) - abs(x1 - x2) + 1;
            Cost[5] = max(Cost[5], res);
        }
        if (x1 > x2 && y1 < y2)
        {
            res = min(l, d) - abs(x1 - x2) + 1;
            Cost[6] = max(Cost[6], res);
        }
        if (x1 < x2 && y1 < y2)
        {
            res = min(r, d) - abs(x1 - x2) + 1;
            Cost[7] = max(Cost[7], res);
        }
        res = 0;
    }
    if (Sz[i].figura == 'G')
    {
        int l, r, d, g;
        l = x1 - 1;
        r = m - x1;
        g = y1 - 1;
        d = m - y1;
        if (abs(x1 - x2) != abs(y1 - y2))
            return 0;
        if (x1 > x2 && y1 > y2)
        {
            res = min(l, g) - abs(x1 - x2) + 1;
            Cost[4] = max(res, Cost[4]);
        }
        if (x1 < x2 && y1 > y2)
        {
            res = min(r, g) - abs(x1 - x2) + 1;
            Cost[5] = max(Cost[5], res);
        }
        if (x1 > x2 && y1 < y2)
        {
            res = min(l, d) - abs(x1 - x2) + 1;
            Cost[6] = max(Cost[6], res);
        }
        if (x1 < x2 && y1 < y2)
        {
            res = min(r, d) - abs(x1 - x2) + 1;
            Cost[7] = max(Cost[7], res);
        }
        res = 0;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> Sz[i].figura >> Sz[i].x >> Sz[i].y;
        Val[i] = calcFig(Sz[i].figura, Sz[i].x, Sz[i].y);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            Cost[j] = 0;
        for (int j = 0; j < n; j++)
            if (i != j)
                Val[i] += upt(i, j);

        if (Sz[i].figura == 'W' || Sz[i].figura == 'H' || Sz[i].figura == 'G')
            for (int k = 0; k < 8; k++)
                Val[i] -= Cost[k];
    }

    for (int i = 0; i < n; i++)
        cout << Val[i] << "\n";
    return 0;
}