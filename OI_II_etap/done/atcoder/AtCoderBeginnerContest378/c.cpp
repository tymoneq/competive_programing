#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> ANS(n + 1), A(n + 1);
    map<int, int> MAPA;

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    for (int i = 1; i <= n; i++)
    {
        if (MAPA.find(A[i]) == MAPA.end())
        {
            ANS[i] = -1;
            MAPA[A[i]] = i;
        }
        else
        {
            ANS[i] = MAPA[A[i]];
            MAPA[A[i]] = i;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ANS[i] << " ";

    cout << "\n";

    return 0;
}