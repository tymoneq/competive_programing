#include <bits/stdc++.h>

using namespace std;

int p(int a, long long b)
{
    return a + rand() % (b - a);
}

int main()
{
    int z, t = 1e9;
    cin >> z;
    srand(z);
    int n = 10;
    cout << 1 << "\n";
    cout << n << " ";
    cout << p(1, 1000) << " " << p(1, 1000) << "\n";
    for (int i = 0; i < n; i++)
    {
        int a = p(1, 1000), b = p(1, 1000), c = p(a + b, 1000*2);
        cout << a << " " << b << " " << c << "\n";
    }
}