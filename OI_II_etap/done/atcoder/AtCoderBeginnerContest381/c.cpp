#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0, numberof1 = 0, numberof2 = 0;
    bool slash = 0;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (slash)
                numberof1 = 0;
            numberof1++;
            numberof2 = 0;
            slash = 0;
        }
        else if (s[i] == '/')
        {
            if (slash)
                numberof1 = 0;
            slash = 1;
            res = max(res, 1);
            numberof2 = 0;
        }
        else if (s[i] == '2')
        {
            if (slash)
            {
                numberof2++;
                res = max(res, (min(numberof2, numberof1)) * 2 + 1);
            }
            else
                numberof1 = 0, numberof2 = 0, slash = 0;
        }
    }
    cout << res << "\n";
    return 0;
}