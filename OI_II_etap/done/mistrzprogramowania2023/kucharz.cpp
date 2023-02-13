#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> Waga(n);
    vector<int> Res(n);
    int suma_wag = 0, nowa_waga = 0;
    for (int i = 0; i < n; i++)
        cin >> Waga[i];
    Res[0] = Waga[0];
    for (int i = 1; i < n; i++)
        Res[i] = Waga[i] - Waga[i - 1];
    for (int i = 0; i < n; i++)
        cout << Res[i] << " ";
    return 0;
}