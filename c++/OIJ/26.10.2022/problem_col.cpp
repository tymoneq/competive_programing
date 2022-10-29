#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long M, wynik = 1;
    cin >> M;

    for (int i = 1; i < M; i++)
    {

        if ((wynik - 1) % 3 == 0 && wynik != 1 && (wynik - 1) / 3 != 1 && wynik !=10)
            wynik = (wynik - 1) / 3;
        else
            wynik *= 2;
    }
    cout << wynik;
   

    return 0;
}