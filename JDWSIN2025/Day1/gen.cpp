#include <bits/stdc++.h>

using namespace std;

long long losuj(long long a, long long b)
{
    return a + rand() % (b - a + 1);
}

int main()
{
    int ziarno;
    cin >> ziarno;
    srand(ziarno);
    int n = 100;
    int m = 100;

    cout << 1 << "\n";

    cout << n << " " << m << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << losuj(1, 1'000'000) << ' ';

        cout << '\n';
    }
    return 0;
}