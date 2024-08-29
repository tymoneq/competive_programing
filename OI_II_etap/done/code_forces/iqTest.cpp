#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, even = 0, odd = 0, index_even = 0, index_odd = 0, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            even++;
            index_even = i;
        }
        else
        {
            odd++;
            index_odd = i;
        }
    }
    if (even == 1)
        cout << index_even;
    else
        cout << index_odd;
    return 0;
}