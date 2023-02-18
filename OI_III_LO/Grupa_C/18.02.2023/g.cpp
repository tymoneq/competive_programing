#include <bits/stdc++.h>
using namespace std;
int p(int a, int b)
{
    return a + (rand() % (b - a));
}
int main()
{
    int z;
    cin >> z;
    srand(z);
    int n = rand() % 100;
    n++;
    int time = 8640000;
    int x, y;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        x = p(0, time - 10000);
        y = p(x, time);
        cout << x << " " << y << "\n";
    }
    return 0;
}