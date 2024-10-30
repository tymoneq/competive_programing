#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 20, MAXMASK = 1 << 20;

ll dp[N][MAXMASK];

inline int convert_mask(string s)
{

    int mask = 0;
    int power_of_two = 1;

    for (int i = s.size() - 1; i >= 0; i--)
    {

        if (s[i] == '1')
            mask += power_of_two;
        power_of_two *= 2;
    }
    return mask;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, z, q, k;
    string s;
    cin >> n;
    vector<pair<int, int>> Mecze(n);

    for (int i = 0; i < n; i++)
        cin >> Mecze[i].first;
    for (int i = 0; i < n; i++)
        cin >> Mecze[i].second;

    cin >> z;

    vector<pair<int, int>> Zaklady(z);
    for (int i = 0; i < z; i++)
    {

        cin >> s >> k;
        Zaklady[i] = {convert_mask(s), k};
    }

    // dp

    cin >> q;
    while (q--)
    {
        cin >> s;
        int mask = convert_mask(s);

        cout << dp[n][mask] << 1 << "\n";
    }

    return 0;
}