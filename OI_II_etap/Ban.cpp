#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    long long n;
    cin >> t;
    unordered_map<int, string> M;
    string s;
    int ind = 0;
    for (int i = 1; i <= 800; i++)
    {
        M[i] = s;
        M[i] += 'A' + ind;
        ind++;
        if (i % 26 == 0)
        {
            int tmp = i / 26;
            s = 'A' + (tmp - 1);
            ind = 0;
        }
    }
    for (int T = 0; T < t; T++)
    {
        cin >> n;
        cout << M[n] << "\n";
    }
    return 0;
}