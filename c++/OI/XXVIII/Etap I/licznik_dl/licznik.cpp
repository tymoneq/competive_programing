#include <bits/stdc++.h>

using namespace std;

int main()
{
    string dl_wew{}, dl_zew{};
    string operacja{};
    char y{};
    int n{}, z{};

    cin >> n >> z;
    cin >> dl_wew >> dl_zew;

    for (int i = 0; i < z; i++)
    {
        int x{}, indeks{};
        cin >> operacja >> x;
        if (operacja == "W")
        {
            cin >> y;
            indeks = dl_wew.size() - x;
            dl_wew[indeks] = y;
        }
        else if (operacja == "Z")
        {
            cin >> y;
            indeks = dl_zew.size() - x;
            dl_zew[indeks] = y;
        }
        else if (operacja == "S")
        {
            int suma{0};
            int temp_dl_wew = dl_wew[dl_wew.size() - x] - 48;
            int temp_dl_zew = dl_zew[dl_zew.size() - x] - 48;
            int temp_dl_wew_1 = dl_wew[dl_wew.size() - x + 1] - 48;
            int temp_dl_zew_1 = dl_zew[dl_zew.size() - x + 1] - 48;
            if (temp_dl_zew_1 + temp_dl_wew_1 >= 10)
            {
                suma = temp_dl_wew + temp_dl_zew + 1;
            }
            else if (temp_dl_zew_1 + temp_dl_wew_1 == 9)
            {

                for (int j = dl_wew.size() - x + 2; j < dl_wew.size(); j++)
                {

                    int temp_1 = dl_wew[j] - 48;
                    int temp_2 = dl_zew[j] - 48;
                    if (temp_1 + temp_2 >= 10)
                    {
                        suma = temp_dl_wew + temp_dl_zew + 1;
                        break;
                    }
                    else if (temp_1 + temp_2 == 9)
                        continue;
                    else if (temp_1 + temp_2 < 9)
                    {
                        suma = temp_dl_wew + temp_dl_zew;
                        break;
                    }
                }
            }
            else
            {
                suma = temp_dl_wew + temp_dl_zew;
            }
            if (suma % 10 == -5)
                cout << 1 << "\n";
            else if (suma % 10 == -6)
                cout << 0 << "\n";

            else
                cout << suma % 10 << '\n';
        }
    }

    return 0;
}