#include <bits/stdc++.h>
using namespace std;
// kmp
int P[20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    P[0] = P[1] = 0;
    int j, n;
    string s; //dodawaj "#" na początek lub inny znak który nie występuje w słowie
    cin >>n >> s;
    for (int i = 2; i <= n; i++)
    {
        j = P[i-1];
        while (j>0 && s[j+1]!=s[i])
            j = P[j];
        if(s[j+1] == s[i])
            j++;
        P[i] = j;
    }
    return 0;
}