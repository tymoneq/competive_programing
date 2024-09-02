#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, s, tmp;
    vector<int> MIN, MAX;
    cin >> m >> s;

    if (s == 0 && m == 1)
    {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }
    if (s == 0 || m * 9 < s)
    {
        cout << -1 << " " << -1 << "\n";
        return 0;
    }
    tmp = s - 1;
    for (int i = 1; i < m; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (tmp == 0)
            {
                MIN.push_back(0);
                break;
            }

            if (j < 9 && tmp - (j + 1) < 0)
            {
                MIN.push_back(j);
                tmp -= j;
                break;
            }
            if (j == 9)
            {
                MIN.push_back(j);
                tmp -= j;
            }
        }

    MIN.push_back(1 + tmp);

    tmp = s;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (tmp == 0)
            {
                MAX.push_back(0);
                break;
            }
            if (j < 9 && tmp - (j + 1) < 0)
            {
                MAX.push_back(j);
                tmp -= j;
                break;
            }
            if (j == 9)
            {
                MAX.push_back(j);
                tmp -= j;
            }
        }

    for (int i = MIN.size() - 1; i >= 0; i--)
        cout << MIN[i];

    cout << " ";
    for (auto i : MAX)
        cout << i;
    cout << "\n";
    return 0;
}