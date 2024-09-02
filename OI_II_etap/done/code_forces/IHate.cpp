#include <bits/stdc++.h>

using namespace std;
#define rep(x, start, end) for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); ((start) < (end) ? x++ : x--))
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;

        rep(x, 0, 20)
        {
            if (n % 11 == 0)
            {
                cout << "YES" << endl;
                goto done;
            }

            n -= 111;
            if (n < 0)
                break;
        }
        cout << "NO" << endl;

    done:;
    }
    return 0;
}