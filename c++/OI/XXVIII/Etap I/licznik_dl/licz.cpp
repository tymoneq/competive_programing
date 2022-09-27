#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dl_wew{}, dl_zew{}, y{};
    string operacja{};

    int n{}, z{};

    cin >> n >> z;
    cin >> dl_wew >> dl_zew;

    for (int i = 0; i < z; i++)
    {
        int x{}, temp{};
        double indeks{};
        cin >> operacja >> x;
        if (operacja == "W")
        {
            cin >> y;
            string str_dl{};
            
        }
        else if (operacja == "Z")
        {
            cin >> y;
            indeks = dl_zew % (int)pow(10, x - 1);

            temp = dl_zew % (int)pow(10, x);
            if (temp >= y)
            {
                dl_zew = dl_zew - temp + y * pow(10, indeks);
                dl_zew += indeks;
            }
        }
        else if (operacja == "S")
        {
            int suma = 0, result = 0;
            suma = dl_wew + dl_zew;
            result = suma % (int)pow(10, x);
            cout << result << "\n";
        }
    }

    return 0;
}