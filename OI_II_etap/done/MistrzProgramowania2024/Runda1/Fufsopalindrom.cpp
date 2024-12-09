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
    string s;
    cin >> n >> s;

    bool T = 1;

    int i = 0, j = n - 1;
    while (i <= j)
    {
        if ((s[i] == '9' && s[j] == '6') || (s[i] == '6' && s[j] == '9'))
        {
            int x = 0;
        }
        else if (s[i] != s[j] || s[i] == '3' || s[i] == '4' || s[i] == '6' || s[i] == '7' || s[i] == '9')
        {
            T = 0;
            break;
        }
        i++;
        j--;
    }

    cout << (T ? "TAK" : "NIE") << '\n';

    return 0;
}
