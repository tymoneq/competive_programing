#include <bits/stdc++.h>

using namespace std;
int res, n, X;
vector<int> Makarony;
void calcRes(int num, int M, int ind)
{
    if (M == 1)
    {
        if (num * 10 > X)
            return;
        for (int i = ind + 1; i < n; i++)
            if (num * 10 + Makarony[i] <= X && num * 10 + Makarony[i] > res)
                res = num * 10 + Makarony[i];
    }
    else
        for (int i = ind + 1; i <= n - M; i++)
            calcRes((num * 10 + Makarony[i]), M - 1, i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    Makarony.resize(n);
    char z;
    for (int i = 0; i < n; i++)
    {
        cin >> z;
        Makarony[i] = z - '0';
    }
    cin >> X;
    for (int i = 0; i < n; i++)
    {
        calcRes(Makarony[i], m - 1, i);
        calcRes(Makarony[i], m - 2, i);
    }

    cout << res;
    return 0;
}