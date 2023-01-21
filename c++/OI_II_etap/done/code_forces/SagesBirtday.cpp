#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> Num(n);
    for (int i = 0; i < n; i++)
        cin >> Num[i];
    sort(Num.begin(), Num.end());
    vector<int> Res;
    int index = n - 1;
    Res.push_back(Num[index]);
    index--;
    int r = 0;
    while (index >= 0)
    {
        if (index == 0)
        {
            Res.push_back(Num[index]);
            index--;
        }
        else
        {
            Res.push_back(Num[index - 1]), Res.push_back(Num[index]);
            r++;
            index -= 2;
        }
    }
    cout << r << "\n";
    for (int w : Res)
        cout << w << ' ';

    return 0;
}