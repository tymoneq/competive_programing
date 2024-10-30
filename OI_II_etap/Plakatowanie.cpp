#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    ll res = 0;
    vector<pair<int, int>> Budynki(n);

    for (int i = 0; i < n; i++)
        cin >> Budynki[i].first >> Budynki[i].second;

    int current_mx = 0, current_mn = numeric_limits<int>::max();

    res++;
    current_mx = Budynki[0].second;
    current_mn = Budynki[0].second;

    for (int i = 1; i < n; i++)
    {
        if (Budynki[i].second > current_mx)
        {
            res++;
            current_mx = Budynki[i].second;
        }
        else if (Budynki[i].second < current_mx && Budynki[i].second >= current_mn)
        {
            if (Budynki[i].second > current_mn)
                res++;
            current_mx = Budynki[i].second;
        }
        else if (Budynki[i].second < current_mn)
        {
            res++;

            current_mx = Budynki[i].second;
            current_mn = Budynki[i].second;
        }
    }
    cout << res << "\n";

    return 0;
}