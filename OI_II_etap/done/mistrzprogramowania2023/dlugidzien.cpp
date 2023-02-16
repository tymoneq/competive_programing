#include <bits/stdc++.h>

using namespace std;
struct monthh
{
    string s;
    int num, days;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int day;
    string month;
    map<string, pair<int, int>> M;
    cin >> day >> month;
    vector<monthh> Months(13);
    Months[1] = {"styczen", 1, 31};
    Months[2] = {"luty", 2, 29};
    Months[3] = {"marzec", 3, 31};
    Months[4] = {"kwiecien", 4, 30};
    Months[5] = {"maj", 5, 31};
    Months[6] = {"czerwiec", 6, 30};
    Months[7] = {"lipiec", 7, 31};
    Months[8] = {"sierpien", 8, 31};
    Months[9] = {"wrzesien", 9, 30};
    Months[10] = {"pazdziernik", 10, 31};
    Months[11] = {"listopad", 11, 30};
    Months[12] = {"grudzien", 12, 31};
    M["styczen"] = {1, 31};
    M["luty"] = {2, 29};
    M["marzec"] = {3, 31};
    M["kwiecien"] = {4, 30};
    M["maj"] = {5, 31};
    M["czerwiec"] = {6, 30};
    M["lipiec"] = {7, 31};
    M["sierpien"] = {8, 31};
    M["wrzesien"] = {9, 30};
    M["pazdziernik"] = {10, 31};
    M["listopad"] = {11, 30};
    M["grudzien"] = {12, 31};
    if (M[month].first < 6)
    {
        if (M[month].second > day)
            cout << day + 1 << " " << month;
        else
        {
            cout << 1 << " " << Months[M[month].first + 1].s;
        }
    }
    else if (M[month].first == 6)
    {
        if (day < 21)
            cout << day + 1 << " " << month;
        else if (day == 21)
            cout << "NOC SWIETOJANSKA!";
        else
            cout << 21 << " " << month;
    }
    else if (M[month].first < 9 || (M[month].first == 9 && day <= 22))
    {
        int dayss = 0;
        int m = M[month].first;
        dayss += day;
        m--;
        while (m > 6)
        {
            dayss += Months[m].days;
            m--;
        }
        dayss += 10;
        dayss -= 20;
        m--;
        while (dayss > 0)
        {
            if (Months[m].days == dayss)
            {

                cout << Months[m - 1].days << " " << Months[m - 1].s;
                break;
            }
            if (Months[m].days < dayss)
            {
                dayss -= Months[m].days;
                m--;
            }
            else if (Months[m].days > dayss)
            {
                if (Months[m].days - dayss - 1 == 1)
                    cout << 5 << " " << Months[m].s;
                else
                    cout << Months[m].days - dayss - 1 << " " << Months[m].s;
                break;
            }
        }
    }
    else if (M[month].first == 12)
    {
        if (day >= 21 && day < 31)
            cout << day + 1 << ' ' << Months[12].s;

        else if (day == 31)
            cout << 1 << " " << Months[1].s;
        else
        {
            int dayys = 21 - day;
            if (dayys < 10)
                cout << 21 + dayys + 1 << " "
                     << "grudzien";
            else
                cout << dayys - 9 << " "
                     << "styczen";
        }
    }
    else
    {
        int dayss = 0;
        int m = M[month].first;
        dayss += Months[m].days - day;
        m++;
        while (m < 12)
        {
            dayss += Months[m].days;
            m++;
        }
        dayss += 20;
        dayss -= 10;
        m = 1;
        while (dayss > 0)
        {
            if (Months[m].days == dayss)
            {

                cout << 1 << " " << Months[m + 1].s;
                break;
            }
            if (Months[m].days < dayss)
            {
                dayss -= Months[m].days;
                m++;
            }
            else if (Months[m].days > dayss)
            {
                cout << dayss + 2 << " " << Months[m].s;
                break;
            }
        }
    }
    return 0;
}