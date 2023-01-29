#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, res = 0;
    cin >> n >> m;
    while (m > n)
    {
        if (m % 2 != 0)
        {
            m++;
            res++;
        }
        m /= 2;
        res++;
    }
    res += n - m;
    cout << res;
    return 0;
}