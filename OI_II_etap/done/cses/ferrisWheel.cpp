#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("1.txt", "r", stdin);
    ui n, x, b;
    cin >> n >> x;
    multiset<ui> V;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        V.insert(b);
    }
    ui weight = 0;
    ui res = 0;
    while (!V.empty())
    {

        res++;
        weight = *V.begin();
        V.erase(V.begin());
        if (!V.empty())
        {
            auto itr = V.lower_bound(x - weight);
            // auto itr = lower_bound(V.begin(), V.end(), (x - weight));
            if (itr != V.end() && *itr <= (x - weight))
                V.erase(itr);
            else if (itr != V.begin())
            {
                itr--;
                V.erase(itr);
            }
        }
    }
    cout << res;
    return 0;
}