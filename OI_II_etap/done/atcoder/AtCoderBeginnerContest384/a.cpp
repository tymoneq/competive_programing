#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    char c1, c2;
    cin >> n >> c1 >> c2;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
        if (s[i] != c1)
            s[i] = c2;

    cout << s << '\n';

    return 0;
}