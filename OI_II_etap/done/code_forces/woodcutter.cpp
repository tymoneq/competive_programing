#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;
int Locations[N], Height[N];
bool Cutted[N];
char TreeFelt[N]; // L - left -R - right
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, res = 2;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> Locations[i] >> Height[i];

    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        // Checked Left site
        if (Locations[i] - Height[i] > Locations[i - 1] + (Cutted[i - 1] && TreeFelt[i - 1] == 'R' ? Height[i - 1] : 0))
        {
            ++res;
            Cutted[i] = 1;
            TreeFelt[i] = 'L';
        }
        else if (Locations[i] + Height[i] < Locations[i + 1])
        {
            ++res;
            Cutted[i] = 1;
            TreeFelt[i] = 'R';
        }
    }

    cout << res << "\n";
    return 0;
}