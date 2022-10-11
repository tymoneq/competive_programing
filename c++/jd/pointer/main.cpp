#include <bits/stdc++.h>
using namespace std;

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int foo(int a, int &b)
{
    b *= 3;
    return 2 * a;
}

int main()
{
    int x = 2;
    int y = 3;
    swapp(x, y);

    cout << x << " " << y << "\n";
    x = foo(x, y);
    cout << x << " " << y;
    return 0;
}