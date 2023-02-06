#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_set<int> S;
    int n, a, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        S.insert(a);
    }
    cin >> k;
    unordered_set<int> M;
    vector<int> Querry(k);
    int mx = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> Querry[i];
        mx = max(mx, Querry[i]);
    }
    bool fint = 0;
    int j;
    for (int i = 0; i <= mx; i++)
    {
        if (S.count(i))
            M.insert(i);
        else
        {
            fint = 0;
            for (j = i - 1; j >= i / 2; j--)
                if (M.count(j) && M.count(i - j))
                {
                    fint = 1;
                    break;
                }
            if (fint)
                M.insert(i);
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (M.count(Querry[i]) || Querry[i] == 0)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }

    return 0;
}