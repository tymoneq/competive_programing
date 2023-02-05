#include <bits/stdc++.h>

using namespace std;

int p(int a, int b)
{
    return a + rand() % (b - a);
}

int main()
{
    int z, t;
    cin >> z;
    srand(z);
    t = 100;
    int n = 100;
    cout << t << "\n";
    for (int i = 0; i < t; i++)
    {
        cout << n << "\n";
        for (int j = 0; j < n; j++)
            cout << p(1, n) << " " << p(1, n) << "\n";
    }
}