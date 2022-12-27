#include <bits/stdc++.h>

using namespace std;
const int MAX_val = 2e5 + 10;
map<int, int> m[MAX_val];
int s[MAX_val];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, i, j;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1;
    }
    for (i = 0; i < n; i++)
        cin >> s[i];
    for (i = 0, j = 1; i < n; i++)
        while (m[s[i]][s[j]])
            j++;
    if (j == n && s[0] == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}