#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e6 + 10;
bool Wybredny[M];
int Sajz[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Sajz[1] = Sajz[2] = 1;
    int q, cur = 2, a;
    char oper;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> oper >> a;
        if (oper == '?')
            cout << (Wybredny[a] ? 1 : Sajz[a]) << "\n";
        else if (oper == 'Z')
        {
            cur++;
        }
        else if (oper == 'W')
        {
            cur++;
        }
    }
    return 0;
}