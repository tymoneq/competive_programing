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
    vector<int> Res(n);
    for (int i = 0; i < n; i++)
        cin >> Num[i];
    if (Num[0] == 1)
        cout << "No";
    else
    {
        cout << "Yes\n";
    }
    return 0;
}