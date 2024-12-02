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
    cin >> n;
    bool T = 1;

    if (n != 13)
        T = 0;

    int points = 0;

    map<string, int> cnt;

    for (int i = 1; i <= n; i++)
    {
        string a;
        cin >> a;
        cnt[a]++;
        if (cnt[a] > 4)
        {
            T = 0;
            break;
        }
        if (a == "10")
            continue;

        if (a == "J")
            points++;
        else if (a == "Q")
            points += 2;
        else if (a == "K")
            points += 3;
        else if (a == "A")
            points += 4;
        else if (a < "2" || a > "9")
        {
            T = 0;
            break;
        }
    }

    if (T)
        cout << points << '\n';
    else
        cout << "OSZUST!" << '\n';

    return 0;
}