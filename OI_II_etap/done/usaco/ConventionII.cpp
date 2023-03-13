#include <bits/stdc++.h>
// Solution using Segment min tree and binary search
using namespace std;
typedef unsigned long long ull;
constexpr int base = 1 << 17;
struct cow
{
    ull arrives, time, ind;
};
inline bool sortCows(cow &lhs, cow &rhs) { return lhs.arrives < rhs.arrives; }
ull Tree[base << 1];
ull currenttime, res;
vector<cow> COWS;
void upt(int v)
{
    v /= 2;
    while (v != 0)
    {
        Tree[v] = min(Tree[v * 2], Tree[v * 2 + 1]);
        v /= 2;
    }
}
void query(int r)
{
    // finding min in a given range
    r += base - 1;
    int l = base;
    ull mn = numeric_limits<ull>::max();
    mn = min(Tree[l], Tree[r]);
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            mn = min(mn, Tree[l + 1]);
        if (r % 2 == 1)
            mn = min(mn, Tree[r - 1]);
        l /= 2, r /= 2;
    }
    if (mn == numeric_limits<ull>::max())
    {
        int lo = 0, hi = COWS.size() - 1, mid, ans;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (COWS[mid].arrives > currenttime)
            {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }
        currenttime = COWS[ans].arrives + COWS[ans].time;
        Tree[base + ans] = numeric_limits<ull>::max();
        upt(base + ans);
    }
    else
    {
        l /= 2;
        while (l < base)
        {
            if (Tree[l * 2] == mn)
                l *= 2;
            else if (Tree[l * 2 + 1] == mn)
            {
                l *= 2;
                l++;
            }
        }
        int ind = l - base;
        Tree[l] = numeric_limits<ull>::max();
        upt(l);
        res = max(res, (currenttime - COWS[ind].arrives));
        currenttime += COWS[ind].time;
    }
}
int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    COWS.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> COWS[i].arrives >> COWS[i].time;
        COWS[i].ind = i + 1;
    }
    sort(COWS.begin(), COWS.end(), sortCows);
    currenttime = COWS[0].arrives + COWS[0].time;
    // seting segment Tree
    for (int i = base; i < base << 1; i++)
        Tree[i] = numeric_limits<ull>::max();
    for (int i = 1; i < n; i++)
        Tree[i + base] = COWS[i].ind;
    for (int i = base - 1; i > 0; i--)
        Tree[i] = min(Tree[i * 2], Tree[i * 2 + 1]);

    n--;
    while (n--)
    {
        int lo = 0, hi = COWS.size() - 1, mid, ans;// finding range with binary search
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (COWS[mid].arrives > currenttime)
            {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }
        if (COWS[COWS.size() - 1].arrives < currenttime)
            ans = COWS.size();
        query(ans);
    }
    cout << res;
    return 0;
}