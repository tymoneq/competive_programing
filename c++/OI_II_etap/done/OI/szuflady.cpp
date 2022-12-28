#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
int Height[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Height[i];

    for (int i = 0; i < n - 1; i++)
        if (Height[i] > Height[i + 1])
            res++;
    cout << res;
    return 0;
}