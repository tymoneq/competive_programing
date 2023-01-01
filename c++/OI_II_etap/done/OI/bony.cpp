#include <bits/stdc++.h>
using namespace std;
const int M = 1.2e6;
bool Sweets[M];
bool Bons[M];
int Tab[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, b, n, k, c;
    vector<long long> Res;
    long long wynik = 0, current_clients = 1;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        Bons[b] = 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (Tab[k] == -1)
        {
            current_clients += k;
            continue;
        }
        b = k;
        c = k;
        if (Tab[k] != 0)
            b = Tab[k];
        while (k > 0)
        {
            if (b > 1e6)
            {
                Tab[c] = -1;
                current_clients += k;
                break;
            }
            if (!Sweets[b])
            {
                if (Bons[b])
                {
                    wynik++;
                    Res.push_back(current_clients);
                }
                k--;
                current_clients++;
                Sweets[b] = 1;
            }
            Tab[c] = b;
            b += c;
        }
    }
    cout << wynik << "\n";
    for (long long r : Res)
        cout << r << '\n';
    return 0;
}