#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fin.tie();
    fin.open("taming.in"), fout.open("taming.out");
    int n;
    fin >> n;
    vector<int> Days(n);
    vector<int> Res(n, -1000);
    for (int i = 0; i < n; i++)
        fin >> Days[i];
    Res[0] = 0;
    for (int i = 1; i < n; i++)
    {
        Res[i] = Days[i];
        if (Days[i] > 0)
            for (int j = 1; j <= Days[i]; j++)
            {
                if (Res[i - j] == -1000 || Res[i - j] == -1)
                    Res[i - j] = Days[i] - j;
                else if (Res[i - j] != Days[i] - j)
                {
                    fout << -1;
                    fin.close(), fout.close();
                    return 0;
                }
            }
    }
    int mini = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (Res[i] == 0)
            mini++;
        if (Res[i] == -1)
            mx++;
    }
    fout << mini << " " << mini + mx;
    // fin.close(), fout.close();
    return 0;
}