#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
public:
};
multiset<int> AktualneWartosci;
int m;
const char Dodaj = '+';
const char Odejmij = '-';
const char Zapytaj = '?';

inline int find_best()
{
    int mx = 0;

    auto head = AktualneWartosci.begin();
    auto tail = AktualneWartosci.begin();
    mx = 1;
    int current_best = 1;

    while (head != AktualneWartosci.end())
    {
        auto next_move = head;
        next_move++;
        if (next_move == AktualneWartosci.end())
            break;

        if ((*tail) * 2 >= *next_move)
        {
            head = next_move;
            current_best++;
        }
        else if ((*tail) * 2 < *next_move)
        {
            current_best--;
            tail++;
        }
        mx = max(mx, current_best);
    }

    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;

    while (m--)
    {
        char operacja;
        int val;
        cin >> operacja;

        if (operacja == Dodaj)
        {
            cin >> val;
            AktualneWartosci.insert(val);
        }
        else if (operacja == Odejmij)
        {
            cin >> val;
            auto it = AktualneWartosci.find(val);
            AktualneWartosci.erase(it);
        }
        else if (operacja == Zapytaj)
        {
            cout << find_best() << "\n";
        }
    }

    return 0;
}