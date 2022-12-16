#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int W, S;
    cin >> W >> S;
    vector<int> Wagon(W);
    for (int i = 0; i < W; i++)
        cin >> Wagon[i];
    long long glowa = 0, ogon = 0, res = numeric_limits<int>::max(), akt_sum = 0;
    while (glowa < W)
    {
        if (akt_sum + Wagon[glowa] < S)
        {
            glowa++;
            akt_sum += Wagon[glowa - 1];
        }
        else if (akt_sum + Wagon[glowa] > S)
        {
            ogon++;
            akt_sum -= Wagon[ogon - 1];
        }
        else if (akt_sum + Wagon[glowa] == S)
        {
            res = min(res, glowa - ogon + 1);
            glowa++;
            akt_sum += Wagon[glowa - 1];
        }
    }
    if (res != numeric_limits<int>::max())
        cout << res;
    else
        cout << "N";
    return 0;
}