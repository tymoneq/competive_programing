#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> Sajz(n);
    for (int i = 0; i < n; i++)
        cin >> Sajz[i];
    sort(Sajz.begin(), Sajz.end());
    int l = 0, r = n - 1, current_space = 0;
    unsigned long long t=0;
    while (l <= r)
    {
        t += Sajz[r];
        current_space += Sajz[r];
        if (l == r)
            break;
        if (current_space + Sajz[l] <= m)
        {
            t += Sajz[l];
            l++;
        }
        else
            t++;
        r--;

        current_space = 0;
    }
    cout << t + 1;
    return 0;
}