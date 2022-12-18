#include <bits/stdc++.h>
using namespace std;

const int MAX_DLUGOSC = 2e6 + 7;
const int MODULO_WAR = 1e9 + 7;

int ile_mozliwosci[MAX_DLUGOSC];
string wiadomosc;
bool Czy_2_OstatnieTworzaLitere(int i)
{
    if (wiadomosc[i - 1] == '1')
        return true;
    if ((wiadomosc[i - 1] == '2') && (wiadomosc[i] <= '6'))
        return true;
    return false;
}
bool Czy_1_OstatniaTworzyLitere(int i)
{
    if (wiadomosc[i] == '0')
        return false;
    return true;
}
int main()
{
    int akt_wynik;
    int i;
    cin >> wiadomosc;

    wiadomosc = "  " + wiadomosc;

    ile_mozliwosci[0] = 0;
    ile_mozliwosci[1] = 1;
    for (i = 2; i < wiadomosc.length(); ++i)
    {
        akt_wynik = 0;
        if (Czy_2_OstatnieTworzaLitere(i) == true)
        {
            akt_wynik = ile_mozliwosci[i - 2];
        }
        if (Czy_1_OstatniaTworzyLitere(i) == true)
        {
            akt_wynik += ile_mozliwosci[i - 1];
            akt_wynik %= MODULO_WAR;
        }
        if (akt_wynik == 0)
        {
            cout << "0\n";
            return 0;
        }
        ile_mozliwosci[i] = akt_wynik;
    }
    cout << ile_mozliwosci[wiadomosc.length() - 1] << "\n";

    return 0;
}
