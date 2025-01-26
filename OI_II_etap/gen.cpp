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

    int n = losuj(100, 100);
    int m = losuj(1, 1);

    cout << n << " " << m << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << 1 << ' ';

        cout << '\n';
    }
    return 0;
}