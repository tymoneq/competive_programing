#include <bits/stdc++.h>

using namespace std;
int Znaki[30]; // klucz;
int slowo[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string s;
    char z;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        cin >> z;
        Znaki[z - 'a']++;
    }
    for (int i = 0; i < m - 1; i++)
        slowo[s[i] - 'a']++;
    bool corect = 0;
    vector<int> res;
    for (int i = m - 1; i < n; i++)
    {
        corect = 1;
        slowo[s[i] - 'a']++;
        for (int j = 0; j < 30; j++)
            if (Znaki[j] != slowo[j])
            {
                corect = 0;
                break;
            }
        if (corect)
            res.push_back(i - m + 2);
        slowo[s[i - m + 1] - 'a']--;
    }
    cout << res.size() << "\n";
    for (int w : res)
        cout << w << " ";

    return 0;
}