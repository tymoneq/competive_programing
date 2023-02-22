#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

struct Item
{
    int q; // type (cow or apple)
    int t; // time of entry
    int x; // position
    int n; // amount

    bool operator<(const Item &y)
    {
        if (x - t == y.x - y.t)
        {
            return q > y.q;
        }
        return x - t < y.x - y.t;
    }
} p[MAX_N];

int main()
{
    int N;
    map<int, int> pts; // stores how many apples are at each point defined above
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].q >> p[i].t >> p[i].x >> p[i].n;
    }

    sort(p, p + N);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].q == 2)
        {
            pts[p[i].x + p[i].t] += p[i].n;
        }
        else
        {
            int n = p[i].n;
            // greedily assign cows to the closest points
            while (n)
            {
                map<int, int>::iterator it = pts.lower_bound(p[i].x + p[i].t);

                if (it == pts.end())
                    break;
                int u = min(n, it->second);

                if (u == it->second)
                {
                    pts.erase(it);
                }
                else
                {
                    it->second -= u;
                }

                n -= u;
                ans += u;
            }
        }
    }

    cout << ans << endl;
}