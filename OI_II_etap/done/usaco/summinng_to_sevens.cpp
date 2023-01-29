#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 7;
long long PRefsum[M];
ifstream fin;
ofstream fout;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fin.open("div7.in"), fout.open("div7.out");
    int n, a;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a;
        PRefsum[i] += PRefsum[i - 1] + a;
    }
    int res = 0;
    for (int i = n; i > 0; i--)
        if (res < i)
            for (int j = 0; j < i; j++)
            {
                if (res > i - j)
                    break;

                if ((PRefsum[i] - PRefsum[j]) % 7 == 0)
                    res = max(res, i - j);
            }

    fout << res;
    fin.close(), fout.close();
    return 0;
}