#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int base = 1 << 19;
inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}
int Tree[base << 1];
int querryMAX(int l, int r)
{
    l += base;
    r += base;
    int val = 0;
    val = max(Tree[l], Tree[r]);
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            val = max(Tree[l + 1], val);
        if (r % 2 == 1)
            val = max(Tree[r - 1], val);
        l /= 2, r /= 2;
    }
    return val;
}
int fintMax(int val, int l, int r)
{
    l += base, r += base;
    if (Tree[l] == val)
        return l;
    if (Tree[r] == val)
        return r;
    while (l != r)
    {
        if (Tree[l] == val)
            break;
        if (Tree[r] == val)
            break;
        if (l % 2 == 0 && Tree[l + 1] == val)
        {
            l++;
            break;
        }
        if (r % 2 == 1 && Tree[r - 1] == val)
        {
            r--;
            break;
        }
        l /= 2, r /= 2;
    }
    if (Tree[r] == val)
        swap(r, l);
    if (Tree[l] == val)
    {
        while (l < base)
        {
            if (Tree[l * 2] == val)
                l *= 2;
            else if (Tree[l * 2 + 1] == val)
            {
                l *= 2;
                l++;
            }
        }
        return l;
    }
}
void upt(int v)
{
    Tree[v] = 0;
    v /= 2;
    while (v != 0)
    {
        Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
        v /= 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ind = 0;
    cin >> n >> k;
    vector<pair<int, int>> Biz(n); // first masa second val
    for (int i = 0; i < n; i++)
        cin >> Biz[i].first >> Biz[i].second;
    sort(Biz.begin(), Biz.end(), sorto);
    for (int i = base; i < base + n; i++)
    {
        Tree[i] = Biz[ind].second;
        ind++;
    }
    for (int i = base - 1; i > 0; i--)
        Tree[i] = max(Tree[i * 2], Tree[2 * i + 1]);
    vector<int> Bags(k);
    for (int i = 0; i < k; i++)
        cin >> Bags[i];
    sort(Bags.begin(), Bags.end());
    ull res = 0;
    int lo, hi, mid, ans, val;
    for (int bag : Bags)
    {
        lo = 0, hi = n - 1, ans = -1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Biz[mid].first > bag)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        ans--;
        if (bag >= Biz[n - 1].first)
            ans = n - 1;
        if (ans >= 0)
        {
            val = querryMAX(0, ans);
            res += val;
            ind = fintMax(val, 0, ans);
            upt(ind);
        }
    }

    cout << res;
    return 0;
}