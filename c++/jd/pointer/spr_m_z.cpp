#include <bits/stdc++.h>
using namespace std;

inline double funct(double x, double N)
{
    return -4 * pow(x, 3) + 3 * pow(x, 2) - 2 * pow(x, 1) + N;
}
int main()
{
    double N, a, b, d=0.01, p = 0;
    cout << "Podaj N : ";
    cin >> N;
    cout << "\nPodaj a i b: ";
    cin >> a >> b;
    while (abs(a - b) > d)
    {

        if (funct(a, N) == 0)
        {
            cout << a;
            return 0;
        }
        if (funct(b, N) == 0)
        {
            cout << b;
        
            return 0;
        }
        p = (a + b) / 2;
        if (funct(p, N) == 0)
        {
            cout << p;
            return 0;
        }
        if (funct(a, N) * funct(p, N) < 0)
            b = p;

        else
            a = p;
    }
    cout << p;
    
    return 0;
}