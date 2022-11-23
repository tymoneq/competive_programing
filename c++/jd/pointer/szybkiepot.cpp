#include <bits/stdc++.h>

using namespace std;

long long pot_szybkie(long long a, unsigned int n)
{
    long long w = 1;

    while (n > 0)
    {
        if (n % 2 == 1) // jesli bit jest = 1
            w *= a;

        a *= a;
        n /= 2; // skrócenie o jeden bit
    }
    return w;
}

int main()
{
    unsigned int n;
    long long a;

    cout << "Podaj podstawę: ";
    cin >> a;
    cout << "Podaj wykładnik: ";
    cin >> n;

    cout << a << " do potęgi " << n << " wynosi " << pot_szybkie(a, n);

    return 0;
}