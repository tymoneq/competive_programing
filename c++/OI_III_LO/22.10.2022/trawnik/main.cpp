#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> rz(n);
    vector<int> kol(m);

    for (int i = 0; i < n; i++)
        cin >> rz[i];
    for (int i = 0; i < m; i++)
        cin >> kol[i];

    long wynik = 0;
    sort(rz.begin(), rz.end());
    sort(kol.begin(), kol.end());

    for (auto el : rz)
    {
        int k = 0;
        for (auto ell : kol)
        {
            if (el <= ell)
            {
                wynik += el * (kol.size() - k);
                break;
            }
            else
            {
                wynik += ell;
                k++;
            }
        }
    }
    cout << wynik;
    return 0;
}