#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin.open("swap.in"), fout.open("swap.out");
    int n, k, a1, a2, b1, b2;
    fin >> n >> k >> a1 >> a2 >> b1 >> b2;
    vector<int> Cows(n + 1);
    for (int i = 1; i <= n; i++)
        Cows[i] = i;

    int cycle_lenght = 0, tmp = 0, v;
    bool isCycle = 1;
    while (cycle_lenght < k)
    {
        tmp = 0;
        for (int i = a1; i <= a1 + (a2 - a1) / 2; i++)
            swap(Cows[i], Cows[a2 - tmp]), tmp++;
        tmp = 0;
        for (int i = b1; i <= b1 + (b2 - b1) / 2; i++)
            swap(Cows[i], Cows[b2 - tmp]), tmp++;
        cycle_lenght++;
        for (int i = 1; i <= n; i++)
        {
            if (Cows[i] == i)
                isCycle = 1;
            else
            {
                isCycle = 0;
                break;
            }
        }
        if (isCycle)
        {
            v = k % cycle_lenght;
            cycle_lenght = 0;
            k = v;
        }
    }
    for (int i = 1; i <= n; i++)
        fout << Cows[i] << "\n";
    fin.close(), fout.close();
    return 0;
}