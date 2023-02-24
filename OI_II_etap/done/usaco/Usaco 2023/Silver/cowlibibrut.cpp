#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll addd = 1e9;
struct cowlibibrut
{
    ll x, y, time;
};
inline bool sortoo(cowlibibrut &lhs, cowlibibrut &rhs) { return lhs.time < rhs.time; }
int G, N;
vector<cowlibibrut> Gardens;
bool valid(ll v, ll timer)
{
    if (Gardens[v].time > timer)
        return 1;
    return 0;
}
bool valid2(ll v, ll timer)
{
    if (Gardens[v].time < timer)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> G >> N;
    Gardens.resize(G);
    ll res = 0;
    ll x, y, timer;
    for (int i = 0; i < G; i++)
    {
        cin >> Gardens[i].x >> Gardens[i].y >> Gardens[i].time;
        Gardens[i].x += addd, Gardens[i].y += addd;
    }
    sort(Gardens.begin(), Gardens.end(), sortoo);
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> timer;
        x += addd, y += addd;
        bool croos = 0;
        ll lo = 0, hi = G - 1, mid, ans = -1, ansm = -1, ans3 = -1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (valid(mid, timer))
            {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }
        lo = 0, hi = G - 1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (valid2(mid, timer))
            {
                lo = mid + 1;
                ansm = mid;
            }
            else
                hi = mid - 1;
        }
        lo = 0, hi = G - 1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Gardens[mid].time == timer)
            {
                ans3 = mid;
                break;
            }
            else if (Gardens[mid].time > timer)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        bool sus = 1;
        if (ans != -1)
        {
            for (int j = 0; j < G; j++)
            {
                if (Gardens[j].time != Gardens[ans].time)
                    continue;
                if (abs(Gardens[j].x - x) + abs(Gardens[j].y - y) > abs(Gardens[j].time - timer))
                {
                    sus = 0;
                    break;
                }
            }
        }
        if (ansm != -1)
        {
            for (int j = 0; j < G; j++)
            {
                if (Gardens[j].time != Gardens[ansm].time)
                    continue;
                if (abs(Gardens[j].x - x) + abs(Gardens[j].y - y) > abs(Gardens[j].time - timer))
                {
                    sus = 0;
                    break;
                }
            }
        }
        if (ans3 != -1)
        {
            for (int j = 0; j < G; j++)
            {
                if (Gardens[j].time != Gardens[ans3].time)
                    continue;
                if (abs(Gardens[j].x - x) + abs(Gardens[j].y - y) > abs(Gardens[j].time - timer))
                {
                    sus = 0;
                    break;
                }
            }
        }
        if (!sus)
            res++;
    }
    cout << res;
    return 0;
}