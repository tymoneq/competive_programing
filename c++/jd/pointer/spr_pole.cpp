#include <bits/stdc++.h>
using namespace std;

inline double funct(double x, double N)
{
    return -4 * pow(x, 3) + 3 * pow(x, 2) - 2 * pow(x, 1) + N;
}
int main()
{
    double N, a, b, d, pole = 0;
    cout << "Podaj N : ";
    cin >> N;
    cout << "\nPodaj a i b: ";
    cin >> a >> b;
    d = (b - a) / 1000;
    for (double i = a; i <= b - a; i += d)
    {
        pole +=  d * (funct(i, N) + funct((i + d), N)) / 2;
    }
    cout << abs(pole);
    return 0;
}