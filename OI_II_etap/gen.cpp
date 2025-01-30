#include <bits/stdc++.h>

using namespace std;

long long losuj(long long  a, long long b)
{
    return a + rand() % (b - a + 1);
}

int main()
{
    int ziarno;
    cin >> ziarno;
    srand(ziarno);

    int q = losuj(1, 2'00'000);

    cout << q << '\n';
    int cnt = 0;
    int id = 0;

    for (int i = 0; i < q; i++)
    {
        int oper = rand() % 2;

        if (oper == 0)
        {
            cnt++;

            if (cnt % 8 == 0)
            {
                cout << 'R' << ' ';
                cout << losuj(1, id) << '\n';
            }
            else
            {
                cout << 'D' << " ";
                id++;
                cout << losuj(1, 200'000) << " " << losuj(0, 1) << '\n';
            }
        }
        if (oper == 1)
        {
            cout << 'P' << ' ';

            cout << losuj(1, 1'000'000'000'000) << '\n';
        }
    }
    return 0;
}