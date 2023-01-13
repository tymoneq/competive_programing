#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char present, past;
    int res_a = 0, res_b = 0;
    for (int i = 0; i < 10000; i++)
    {
        cin >> present;
        if (present == 'A')
            res_a++;
        else
            res_b++;

        if (res_a >= 1000 && res_b < res_a - 3)
        {
            cout << "A " << res_a << ":" << res_b;
            break;
        }
        if (res_b >= 1000 && res_a < res_b - 3)
        {
            cout << "B " << res_b << ":" << res_a;
            break;
        }
    }

    return 0;
}