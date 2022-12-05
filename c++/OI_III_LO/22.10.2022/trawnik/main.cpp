#include <bits/stdc++.h>

using namespace std;
int main()
{
    // binary search
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> rz(n);
    vector<int> kol(m);
    vector<long long> Pref_sum_kol(m);
    for (int i = 0; i < n; i++)
        cin >> rz[i];
    for (int i = 0; i < m; i++)
        cin >> kol[i];

    long long wynik = 0;
    sort(rz.begin(), rz.end());
    sort(kol.begin(), kol.end());
    Pref_sum_kol[0] = kol[0];
    for (int i = 1; i < m; i++)
        Pref_sum_kol[i] = Pref_sum_kol[i - 1] + kol[i];

    for (int i = 0; i < n; i++)
    {
        auto itr = lower_bound(kol.begin(), kol.end(), rz[i]);
        int index = (itr - kol.begin());
        wynik += (m - index) * rz[i];
        if (index > 0)
            wynik += Pref_sum_kol[index - 1];
    }
    cout << wynik;
    return 0;
}