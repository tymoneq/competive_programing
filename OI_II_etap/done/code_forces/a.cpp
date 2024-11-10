#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, a, b;
    string s;

    pair<int, int> last;
    cin >> t;

    while (t--)
    {
        cin >> n >> a >> b >> s;
        int x = 0, y = 0;
        int run = 0;
        bool Correct = 0;
        while (run < 10'000)
        {
            run++;
            for (int i = 0; i < n; i++)
            {
                if (x == a && y == b)
                {
                    Correct = 1;
                    break;
                }

                if (s[i] == 'N')
                    y++;
                else if (s[i] == 'S')
                    y--;

                else if (s[i] == 'E')
                    x++;
                else if (s[i] == 'W')
                    x--;
            }
            if (Correct)
                break;
        }

        cout << (Correct ? "YES" : "NO") << "\n";
    }

    return 0;
}