#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr ull mian = 1 << 30;
ull fix_poz = 0, calc_positon = 0;
int j = 0;
int index_plaz = 0;
struct beachgoer
{
    ull distance = 0;
    ull poz_start = 0;
    ull how_many = 0;
};
inline void add_new_beachgoer(beachgoer &current_beachgoer, queue<beachgoer> &q, vector<beachgoer> &Plaz)
{
    current_beachgoer.distance /= 2;
    current_beachgoer.how_many *= 2;
    q.push(current_beachgoer);
    index_plaz++;
}
inline void add_new_beachgoer_2(beachgoer &new_beachgoer, queue<beachgoer> &q)
{
    new_beachgoer.distance /= 2;
    new_beachgoer.how_many *= 2;
    q.push(new_beachgoer);
    q.pop();
}
inline void add_to_res(beachgoer &this_beachgoer, ull &tmp, ull &i, vector<pair<ull, ull>> &Inuqiries, vector<pair<ull, ull>> &Res)
{
    calc_positon = this_beachgoer.how_many - tmp - (i - Inuqiries[j].second);
    fix_poz = this_beachgoer.poz_start * mian + this_beachgoer.distance * (1 + 2 * (calc_positon - 1));
    Res[Inuqiries[j].first] = (make_pair(fix_poz, mian));
    j++;
}
inline bool sort_inquiries(pair<ull, ull> &lhs, pair<ull, ull> &rhs) { return lhs.second < rhs.second; }
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
    ull tmp, n, X, z, a, current, prev;
    cin >> n >> X >> z;
    beachgoer current_beachgoer, new_beachgoer;
    vector<beachgoer> Plaz;
    vector<pair<ull, ull>> Inuqiries(z); // first -> index second -> val
    vector<pair<ull, ull>> Res(z);       // first -> licznik second -> mian
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
    ull i = 0;
    while (Inuqiries.size() > j)
    {
        if (Plaz.size() > index_plaz)
        {
            current_beachgoer = Plaz[index_plaz];
            if (q.size() > 0)
            {
                new_beachgoer = q.front();
                if (current_beachgoer.distance > new_beachgoer.distance || (current_beachgoer.distance == new_beachgoer.distance && current_beachgoer.poz_start < new_beachgoer.poz_start))
                {
                    tmp = current_beachgoer.how_many;
                    i += current_beachgoer.how_many * 2 - tmp;
                    add_new_beachgoer(current_beachgoer, q, Plaz);
                    while (Inuqiries.size() > j && i >= Inuqiries[j].second)
                        add_to_res(current_beachgoer, tmp, i, Inuqiries, Res);
                }

                else
                {
                    tmp = new_beachgoer.how_many;
                    i += new_beachgoer.how_many * 2 - tmp;
                    add_new_beachgoer_2(new_beachgoer, q);
                    while (Inuqiries.size() > j && i >= Inuqiries[j].second)
                        add_to_res(new_beachgoer, tmp, i, Inuqiries, Res);
                }
            }
            else
            {
                tmp = current_beachgoer.how_many;
                i += current_beachgoer.how_many * 2 - tmp;
                add_new_beachgoer(current_beachgoer, q, Plaz);
                while (Inuqiries.size() > j && i >= Inuqiries[j].second)
                    add_to_res(current_beachgoer, tmp, i, Inuqiries, Res);
            }
        }
        else
        {
            new_beachgoer = q.front();
            tmp = new_beachgoer.how_many;
            i += new_beachgoer.how_many * 2 - tmp;
            add_new_beachgoer_2(new_beachgoer, q);
            while (Inuqiries.size() > j && i >= Inuqiries[j].second)
                add_to_res(new_beachgoer, tmp, i, Inuqiries, Res);
        }
    }

    for (auto el : Res)
    {
        while (el.first % 2 == 0 && el.second != 1) // można spróbować przyśpieszyć
        {
            el.first /= 2;
            el.second /= 2;
        }
        cout << el.first << "/" << el.second << "\n";
    }

    return 0;
}