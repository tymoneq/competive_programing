#include <iostream>
using namespace std;
const int MAX_VAL = 1e5 + 10;
int c[MAX_VAL];
int main()
{
    int n, i, x, y;
    cin >> n;
    int z = 2;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (y != 1)
        {
            c[i] = 1;
            if (x != -1)
                c[x] = 1;
        }
    }
    for (i = 1; i <= n; i++)
        if (c[i] != 1)
        {
            cout << i << " ";
            z = 1;
        }
    if (z == 2)
        cout << -1;
    return 0;
}