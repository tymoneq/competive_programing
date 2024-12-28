#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
char flip(char c)
{
    if ('a' <= c && c <= 'z')
    {
        return (c - 'a') + 'A';
    }
    else
    {
        return (c - 'A') + 'a';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int q;
    cin >> s >> q;

    while (q--)
    {
        ll zapytanie;
        cin >> zapytanie;

        zapytanie--;

        ll indxWCiago = zapytanie % (ll)s.size();
        ll blk = zapytanie / s.size();

        if (__builtin_popcountll(blk) % 2)
            cout << flip(s[indxWCiago]);
        else
            cout << s[indxWCiago];

        cout << "\n";
    }
    return 0;
}