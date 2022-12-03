#include <bits/stdc++.h>

using namespace std;
struct mis
{
    int x = 0;
    int y = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mis Skok_1, Skok_2, Mis;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> Plansza(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Plansza[i][j];

    vector<int> Suma;
    Suma.push_back(Plansza[0][0]);
    Suma.push_back(Plansza[0][0]);
    if (sqrt(k) > n - 1 || sqrt(k) > m - 1)
    {
        cout << 0;
        return 0;
    }
    while (Skok_1.x != n - 1 || Skok_1.y != m - 1 || Skok_2.x != n - 1 || Skok_1.y != m - 1)
    {

        Skok_1.x = Skok_1.x + 1;
        Skok_1.y = Skok_1.y + k - 1;
        if (Skok_1.x > n - 1)
        {
            int tmp = Skok_1.x - n + 1;
            Skok_1.x -= tmp;
            Skok_1.y += tmp;
        }

        Skok_2.x = Skok_2.x + k - 1;
        Skok_2.y = Skok_2.y + 1;
        Suma[0] += Plansza[Skok_1.x][Skok_1.y];
        Suma[1] += Plansza[Skok_2.x][Skok_2.y];
    }
    cout << Suma[0];
    return 0;
}