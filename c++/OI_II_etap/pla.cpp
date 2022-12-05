#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull fix_dist = 0;
constexpr ull mian = 1 << 30;
int fix_calc = 0;
bool finded = false;
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
void add_new_beachgoer(beachgoer &current_beachgoer, queue<beachgoer> &q, vector<beachgoer> &Plaz, int &i, vector<pair<int, int>> &Inuqiries, vector<pair<int, ull>> &Res)
{
    int tmp = current_beachgoer.how_many;
    current_beachgoer.distance /= 2;
    current_beachgoer.how_many *= 2;
    i += current_beachgoer.how_many - tmp;
    if (i >= Inuqiries[0].second && !finded)
    {
        fix_calc = i - Inuqiries[0].second;
        fix_dist = current_beachgoer.poz_start * mian + current_beachgoer.distance * (current_beachgoer.how_many - fix_calc);
        Res.push_back(make_pair(Inuqiries[0].first, fix_dist));
        Inuqiries.erase(Inuqiries.begin());
    }
    q.push(current_beachgoer);
    Plaz.erase(Plaz.begin());
}
void add_new_beachgoer_2(beachgoer &new_beachgoer, queue<beachgoer> &q, int &i, vector<pair<int, int>> &Inuqiries, vector<pair<int, ull>> &Res)
{
    int tmp = new_beachgoer.how_many;
    new_beachgoer.distance /= 2;
    new_beachgoer.how_many *= 2;
    i += new_beachgoer.how_many - tmp;
    if (i >= Inuqiries[0].second && !finded)
    {
        fix_calc = i - Inuqiries[0].second;
        fix_dist = new_beachgoer.poz_start * mian + new_beachgoer.distance * (new_beachgoer.how_many - fix_calc);
        Res.push_back(make_pair(Inuqiries[0].first, fix_dist));
        Inuqiries.erase(Inuqiries.begin());
    }
    q.push(new_beachgoer);
    q.pop();
}
inline bool sort_inquiries(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.second < rhs.second; }
inline bool sort_res(pair<int, ull> &lhs, pair<int, ull> &rhs) { return lhs.first < rhs.first; }
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
    vector<pair<int, ull>> Res;          // first -> index second -> val
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
    int i = 1;
    while (i <= Inuqiries[0].second && Inuqiries.size() > 0)
    {
        if (Inuqiries[0].second == i)
        {
            if (Plaz.size() == 0)
            {
                tmp = q.front().distance / 2 + (q.front().poz_start * mian);
                Res.push_back(make_pair(Inuqiries[0].first, tmp / 2));
                Inuqiries.erase(Inuqiries.begin());
            }
            else if (q.size() > 0 && q.front().distance > Plaz[0].distance || (q.front().distance == Plaz[0].distance && q.front().poz_start < Plaz[0].poz_start))
            {
                tmp = q.front().distance / 2 + (q.front().poz_start * mian);
                Res.push_back(make_pair(Inuqiries[0].first, tmp));
                Inuqiries.erase(Inuqiries.begin());
            }
            else if (q.front().distance < Plaz[0].distance || (q.size() == 0 || (q.front().distance == Plaz[0].distance && q.front().poz_start > Plaz[0].poz_start)))
            {
                tmp = Plaz[0].distance / 2 + (Plaz[0].poz_start * mian);
                Res.push_back(make_pair(Inuqiries[0].first, tmp));
                Inuqiries.erase(Inuqiries.begin());
            }
            finded = true;
        }
        if (Plaz.size() > 0)
        {
            current_beachgoer = Plaz[0];
            if (q.size() > 0)
            {
                new_beachgoer = q.front();
                if (current_beachgoer.distance > new_beachgoer.distance || (current_beachgoer.distance == new_beachgoer.distance && current_beachgoer.poz_start < new_beachgoer.poz_start))
                    add_new_beachgoer(current_beachgoer, q, Plaz, i, Inuqiries, Res);

                else if (current_beachgoer.distance < new_beachgoer.distance || (current_beachgoer.distance == new_beachgoer.distance && current_beachgoer.poz_start > new_beachgoer.poz_start))
                    add_new_beachgoer_2(new_beachgoer, q, i, Inuqiries, Res);
            }
            else
                add_new_beachgoer(current_beachgoer, q, Plaz, i, Inuqiries, Res);
        }
        else
        {
            new_beachgoer = q.front();
            add_new_beachgoer_2(new_beachgoer, q, i, Inuqiries, Res);
        }
        finded = false;
    }
    sort(Res.begin(), Res.end(), sort_res);
    pair<ull, ull> lowerrr;
    for (auto el : Res)
    {
        lowerrr.first = el.second;
        lowerrr.second = mian;
        lower(lowerrr);
        cout << lowerrr.first << "/" << lowerrr.second << "\n";
    }

    return 0;
}