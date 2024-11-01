#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, mx = 0;
    string s;

    cin >> n >> k >> s;

    vector<int> A;
    char prev = s[0];
    A.push_back(0);

    for (int i = 1; i < n; i++)
        if (s[i] != prev)
        {
            A.push_back(i);
            prev = s[i];
        }

    int l = 0, r = 0, tmpk = 0, current_mx = 0, indx = 0;

    while (l < n)
    {
        tmpk = k;
        current_mx = 1;
        r = l + 1;
        while (tmpk >= 0)
        {
            if (r < n && s[r] == s[l])
            {
                current_mx++;
                r++;
            }
            else if (r < n && s[r] != s[l] && tmpk > 0)
            {
                current_mx++;
                r++;
                tmpk--;
            }
            else if (r == n || tmpk == 0)
            {
                break;
            }
        }
        indx++;
        if (indx == A.size())
            l = n;
        else
            l = A[indx];

        mx = max(mx, current_mx);
    }

    cout << mx << "\n";

    return 0;
}