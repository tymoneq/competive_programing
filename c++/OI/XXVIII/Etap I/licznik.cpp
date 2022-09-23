#include <bits/stdc++.h>

using namespace std;

int main()
{
    string dl_wew, dl_zew, str_dl_suma;
    string operacja{};
    char y;
    int x, indeks, n, z;

    cin >> n >> z;
    cin >> dl_wew >> dl_zew;

    for (int i = 0; i < z; i++)
    {
        cin >> operacja;
        if (operacja == "W")
        {
            cin >> x >> y;
            indeks = dl_wew.size() - x;
            dl_wew[indeks] = y;
        }
        else if (operacja == "Z")
        {
            cin >> x >> y;
            indeks = dl_zew.size() - x;
            dl_zew[indeks] = y;
        }
        else if (operacja == "S")
        {
            cin >> x;
            str_dl_suma = to_string(stoi(dl_wew) + stoi(dl_zew));
            cout << str_dl_suma[str_dl_suma.size()-x]  << "\n";

        }
        
    }

    return 0;
}