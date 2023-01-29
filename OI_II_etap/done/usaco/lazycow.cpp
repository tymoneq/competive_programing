#include <bits/stdc++.h>
using namespace std;
const int M = 450;
int Grid[M][M], Prefsum[M][M];

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fin.tie(0);
    fin.open("lazy.in"), fout.open("lazy.out");
    int n, k;
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> Grid[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Prefsum[i][j] = Prefsum[i][j - 1] + Grid[i][j];
    int mx = 0, zakres = 1, x, curret_res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            zakres = 1, curret_res = 0;
            for (int h = 0; h <= 2 * k; h++)
            {
                if (i - k + h >= 1 && i - k + h <= n)
                {
                    x = (zakres - 1) / 2;
                    if (j - x >= 1 && j + x <= n)
                        curret_res += Prefsum[i - k + h][j + x] - Prefsum[i - k + h][j - x - 1];
                    else if (j - x < 1 && j + x <= n)
                        curret_res += Prefsum[i - k + h][j + x] - Prefsum[i - k + h][0];
                    else if (j - x >= 1 && j + x > n)
                        curret_res += Prefsum[i - k + h][n] - Prefsum[i - k + h][j - x - 1];

                    else if (j - x < 1 && j + x > n)
                        curret_res += Prefsum[i - k + h][n] - Prefsum[i - k + h][0];
                }
                if (h < k)
                    zakres += 2;
                else
                    zakres -= 2;
            }
            mx = max(mx, curret_res);
        }

    fout << mx;
    fout.close(), fin.close();
    return 0;
}