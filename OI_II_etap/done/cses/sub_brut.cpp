#include <bits/stdc++.h>

using namespace std;
const int M = 2e5 + 10;
int Num[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> Num[i];
    }
    int res = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += Num[j];
            if (sum == x)
                res++;
        }
    }
    cout << res;
    return 0;
}