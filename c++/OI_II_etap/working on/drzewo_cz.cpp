#include <bits/stdc++.h>
using namespace std;
const int M = 17;
int Tree[M][M], indx = 0, n;
string s;
struct drzewo_cz
{
    int x1, y1, x2, y2;
};

long long fast_pot(long long a, unsigned int n)
{
    long long w = 1;
    while (n > 0)
    {
        if (n % 2 == 1) // jesli bit jest = 1
            w *= a;

        a *= a;
        n /= 2; // skrócenie o jeden bit
    }
    return w;
}

inline void fill(int code, drzewo_cz poz)
{
    indx++;
    code -= 48;
    if (code == 0)
        return;
    if (code == 1)
    {
        for (int i = poz.x1; i < poz.x2; i++)
            for (int j = poz.y1; j < poz.y2; j++)
                Tree[i][j] = 1;
        return;
    }
    else if (code == 4)
    {
        drzewo_cz tmp;
        if (poz.x1 <= n / 2 && poz.y1 <= n / 2)
        {
            tmp.x1 = poz.x1, tmp.y1 = poz.y1, tmp.x2 = poz.x2 / 2, tmp.y2 = poz.y2 / 2;
            fill(s[indx], tmp);
            tmp.x1 = poz.x2 / 2 + 1, tmp.y1 = poz.y1, tmp.x2 = poz.x2, tmp.y2 = poz.y2 / 2;
            fill(s[indx], tmp);
            tmp.x1 = poz.x1, tmp.y1 = poz.y2 / 2 + 1, tmp.x2 = poz.x2 / 2, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
            tmp.x1 = poz.x2 / 2 + 1, tmp.y1 = poz.y2 / 2 + 1, tmp.x2 = poz.x2, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
        }
        else if (poz.x1 > n / 2 && poz.y1 <= n / 2)
        {
            tmp.x1 = poz.x1, tmp.y1 = poz.y1, tmp.x2 = (poz.x2 - poz.x1) / 2 + poz.x1, tmp.y2 = poz.y2 / 2;
            fill(s[indx], tmp);
            tmp.x1 = (poz.x2 - poz.x1) / 2 + poz.x1, tmp.y1 = poz.y1, tmp.x2 = poz.x2, tmp.y2 = poz.y2 / 2;
            fill(s[indx], tmp);
            tmp.x1 = poz.x1, tmp.y1 = poz.y2 / 2 + 1, tmp.x2 = (poz.x2 - poz.x1) / 2 + poz.x1, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
            tmp.x1 = (poz.x2 - poz.x1) + 1 + poz.x1, tmp.y1 = poz.y2 / 2 + 1, tmp.x2 = poz.x2, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
        }
        else if (poz.x1 <= n / 2 && poz.y1 > n / 2)
        {
            tmp.x1 = poz.x1, tmp.y1 = poz.y1, tmp.x2 = poz.x2 / 2, tmp.y2 = (poz.y2 - poz.y1) / 2 + poz.y1;
            fill(s[indx], tmp);
            tmp.x1 = poz.x2 / 2 + 1, tmp.y1 = poz.y1, tmp.x2 = poz.x2, tmp.y2 = (poz.y2 - poz.y1) / 2 + poz.y1;
            fill(s[indx], tmp);
            tmp.x1 = poz.x1, tmp.y1 = (poz.y2 - poz.y1) / 2 + poz.y1 + 1, tmp.x2 = poz.x2 / 2, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
            tmp.x1 = poz.x2 / 2 + 1, tmp.y1 = (poz.y2 - poz.y1) / 2 + poz.y1 + 1, tmp.x2 = poz.x2, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
        }
        else if (poz.x1 > n / 2 && poz.y1 > n / 2)
        {
            tmp.x1 = poz.x1, tmp.y1 = poz.y1, tmp.x2 = (poz.x2 - poz.x1) / 2 + poz.x1, tmp.y2 = (poz.y2 - poz.y1) / 2 + poz.y1;
            fill(s[indx], tmp);
            tmp.x1 = (poz.x2 - poz.x1) + poz.x1, tmp.y1 = poz.y1, tmp.x2 = poz.x2, tmp.y2 = (poz.y2 - poz.y1) / 2 + poz.y1;
            fill(s[indx], tmp);
            tmp.x1 = poz.x1, tmp.y1 = tmp.y1 = (poz.y2 - poz.y1) / 2 + poz.y1 + 1, tmp.x2 = (poz.x2 - poz.x1) / 2 + poz.x1, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
            tmp.x1 = (poz.x2 - poz.x1) + poz.x1, tmp.y1 = tmp.y1 = (poz.y2 - poz.y1) / 2 + poz.y1 + 1, tmp.x2 = poz.x2, tmp.y2 = poz.y2;
            fill(s[indx], tmp);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m >> s;
    n = fast_pot(2, m);
    drzewo_cz Tr = {1, 1, n + 1, n + 1};
    fill(s[0], Tr);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << Tree[i][j] << " ";
        cout << "\n";
    }
    return 0;
}