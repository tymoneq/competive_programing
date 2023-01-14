#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v = 0;
    cin >> n;
    vector<int> Num(9);
    Num[0] = Num[1] = 1;
    v = n % 10;
    v--;
    n /= 10;
    Num[7] = v;
    if (n > 0)
    {
        v = n % 10;
        n /= 10;
        Num[6] = Num[8] = v;
    }
    if (n > 0)
    {
        v = n % 10;
        n /= 10;
        Num[5] = Num[4] = v;
    }
    if (n > 0)
    {
        v = n % 10;
        n /= 10;
        Num[3] = v;
    }
    if (n > 0)
    {
        v = n % 10;
        n /= 10;
        Num[2] = v;
    }
    if (n > 0)
    {
        v = n % 10;
        v++;
        n /= 10;
        Num[0] = Num[1] = v;
    }
    for (int i = 0; i < 9; i++)
        cout << Num[i];
    return 0;
}