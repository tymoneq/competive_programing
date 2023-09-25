#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> Monety(n);
    for (int i = 0; i < n; i++)
        cin >> Monety[i].first;
    for (int i = 0; i < n; i++)
        cin >> Monety[i].second;
    vector<pair<bool, bool>> OFF(n);
    priority_queue<pair<ll, int>> top, sum;
    priority_queue<ll> bottom;
    for (int i = 0; i < n; i++)
    {
        top.push({Monety[i].first, i});
        sum.push({Monety[i].first + Monety[i].second, i});
    }
    ll res = 0;
    ll val1, val2, val3;
    while (k--)
    {
        if (k >= 2)
        {
        }
        else
        {
            while (bottom.size() > 0 && OFF[top.top().first].first)
                top.pop();

            while (bottom.size() > 0 && OFF[bottom.top()].second)
                bottom.pop();
            res += max(bottom.top(), top.top().first);
        }
    }
    cout << res;
    return 0;
}