#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, res, head, current_sum, indx;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> s;
        res = 0;
        head = -1;
        current_sum = 0;

        while (head < s.size() || head == -1)
        {
            head++;
            current_sum++;
            if (s[head] == '+')
            {
                indx = 1;
                while (indx >= 0 && head < s.size())
                {
                    current_sum++;
                    head++;
                    if (s[head] == '+')
                        indx++;
                    else
                        indx--;
                }
            }

            res += current_sum;
        }

        cout << res - 1 << "\n";
    }

    return 0;
}