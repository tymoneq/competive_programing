#include <bits/stdc++.h>

using namespace std;
int Num[505];
int main()
{
    ifstream fin;
    fin.open("przyklad.txt");
    const int n = 500;
    for (int i = 1; i <= n; i++)
        fin >> Num[i];

    int res = 0, actual_res = 1, nwd, first, res_nwd = 0;

    for (int i = 1; i <= n; i++)
    {
        nwd = Num[i];
        actual_res = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (gcd(nwd, Num[j]) != 1)
            {
                actual_res++;
                nwd = gcd(nwd, Num[j]);
            }
            else
                break;
        }
        if (actual_res > res)
        {
            res = actual_res;
            first = Num[i];
            res_nwd = nwd;
        }
    }
    cout << first << " " << res << " " << res_nwd;
    return 0;
}