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
    n = 20000;
    int Val = 1e9;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int v = p(1, Val - 1000);
        cout << v << " " << p(v, Val) << "\n ";
    }
}