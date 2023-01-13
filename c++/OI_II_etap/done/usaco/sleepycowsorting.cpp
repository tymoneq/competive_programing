#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("sleepy.in"), fout.open("sleepy.out");
    int n;
    fin >> n;
    vector<int> Cows(n + 1);
    vector<int> Sort_cows(n + 1);
    int x = 1;
    for (int i = 1; i <= n; i++)
        fin >> Cows[i];
    for (int i = n - 1; i > 0; i--)
    {
        if (Cows[i] < Cows[i + 1])
            x++;
        else
            break;
    }
    fout << n - x;
    fout.close(), fin.close();
    return 0;
}