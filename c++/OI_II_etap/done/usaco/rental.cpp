#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("rental.in", "r", stdin);
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> milk_amt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> milk_amt[i];
    }

    vector<pair<int, int>> shops(m);
    for (int i = 0; i < m; i++)
    {
        cin >> shops[i].second >> shops[i].first;
    }

    vector<int> rent(r);
    for (int i = 0; i < r; i++)
    {
        cin >> rent[i];
    }

    sort(milk_amt.begin(), milk_amt.end(), greater<int>());
    sort(shops.begin(), shops.end(), greater<pair<int, int>>());
    sort(rent.begin(), rent.end(), greater<int>());
    int shop_at = 0;
    int rent_at = 0;
    int cow_at = 0;
    long long max_money = 0;
    while (cow_at < n)
    {
        int amt = milk_amt[cow_at];
        int sold_money = 0;
        int curr_shop = shop_at;
        int last = 0;

        while (curr_shop < m)
        {
            int sold = min(amt, shops[curr_shop].second);
            sold_money += shops[curr_shop].first * sold;
            amt -= sold;

            if (amt == 0)
            {
                last = sold;
                break;
            }
            else
            {
                curr_shop++;
            }
        }

        if (rent_at >= r || sold_money > rent[rent_at])
        {
            max_money += sold_money;
            shop_at = curr_shop;
            if (shop_at < m)
            {
                shops[shop_at].second -= last;
            }
            cow_at++;
        }
        else
        {
            max_money += rent[rent_at];
            n--;
            rent_at++;
        }
    }

    freopen("rental.out", "w", stdout);
    cout << max_money << endl;
}