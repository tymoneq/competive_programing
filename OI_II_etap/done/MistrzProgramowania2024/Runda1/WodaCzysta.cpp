#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<char> Ans;
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        Ans.push_back(s[0]);
    }

    for (char a : Ans)
        cout << a;
    cout << '\n';
    return 0;
}