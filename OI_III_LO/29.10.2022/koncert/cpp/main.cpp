#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dni(n + 1, 0);
    vector<int> koncert(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> dni[i];

    for (int i = 1; i <= n; i++)
        koncert[i] = koncert[i - 1] + dni[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int pocz, kon;
        cin >> pocz >> kon;
        int wynik = koncert[kon] - koncert[pocz-1];
        cout << wynik << "\n";
    }
    return 0;
}
