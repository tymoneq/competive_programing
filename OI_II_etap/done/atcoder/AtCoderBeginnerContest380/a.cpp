#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    unordered_map<int, int> cnt;
    for (int i = 0; i < s.size(); i++)
        cnt[s[i] - '0']++;

    bool T = 1;

    if (cnt[1] != 1)
        T = 0;
    if (cnt[2] != 2)
        T = 0;
    if (cnt[3] != 3)
        T = 0;

    cout << (T ? "Yes" : "No") << "\n";

    return 0;
}