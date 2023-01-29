#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+10;
int Val[M];
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Val[i];
    }
    sort(Val, Val + n);
    int avrage = Val[n / 2];
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += abs(avrage - Val[i]);
    cout << res;
    return 0;
}