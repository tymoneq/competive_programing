#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    string s;
    cin >> n >> l >> s;
    vector<int> Nawozy(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> Nawozy[i];
    int d_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'D')
            Nawozy[s[i] - '0']--;

        else
            d_count++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Nawozy[i] < 0)
        {
            cout << "NIE";
            return 0;
        }
        else
            sum += Nawozy[i];
    }
    cout << (sum >= d_count ? "TAK" : "NIE");
    return 0;
}