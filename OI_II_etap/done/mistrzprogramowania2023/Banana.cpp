#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    long long n;
    cin >> T;
    vector<char> Res;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        Res.clear();
        while (n > 0)
        {
            n-= 1;
            Res.push_back('A' + (n % 26));
            n /= 26;
        }
        for (int j = Res.size() - 1; j >= 0; j--)
            cout << Res[j];
        cout << "\n";
    }
    return 0;
}