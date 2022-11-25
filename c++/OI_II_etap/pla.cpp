#include <bits/stdc++.h>
using namespace std;
struct distances_between
{
    int licz = 0;
    int mian = 0;
    int left_licznik = 0;
    int left_mian = 0;
    int right_licznik = 0;
    int right_mian = 0;
};
void lower(distances_between &el)
{
    while (el.licz % 2 == 0 && el.mian != 1)
    {
        el.licz /= 2;
        el.mian /= 2;
    }
    while (el.left_licznik % 2 == 0 && el.left_mian != 1)
    {
        el.left_licznik /= 2;
        el.left_mian /= 2;
    }
    while (el.right_licznik % 2 == 0 && el.right_mian != 1)
    {
        el.right_licznik /= 2;
        el.right_mian /= 2;
    }
}
int Euklides(int a, int b)
{
    int tmp;
    while (a != b && b != 0 && a != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
inline int NWW(int a, int b) { return a * b / Euklides(a, b); }
struct myComp
{
    bool operator()(distances_between &lhs, distances_between &rhs)
    {
        int nww_d = NWW(lhs.mian, rhs.mian);
        int nww_l = NWW(lhs.left_mian, rhs.left_mian);
        int l_m = nww_d / lhs.mian;
        int r_m = nww_d / rhs.mian;
        int l_l = nww_l / lhs.left_mian;
        int r_l = nww_l / rhs.left_mian;
        if (lhs.licz * l_m < rhs.licz * r_m)
            return true;
        else if (lhs.licz * l_m == rhs.licz * r_m && lhs.left_licznik * l_l < rhs.left_licznik * r_l)
            return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, X, z;
    cin >> n >> X >> z;
    vector<int> position(n); // wczytanie danych
    priority_queue<distances_between, vector<distances_between>, myComp> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
        if (i != 0 || (i == n - 1 && position[i] == X))
        {
            distances_between ds_b;
            ds_b.licz = position[i] - position[i - 1];
            ds_b.mian = 2;
            ds_b.left_licznik = position[i - 1];
            ds_b.left_mian = 1;
            ds_b.right_licznik = position[i];
            ds_b.right_mian = 1;
            lower(ds_b);
            pq.push(ds_b);
        }
        else if (i == n - 1)
        {
            distances_between ds_b;
            ds_b.licz = position[i] - position[i - 1];
            ds_b.mian = 2;
            ds_b.left_licznik = position[i];
            ds_b.left_mian = 1;
            ds_b.right_licznik = 0;
            ds_b.right_mian = 1;
            lower(ds_b);
            pq.push(ds_b);
        }
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < z; i++)
    {
        int a;
        cin >> a;
        if (a <= res.size())
            cout << res[a - 1].first << "/ " << res[a - 1].second << "\n";
        else
        {
            for (int j = 0; j < a - res.size(); j++)
            {
                distances_between ds_b = pq.top();
                pq.pop();
                distances_between ds_left;
                distances_between ds_right;
                if (ds_b.right_licznik == 0)
                {
                    res.push_back(make_pair(X, 1));
                    ds_right.left_licznik = ds_b.left_licznik;
                    ds_right.left_mian = ds_b.left_mian;
                    ds_right.right_licznik = X;
                    ds_right.right_mian = 1;
                    ds_right.licz = ds_b.licz;
                    ds_right.mian = 2 * ds_b.mian;
                    lower(ds_right);
                    pq.push(ds_right);
                }
                else
                {
                    ds_left.left_licznik = ds_b.left_licznik;
                    ds_left.left_mian = ds_b.left_mian;
                    ds_right.right_licznik = ds_b.right_licznik;
                    ds_right.right_mian = ds_b.right_mian;
                    int nww_b_l = NWW(ds_left.left_mian, ds_b.mian); // wspólny mianownik punktów
                    int nww_b_r = NWW(ds_right.right_mian, ds_b.mian);
                    // sprawdzenie ile razy trzeba pomnożyć licznik
                    int l_m = ds_left.left_mian / nww_b_l;
                    int b_m_1 = ds_b.mian / nww_b_l;
                    int r_m = ds_right.right_mian / nww_b_r;
                    int b_m_2 = ds_b.mian / nww_b_r;
                    // dodaj liczenie nowych punktów i dodawanie ich to pq
                }
            }
            cout << res[a - 1].first << "/ " << res[a - 1].second << "\n";
        }
    }

    return 0;
}