#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    unsigned int res = 0;
    cin >> n;
    set<int> Elsie, Bessie;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        Elsie.insert(a);
    }
    for (int i = 1; i <= n * 2; i++)
        if (!Elsie.count(i))
            Bessie.insert(i);
    for (int card : Elsie)
    {
        auto it = Bessie.upper_bound(card);
        // auto it = upper_bound(Bessie.begin(), Bessie.end(), card);
        if (it != Bessie.end())
        {
            res++;
            Bessie.erase(it);
        }
    }
    cout << res;
    return 0;
}