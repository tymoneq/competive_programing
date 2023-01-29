#include <bits/stdc++.h>
using namespace std;
const int M = 200000;
bool Animal[M];
struct les_zwierz_brut
{
    int a, b, cost;
};

int main()
{
    int n, m, c, a, b, k;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    vector<les_zwierz_brut> V(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> k;
        V[i] = {a, b, k};
    }
    int res = 0, current_res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
            Animal[j] = 0;
        current_res = 0;
        for (int j = i; j <= n; j++)
        {
            for (int h = 0; h < m; h++)
                if (!Animal[h] && V[h].a <= j && V[h].b >= j)
                {
                    current_res -= V[h].cost;
                    Animal[h] = 1;
                }
            current_res += c;

            res = max(res, current_res);
        }
    }
    cout << res;
}