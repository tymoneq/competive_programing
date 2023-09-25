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
    int n = (rand() % 10) + 1, q = (rand() % 10) + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int a = (rand() % 100) + 1;
        cout << a << " ";
    }
    cout << q << "\n";
    for (int i = 0; i < q; i++)
    {
        int a = (rand() % n) + 1;
        cout << a << " ";
        int b = (rand() % 100) + 1;
        cout << b << "\n";
    }
}