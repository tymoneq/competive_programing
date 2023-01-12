#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    //fin.open("sleepy.in"), fout.open("sleepy.out");
    int n;
    cin >> n;
    vector<int> Cows(n + 1);
    vector<int> Sort_cows(n + 1);
    int pozmx = 0, N, tmp = 0;
    for (int i = 1; i <= n; i++)
        cin >> Cows[i];
    N = n;
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (Cows[i] == N)
            {
                pozmx = i;
                break;
            }
        }

        if (pozmx != N) // dodaj decydowanie którą wartość wziąć #mniejszą
        {
            res += pozmx;
            Sort_cows[N] = N;
            tmp = 1;
            for (int i = pozmx + 1; i <= n; i++)
            {
                if (Cows[i] < N)
                {
                    Sort_cows[tmp] = Cows[i];
                    tmp++;
                }
                else
                    break;
            }
            for (int i = 1; i < pozmx; i++)
            {
                Sort_cows[tmp] = Cows[i];
                tmp++;
            }
            Cows = Sort_cows;
        }
        else
            Sort_cows[N] = N;

        N--;
    }
    cout << res;
    fout.close(), fin.close();
    return 0;
}