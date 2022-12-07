#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr ull mian = 1 << 30;

struct beachgoer
{
    ull distance = 0;
    int poz_start = 0;
    int how_many = 0;
};
void lower(pair<ull, ull> &el)
{
    while (el.first % 2 == 0 && el.second != 1)
    {
        el.first /= 2;
        el.second /= 2;
    }
}
void add_new_beachgoer(beachgoer &current_beachgoer, queue<beachgoer> &q, vector<beachgoer> &Plaz)
{
    current_beachgoer.distance /= 2;
    current_beachgoer.how_many *= 2;
    q.push(current_beachgoer);
    Plaz.erase(Plaz.begin());
}
void add_new_beachgoer_2(beachgoer &new_beachgoer, queue<beachgoer> &q)
{
    new_beachgoer.distance /= 2;
    new_beachgoer.how_many *= 2;
    q.push(new_beachgoer);
    q.pop();
}
inline bool sort_inquiries(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.second < rhs.second; }
inline bool sort_beachgoer(const beachgoer &lhs, const beachgoer &rhs)
{
    if (lhs.distance > rhs.distance)
        return true;
    if (lhs.distance == rhs.distance && lhs.poz_start < rhs.poz_start)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull tmp;
    int n, X, z, a, current, prev;
    cin >> n >> X >> z;
    beachgoer current_beachgoer, new_beachgoer;
    vector<beachgoer> Plaz;
    vector<pair<int, int>> Inuqiries(z); // first -> index second -> val
    vector<pair<ull, ull>> Res(z);       // first -> index second -> val
    queue<beachgoer> q;
    // preparing date
    for (int i = 0; i < n; i++)
    {
        cin >> current;
        if (i != 0)
        {
            current_beachgoer.poz_start = prev;
            current_beachgoer.how_many = 1;
            current_beachgoer.distance = (current - prev) * mian;
            Plaz.push_back(current_beachgoer);
        }
        prev = current;
    }
    for (int i = 0; i < z; i++)
    {
        cin >> a;
        Inuqiries[i] = make_pair(i, a);
    }
    // sorting
    sort(Inuqiries.begin(), Inuqiries.end(), sort_inquiries);
    sort(Plaz.begin(), Plaz.end(), sort_beachgoer);
    int i = 0, calc_positon = 0;
    ull fix_poz = 0;
    while (Inuqiries.size() > 0)
    {
        if (Plaz.size() > 0)
        {
            current_beachgoer = Plaz[0];
            if (q.size() > 0)
            {
                new_beachgoer = q.front();
                if (current_beachgoer.distance > new_beachgoer.distance || (current_beachgoer.distance == new_beachgoer.distance && current_beachgoer.poz_start < new_beachgoer.poz_start))
                {
                    tmp = current_beachgoer.how_many;
                    i += current_beachgoer.how_many * 2 - tmp;
                    add_new_beachgoer(current_beachgoer, q, Plaz);
                    if (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                        while (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                        {
                            calc_positon = current_beachgoer.how_many - tmp - (i - Inuqiries[0].second);
                            fix_poz = current_beachgoer.poz_start * mian + current_beachgoer.distance * (1 + 2 * (calc_positon - 1));
                            Res[Inuqiries[0].first] = (make_pair(fix_poz, mian));
                            Inuqiries.erase(Inuqiries.begin());
                        }
                }

                else if (current_beachgoer.distance < new_beachgoer.distance || (current_beachgoer.distance == new_beachgoer.distance && current_beachgoer.poz_start > new_beachgoer.poz_start))
                {
                    tmp = new_beachgoer.how_many;
                    i += new_beachgoer.how_many * 2 - tmp;
                    add_new_beachgoer_2(new_beachgoer, q);
                    if (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                        while (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                        {
                            calc_positon = new_beachgoer.how_many - tmp - (i - Inuqiries[0].second);
                            fix_poz = new_beachgoer.poz_start * mian + new_beachgoer.distance * (1 + 2 * (calc_positon - 1));
                            Res[Inuqiries[0].first] = (make_pair(fix_poz, mian));
                            Inuqiries.erase(Inuqiries.begin());
                        }
                }
            }
            else
            {
                tmp = current_beachgoer.how_many;
                i += current_beachgoer.how_many * 2 - tmp;
                add_new_beachgoer(current_beachgoer, q, Plaz);
                if (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                    while (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                    {
                        calc_positon = current_beachgoer.how_many - tmp - (i - Inuqiries[0].second);
                        fix_poz = current_beachgoer.poz_start * mian + current_beachgoer.distance * (1 + 2 * (calc_positon - 1));
                        Res[Inuqiries[0].first] = (make_pair(fix_poz, mian));
                        Inuqiries.erase(Inuqiries.begin());
                    }
            }
        }
        else
        {
            new_beachgoer = q.front();
            tmp = new_beachgoer.how_many;
            i += new_beachgoer.how_many * 2 - tmp;
            add_new_beachgoer_2(new_beachgoer, q);
            if (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                while (Inuqiries.size() > 0 && i >= Inuqiries[0].second)
                {
                    calc_positon = new_beachgoer.how_many - tmp - (i - Inuqiries[0].second);
                    fix_poz = new_beachgoer.poz_start * mian + new_beachgoer.distance * (1 + 2 * (calc_positon - 1));
                    Res[Inuqiries[0].first] = (make_pair(fix_poz, mian));
                    Inuqiries.erase(Inuqiries.begin());
                }
        }
    }

    for (auto el : Res)
    {
        lower(el);
        cout << el.first << "/" << el.second << "\n";
    }

    return 0;
}