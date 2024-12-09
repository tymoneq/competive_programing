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

    int n = losuj(1, 10'000);
    int k = losuj(1, 100);

    cout << n << " " << k << '\n';

    for (int i = 1; i <= n; i++)
        cout << losuj(1, 1'000) << ' ';

    cout << '\n';
    for (int i = 2; i <= n; i++)
    {
        int rodzic = losuj(1, i - 1);
        cout << rodzic << '\n';
    }

    return 0;
}