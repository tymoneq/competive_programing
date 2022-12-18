#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, res = 0;
    cin >> n;

    while (n > 0)
    {
        if (n >= 100)
        {
            n -= 100;
            res++;
        }
        else if (n >= 20)
        {
            n -= 20;
            res++;
        }
        else if (n >= 10)
        {
            n -= 10;
            res++;
        }
        else if (n >= 5)
        {
            n -= 5;
            res++;
        }
        else if (n >= 1)
        {
            n -= 1;
            res++;
        }
    }
    cout << res;

    return 0;
}