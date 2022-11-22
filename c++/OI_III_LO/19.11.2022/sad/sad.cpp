#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll x_1, y_1, x_2, y_2, x_3, y_3;
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
    ll x_kwadr_1, y_kwadr_1, x_kwadr_2, y_kwadrat_2;
    x_kwadr_1 = min(x_1, min(x_2, x_3));
    y_kwadr_1 = min(y_1, min(y_2, y_3));
    x_kwadr_2 = max(x_1, max(x_2, x_3));
    y_kwadrat_2 = max(y_1, max(y_2, y_3));
    ll temp_wynik = (x_kwadr_2 - x_kwadr_1) * (y_kwadrat_2 - y_kwadr_1);
    if (x_1 != x_2 && y_2 != y_1)
    {
        // if (x_1 == x_kwadr_1 || x_1 == x_kwadr_2)
        // {
            ll point_x = x_kwadr_1;
            ll point_y = y_2;
            temp_wynik -= abs(point_y - y_1) * abs(point_x - x_2) / 2;
        // }
        // else if (x_2 == x_kwadr_1 || x_2 == x_kwadr_2)
        // {
        //     ll point_x = x_2;
        //     ll point_y = y_1;
        //     temp_wynik -= abs(point_y - y_2) * abs(point_x - x_1) / 2;
        // }
    }
    if (x_3 != x_2 && y_3 != y_2)
    {
        // if (x_2 == x_kwadr_1 || x_2 == x_kwadr_2)
        // {
            ll point_x = x_kwadr_1;
            ll point_y = y_3;
            temp_wynik -= abs(point_y - y_2) * abs(point_x - x_3) / 2;
        // }
        // else if (x_3 == x_kwadr_1 || x_3 == x_kwadr_2)
        // {
        //     ll point_x = x_3;
        //     ll point_y = y_2;
        //     temp_wynik -= abs(point_y - y_3) * abs(point_x - x_2) / 2;
        // }
    }
    if (x_1 != x_3 && y_3 != y_1)
    {
        // if (x_1 == x_kwadr_1 || x_1 == x_kwadr_2)
        // {
            ll point_x = x_kwadr_1;
            ll point_y = y_3;
            temp_wynik -= abs(point_y - y_1) * abs(point_x - x_3) / 2;
        //}
        // else if (x_3 == x_kwadr_1 || x_3 == x_kwadr_2)
        // {
        //     ll point_x = x_3;
        //     ll point_y = y_1;
        //     temp_wynik -= abs(point_y - y_1) * abs(point_x - x_1) / 2;
        // }
    }
    cout << temp_wynik - 3;
    return 0;
}