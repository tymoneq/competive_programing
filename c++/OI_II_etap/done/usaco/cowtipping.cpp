#include <bits/stdc++.h>

using namespace std;
int Grid[15][15];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("cowtip.in"), fout.open("cowtip.out");
    int n;
    fin >> n;
    char z;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fin >> z;
            Grid[i][j] = z - 48;
        }

    int res = 0;
    pair<int, int> poz;
    bool fint = 0;
    while (1)
    {
        fint = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (fint)
                break;
            for (int j = n - 1; j >= 0; j--)
                if (Grid[i][j] == 1)
                {
                    fint = 1;
                    poz.first = i, poz.second = j;
                    res++;
                    break;
                }
        }
        for (int i = 0; i <= poz.first; i++)
            for (int j = 0; j <= poz.second; j++)
            {
                if (Grid[i][j] == 0)
                    Grid[i][j] = 1;
                else
                    Grid[i][j] = 0;
               
            }

        if (!fint)
            break;
    }
    fout << res;
    fin.close(), fout.close();
    return 0;
}