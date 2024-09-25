#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;

    int cnt = 0, current_cnt = 0;
    pair<char, int> MXpas;
    cin >> s;

    current_cnt = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == s[i])
        {
            current_cnt++;
            if (MXpas.second < current_cnt && current_cnt >= 10)
                MXpas = {s[i], current_cnt};
        }
        else
        {
            if (current_cnt >= 10)
                cnt++;
            current_cnt = 1;
        }
    }

    cout << cnt << " " << MXpas.first << " " << MXpas.second << "\n";
    return 0;
}