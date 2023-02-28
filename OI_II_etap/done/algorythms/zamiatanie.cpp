#include <bits/stdc++.h>
using namespace std;
void add(int v, int x)
{
}
int main()
{
    // scalowanie

    int n, x, y, s;
    cin >> n;
    map<int, int> mapa;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
        mapa[V[i]];
    }
    for (auto it = mapa.begin(); it != mapa.end(); it++)
        it->second = x++;
    for (int i = 1; i <= n; i++)
        V[i] = mapa[V[i]];

    // zamiatanie

    vector<pair<pair<int, int>, int>> vctr;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        vctr.push_back({{x, 1}, y});
        vctr.push_back({{x + s + 1, -1}, y});
    }
    sort(vctr.begin(), vctr.end());
    for (auto w : vctr)
    {

        if (w.first.second == 1)
            // dodajemy na drzewie
            add(w.second, 1);

        else
            // usuwamy z drzewa
            add(w.second, -1);
    }
    return 0;
}