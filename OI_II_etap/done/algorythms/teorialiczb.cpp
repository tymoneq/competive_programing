#include <bits/stdc++.h>

using namespace std;
// euklides na sterydach znajdzie x,y całkowite takie że ax + by = nwd(a,b)
int x = 1, y, x2;
int nwd(int a, int b)
{
    if (b)
    {
        nwd(b, a % b);
        x2 = y;
        y = x - ((a / b) * y);
        x = x2;
    }
}
int main()
{
    return 0;
}