#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char tab[36];
    for (int i = 0; i < 10; i++)
        tab[i] = i + 48;
    tab[10] = 'A';
    tab[11] = 'B';
    tab[12] = 'C';
    tab[13] = 'D';
    tab[14] = 'E';
    tab[15] = 'F';
    tab[16] = 'G';
    tab[17] = 'H';
    tab[18] = 'I';
    tab[19] = 'J';
    tab[20] = 'K';
    tab[21] = 'L';
    tab[22] = 'M';
    tab[23] = 'N';
    tab[24] = 'O';
    tab[25] = 'P';
    tab[26] = 'Q';
    tab[27] = 'R';
    tab[28] = 'S';
    tab[29] = 'T';
    tab[30] = 'U';
    tab[31] = 'V';
    tab[32] = 'W';
    tab[33] = 'X';
    tab[34] = 'Y';
    tab[35] = 'Z';
    string X;
    int Y, Z;
    unsigned long long X_dz = 0;
    cin >> X >> Y >> Z;
    int u = 0;
    for (int i = X.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 36; j++)
        {
            if (tab[j] == X[i])
            {
                X_dz += j * pow(Y, u);
            }
        }

        u++;
    }
    vector<char> wynik;

    while (true)
    {
        if (X_dz == 0)
            break;
        int mod = X_dz % Z;
        X_dz /= Z;
        wynik.push_back(tab[mod]);
    }
    for (int i = wynik.size() - 1; i >= 0; i--)
        cout << wynik[i];
    return 0;
}