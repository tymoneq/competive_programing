#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Nums[M];
int How_many[M], Count[M]; // drzewo
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> Nums[i];
        How_many[Nums[i]]++;
    }
    for (int i = 1; i <= n; i++)
        Count[i] = Count[i - 1] + How_many[i];
    bool cor = 1;
    for (int i = n; i > 1; i--)
        if (Count[i - 1] > i - 1)
        {
            cor = 0;
            break;
        }
    cout << (cor ? "TAK\n" : "NIE\n");
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        How_many[Nums[a]]--;
        How_many[b]++;
        cor = 1;
        if (How_many[n] < 1 || How_many[1] > 1)
            cor = 0;
        if (cor)
            for (int j = 1; j <= n; j++)
            {
                Count[j] = Count[j - 1] + How_many[j];
                if (Count[j - 1] > j - 1)
                    cor = 0;
            }
        Nums[a] = b;
        cout << (cor ? "TAK\n" : "NIE\n");
    }
    return 0;
}