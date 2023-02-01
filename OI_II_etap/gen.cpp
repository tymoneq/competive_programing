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
    srand(z);
    n = 1;
    int Val = 702;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int v = p(1, Val);
        cout << v;
    }
}