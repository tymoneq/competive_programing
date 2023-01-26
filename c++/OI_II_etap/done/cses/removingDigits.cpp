#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, N, mx, res = 0;
    cin >> n;
    while (n != 0)
    {
        N = n;
        mx = -10;
        while (N > 0)
        {
            mx = max(mx, N % 10);
            N /= 10;
        }
        n -= mx;
        res++;
    }
    cout << res;
}