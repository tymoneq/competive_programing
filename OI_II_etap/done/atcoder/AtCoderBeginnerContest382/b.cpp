#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    string s;
    cin >> n >> d >> s;

    int indx = n - 1;
    while (d > 0 && indx >= 0)
    {
        if (s[indx] == '@')
        {
            d--;
            s[indx] = '.';
        }
        indx--;
    }
    cout << s << '\n';
    return 0;
}