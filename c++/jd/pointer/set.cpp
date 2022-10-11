#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> secik;
    vector<int> d = {11, 24, 11, 255, 2, 255};
    secik.insert(d.begin(), d.end());
    for (auto el : secik)
        cout << el << " ";

    map<string, string> mapka; // map <key, value>
    mapka["pon"] = "mon";
    mapka["wt"] = "TH";
    for (auto el : mapka)
    {
        cout << el.first << " " << el.second << " ";
    }

    map<int, int> m;
    for (auto el : d)
    {
        m[el]++;
    }
    cout << endl;
    for (auto el : m)
    {
        cout << el.first << " " << el.second << " ";
    }
    return 0;
}