#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int lastVovelindex = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'o' || s[i] == 'u' || s[i] == 'i' || s[i] == 'a' || s[i] == 'e')
        {
            lastVovelindex = i;
            break;
        }

        if (s[i] == 'O' || s[i] == 'U' || s[i] == 'I' || s[i] == 'A' || s[i] == 'E')
        {
            lastVovelindex = i;
            break;
        }
    }

    for (int i = 0; i <= lastVovelindex; i++)
        cout << s[i];

    cout << "ntry\n";

    return 0;
}