#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    queue<string> kol;
    string oper, imie;
    for (int i = 0; i < n; i++)
    {
        cin >> oper;
        if (oper == "nowy")
        {
            cin >> imie;
            kol.push(imie);
        }
        if (oper == "zawolaj")
        {
            string name = kol.front();
            kol.pop();
            cout << name << "\n";
        }
        if (oper == "ile")
        {
            cout << kol.size() << "\n";
        }
    }

    return 0;
}