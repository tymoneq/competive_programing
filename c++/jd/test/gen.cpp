#include <bits/stdc++.h>

using namespace std;
int p(int a, int b)
{
    return a + rand() % (b - a);
}
int main()
{
    int z, n;
    cin >> z;
    cout << 500 << "\n";
    srand(z);
    for (int i = 0; i < 500; i++)
    {
        cout << p(0,500) << "\n";
    }
}