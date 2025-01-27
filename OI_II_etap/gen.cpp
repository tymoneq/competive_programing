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

    int n = losuj(1, 200);

    cout << n << '\n';

    for (int i = 0; i < n; i++)
    {
        cout << losuj(1, 5'00'000) << ' ';
    }
    return 0;
}