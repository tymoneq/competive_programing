#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int base = 1 << 18;

ll sumTree[base << 1];
int MXTree[base << 1];

inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second > rhs.second;
    return lhs.first < rhs.first;
}

void upt(int v)
{
    v /= 2;
    while (v > 0)
    {
        MXTree[v] = max(MXTree[v * 2], MXTree[v * 2 + 1]);
        sumTree[v] = sumTree[v * 2] + sumTree[v * 2 + 1];
        v /= 2;
    }
}

int fintmx()
{
    int indx = 1;
    while (indx < base)
    {
        if (MXTree[indx * 2] == MXTree[indx])
            indx *= 2;
        else
            indx = indx * 2 + 1;
    }
    return indx;
}
ll querr_sum(int l, int r)
{
    l += base;
    r += base + 1;
    ll sum = 0;
    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            sum += sumTree[l + 1];
        if (r % 2 == 1)
            sum += sumTree[r - 1];
        r /= 2, l /= 2;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, c, c_v, res;
    ll current_sum;
    cin >> t;
    for (int i = base; i < base + base - 1; i++)
        MXTree[i] = -10;

    while (t--)
    {
        cin >> n >> c;
        res = 0;
        vector<pair<int, int>> V(n), Sorted_v(n);
        vector<ll> Pref_sum(n);
        pair<int, bool> mx = {0, 0};
        for (int i = 0; i < n; i++)
        {
            cin >> V[i].first;
            Sorted_v[i].first = V[i].first;
            Sorted_v[i].second = i;
            MXTree[i + base + 1] = V[i].first;
            mx.first = max(V[i].first, mx.first);
        }
        Pref_sum[0] = V[0].first;
        for (int i = 1; i < n; i++)
            Pref_sum[i] = Pref_sum[i - 1] + V[i].first;

        sort(Sorted_v.begin(), Sorted_v.end(), sorto);

        for (int i = 0; i < n; i++)
        {
            sumTree[base + i + 1] = Sorted_v[i].first;
            V[Sorted_v[i].second].second = i;
        }
        for (int i = base; i <= base + n; i++)
            upt(i);

        for (int i = 0; i < n; i++)
        {
            res = 0;
            if (i == 0)
            {
                current_sum = V[i].first + c;
                queue<pair<int, int>> q;
                while (current_sum < MXTree[1])
                {
                    int indx = fintmx();
                    current_sum += MXTree[indx];
                    q.push({MXTree[indx], indx});
                    MXTree[indx] = -10;
                    upt(indx);
                    res++;
                }

                while (!q.empty())
                {
                    MXTree[q.front().second] = q.front().first;
                    upt(q.front().second);
                    q.pop();
                }
            }
            else
            {
                if (mx.first == V[i].first && !mx.second && V[0].first + c < mx.first)
                    mx.second = 1;

                else
                {
                    current_sum = (ll)c + querr_sum(V[i].second, n);
                    if (current_sum < (ll)V[i].first)
                        res = n - V[i].second;
                    else
                    {
                        current_sum = Pref_sum[i] + c;
                        res = i;
                        queue<pair<int, int>> q;
                        while (current_sum < MXTree[1])
                        {
                            int indx = fintmx();
                            current_sum += MXTree[indx];
                            q.push({MXTree[indx], indx});
                            MXTree[indx] = -10;
                            upt(indx);
                            res++;
                        }

                        while (!q.empty())
                        {
                            MXTree[q.front().second] = q.front().first;
                            upt(q.front().second);
                            q.pop();
                        }
                    }
                }
            }
            cout << res << " ";
            MXTree[i + base + 1] = -10;
            sumTree[V[i].second + 1 + base] = 0;
            upt(i + base + 1);
            upt(V[i].second + 1 + base);
        }
        cout << "\n";
        for (int i = base; i <= base + n; i++)
        {
            MXTree[i] = -10;
            sumTree[i] = 0;
            upt(i);
        }
    }
    return 0;
}
