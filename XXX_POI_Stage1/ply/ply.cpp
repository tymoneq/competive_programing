#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string znaki;
    int n, H, wynik = 0, stopien_baz = 0, otwarte = 0;
    cin >> n >> H;
    cin >> znaki;

    // liczenie stopnia bazowego
    for (int i = 0; i < n; i++)
    {
        if (znaki[i] == '(')
            otwarte += 1;
        else if (znaki[i] == ')')
        {
            stopien_baz = max(stopien_baz, otwarte);
            --otwarte;
        }
    }
    if (stopien_baz <= H)
        cout << 0;
    else if (stopien_baz > H)
    {
        otwarte = 0;
        for (int i = 0; i < n; i++)
        {
            if (znaki[i] == '(')
            {
                if (otwarte < H)
                    otwarte += 1;
                else
                {
                    otwarte -= 1;
                    wynik += 1;
                }
            }
            else if (znaki[i] == ')')
            {
                if (otwarte > 0)
                    --otwarte;
                else
                {
                    wynik += 1;
                    otwarte += 1;
                }
            }
        }
        cout << wynik;
    }
    return 0;
}