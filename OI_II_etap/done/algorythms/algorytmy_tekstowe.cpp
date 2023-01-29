#include <bits/stdc++.h>
using namespace std;
// kmp
int P[20], Kmp[20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    P[0] = P[1] = 0;
    int j, n;
    string w, t; // dodawaj "#" na początek lub inny znak który nie występuje w słowie wzorzec
    cin >> n >> w >> t;
    for (int i = 2; i <= n; i++) // tworzenie prefiksosufixów
    {
        j = P[i - 1];
        while (j > 0 && w[j + 1] != w[i])
            j = P[j];
        if (w[j + 1] == w[i])
            j++;
        P[i] = j;
    }
    // kmp
    j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (i > 0)
            j = Kmp[i - 1];
        while (j > 0 && t[i] != w[j + 1])
            j = P[j];

        if (t[i] == w[j + 1])
            j++;
        if (j == n)
        {
            j = P[j];
        }
    }
    return 0;
}