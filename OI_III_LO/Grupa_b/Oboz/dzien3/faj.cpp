#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll INF = 1e18;
constexpr int skok = 1e9;
map<pair<ll, ll>, int> M;
map<ll, int> Cords;
pair<int, int> Mieszkancy;
ll n, lo, hi, prevlo;
bool running = 1;
inline bool valid(ll val)
{
    auto it = Cords.lower_bound(lo);
    int countl = 0;
    for (it; it->first <= val; it++)
        countl += it->second;
    int countr = n - Mieszkancy.first - Mieszkancy.second - countl;
    if (countl < 2 && countr < 2)
    {
        running = 0;
        prevlo = lo;
        return 0;
    }
    if (countl + Mieszkancy.first > Mieszkancy.second + countr)
    {
        Mieszkancy.second += countr;
        return 1;
    }
    else
    {
        Mieszkancy.first += countl;
        return 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll s, v, h;
    cin >> n >> s;
    pair<ll, ll> MAX_cords;
    MAX_cords.first = numeric_limits<ll>::max();
    MAX_cords.second = numeric_limits<ll>::min();

    for (int i = 0; i < n; i++)
    {
        cin >> h >> v;
        h += skok;
        v += skok;
        M[{v, h}]++;
        Cords[v]++;
        MAX_cords.first = min(MAX_cords.first, v);
        MAX_cords.second = max(MAX_cords.second, v);
    }
    lo = MAX_cords.first, hi = MAX_cords.second;
    ll mid;
    while (lo <= hi && running)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid))
        {
            MAX_cords.second = mid;
            hi = mid - 1;
        }
        else
        {
            MAX_cords.first = mid;
            lo = mid + 1;
        }
    }
    if (prevlo != 0)
        lo = prevlo;
    ll res = numeric_limits<ll>::max(), tmp = 0, newf, news, x;
    for (ll i = MAX_cords.first; i <= MAX_cords.second; i++)
    {
        tmp = 0;
        for (auto el : M)
        {
            if (el.first.first == i || el.first.second == skok)
            {

                if (abs(el.first.first - i) >= s || abs(el.first.second - skok) >= s)
                    continue;
                else if (el.first.first == i)
                    tmp += (abs(el.first.second - skok) + s) * el.second;
                else
                    tmp += (abs(el.first.first - i) + s) * el.second;
            }
            else
            {
                x = 0;
                news = 0, newf = 0;
                if (abs(el.first.second - skok) < abs(el.first.first - i))
                {
                    x += abs(el.first.second - skok);
                    news = skok;
                }
                else
                {
                    x += abs(el.first.first - i);
                    newf = i;
                }
                if (news != 0 && abs(el.first.first - i) < s)
                    x += abs(s - abs(el.first.first - i));

                else if (newf != 0 && abs(el.first.second - skok) < s)
                    x += abs(s - abs(el.first.second - skok));

                tmp += x * el.second;
            }
        }
        res = min(res, tmp);
    }
    cout << res << "\n";
    return 0;
}