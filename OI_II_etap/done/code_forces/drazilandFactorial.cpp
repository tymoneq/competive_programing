#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string F[11];

inline bool sorto(int &l, int &r) { return l > r; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sum = 0, n;
    char a;
    vector<int> Res;

    F[2] = "2";
    F[3] = "3";
    F[4] = "322";
    F[5] = "5";
    F[6] = "53";
    F[7] = "7";
    F[8] = "7222";
    F[9] = "7332";

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a - '0' > 1)
            for (char k : F[a - '0'])
                Res.push_back(k - '0');
    }

    sort(Res.begin(), Res.end(), sorto);
    for (int e : Res)
        cout << e;

    cout << "\n";

    return 0;
}