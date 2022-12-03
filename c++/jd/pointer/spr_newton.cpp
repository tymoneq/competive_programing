#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x, y = 2, X;
    cin >> X;
    double dec = 0.00001;
    x = X;
    x /= 2;

    while (abs(x - y) > dec)
    {
        x = (x + y) / 2;
        y = X / x;
        cout << x << " " << y << "\n";
    }

    return 0;
}