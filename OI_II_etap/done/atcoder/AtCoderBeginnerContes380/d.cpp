#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int q;
    cin >> s >> q;

    set<int> Normal, Reversed;
    Normal = {0, 3, 5, 6};
    Reversed = {1, 2, 4, 7};

    while (q--)
    {
        ll zapytanie;
        cin >> zapytanie;

        zapytanie--;

        ll indxWCiago = zapytanie % (ll)s.size();
        ll pozycja = zapytanie % (ll)(8 * s.size());
        ll segment = zapytanie % (64 * s.size());
        segment /= (8 * s.size());
        pozycja /= s.size();

        if (Normal.count(segment))
        {
            if (Normal.count(pozycja))
                cout << s[indxWCiago] << " ";

            else
            {
                char ans;
                if (s[indxWCiago] < 97)
                    ans = s[indxWCiago] + 32;

                else
                    ans = s[indxWCiago] - 32;

                cout << ans << ' ';
            }
        }
        else
        {
            if (Normal.count(pozycja))
            {
                char ans;
                if (s[indxWCiago] < 97)
                    ans = s[indxWCiago] + 32;

                else
                    ans = s[indxWCiago] - 32;

                cout << ans << ' ';
            }
            else
                cout << s[indxWCiago] << " ";
        }
    }
    cout << "\n";

    return 0;
}