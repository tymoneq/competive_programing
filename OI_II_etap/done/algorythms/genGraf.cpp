#include <bits/stdc++.h>

using namespace std;

int losuj(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main()
{
    int ziarno;
    cin >> ziarno;
    srand(ziarno);

    int n = losuj(1'00'000, 5'00'000);
    int m = losuj(n, min(n + n, 5'00'000));

    cout << n << " " << m << '\n';

    for (int i = 2; i <= n; i++)
    {
        int rodzic = losuj(1, i - 1);
        cout << rodzic << ' ' << i << " " << losuj(1, 1'000'000'000) << '\n';
    }

    for (int i = n; i <= m; i++)
    {
        int a = losuj(1, n);
        int b = losuj(1, n);
        if (a == b)
        {
            i--;
            continue;
        }

        cout << a << ' ' << b << " " << losuj(1, 1'000'000'000) << '\n';
    }

    return 0;
}