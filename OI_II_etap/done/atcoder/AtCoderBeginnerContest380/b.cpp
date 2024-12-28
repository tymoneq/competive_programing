#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int l = 0, cnt = 0;

    vector<int> ans;
    while (l < s.size())
    {
        if (s[l] == '|')
        {
            ans.push_back(cnt);
            cnt = 0;
        }
        else
            cnt++;
        l++;
    }
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}