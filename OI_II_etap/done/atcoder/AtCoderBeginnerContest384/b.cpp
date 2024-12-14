#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, R;
    cin >> n >> R;

    for (int i = 0; i < n; i++)
    {
        int d, a;
        cin >> d >> a;

        if (d == 1 && (1600 <= R && R <= 2799))
            R += a;

        if (d == 2 && (1200 <= R && R <= 2399))
            R += a;
    }

    cout << R << '\n';

    return 0;
}