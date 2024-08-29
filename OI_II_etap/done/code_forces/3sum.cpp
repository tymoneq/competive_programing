#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 15;

int TAB[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < MAXN; i++)
            TAB[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            TAB[a % 10]++;
        }
        bool T = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    if (((i == k && k == j && TAB[i] >= 3) || (i == k && j != i && TAB[i] >= 2 && TAB[j] >= 1) || (i == j && k != i && TAB[i] >= 2 && TAB[k] >= 1) || (j == k && j != i && TAB[j] >= 2 && TAB[i] >= 1) || (i != j && j != k && k != i && TAB[i] >= 1 && TAB[j] >= 1 && TAB[k] >= 1)) && ((i + k + j) % 10 == 3))
                        T = 1;

        if (T)
            cout
                << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}