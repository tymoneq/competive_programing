
#include <bits/stdc++.h>

using namespace std;

float f(float x)
{
    return ((-1) * x) / 2 + 6;
}
float a, b, d, pole;
int main()
{

    cin >> a >> b >> d;
    for (float i = a; i <= b - a; i += d)
    {
        pole = pole + d * abs(f((i + d) / 2));
    }
    cout << pole;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

float f(float x)
{
    return (5 * pow(x, 5)) - (4 * pow(x, 4)) + (3 * pow(x, 3)) - (2 * pow(x, 2)) + x - 1;
}

float x1, x2, d, p;
int main()
{

    cin >> x1 >> x2 >> d;

    while (x2 - x1 > d)
    {

        if (f(x1) == 0)
        {
            cout << x1;
            return 0;
        }
        if (f(x2) == 0)
        {
            cout << x2;
            return 0;
        }
        p = (x1 + x2) / 2;
        if (f(p) == 0)
        {
            cout << p;
            return 0;
        }
        if (f(x1) * f(p) < 0)
        {
            x2 = p;
        }
        else
        {
            x1 = p;
        }
    }
    cout << p;
    return 0;
}