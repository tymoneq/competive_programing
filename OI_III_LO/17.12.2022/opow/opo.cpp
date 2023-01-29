#include <bits/stdc++.h>

using namespace std;
int TAB[200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long res = 0;
    int n, tmp;
    char znak;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> znak;
        if ((int)znak >= 65 && (int)znak < 97)
        {
            tmp = znak + 32;
            if (TAB[znak] == 1)
            {
                TAB[tmp] = 1;
                res++;
            }
            else
                TAB[tmp] = 1;
            
        }
        if ((int)znak >= 97)
        {
            tmp = znak - 32;
            if (TAB[znak] == 1)
            {
                TAB[tmp] = 1;
                res++;
            }
            else
                TAB[tmp] = 1;
            
        }
    }
    cout << res;
}