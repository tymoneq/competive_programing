#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 1e5 * 3 + 10;
int Power_of_pok[MAX_VAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, q;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> q;
        for (int j = 0; j < n; j++)
            cin >> Power_of_pok[j];
        
    }

    return 0;
}