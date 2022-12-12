#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cykle = 0, res = 0, j = 1;
    char Test;
    bool punkty = true;
    cin >> n;
    cykle = n / 10;

    for (int i = 0; i < n; i++)
    {
        cin >> Test;
        if (Test == 'N')
            punkty = false;
        if (j == cykle && punkty)
        {
            res++;
            j = 0;
        }
        else if (j == cykle)
        {
            j = 0;
            punkty = true;
        }
        j++;
    }
    cout << res;
    return 0;
}