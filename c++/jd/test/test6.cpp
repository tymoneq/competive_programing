#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char present, past;
    int res_a = 0, res_b = 0, mx_a = 0, mx_b = 0, count = 0;
    bool first_a = 0, first_b = 0;
    for (int i = 0; i < 10000; i++)
    {
        cin >> present;
        if (present == 'A')
        {
            first_b = 0;
            res_b = 0;
            res_a++;
        }
        else
        {
            first_a = 0;
            res_a = 0;
            res_b++;
        }
        if (res_a >= 10)
        {
            mx_a = max(mx_a, res_a);

            if (!first_a)
                count++;
            first_a = 1;
        }
        if (res_b >= 10)
        {
            mx_b = max(mx_b, res_b);

            if (!first_b)
                count++;
            first_b = 1;
        }
    }
    cout << count << " ";
    if (mx_a > mx_b)
        cout << "A " << mx_a;
    else
        cout << "B " << mx_b;
    return 0;
}