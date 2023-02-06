#include <bits/stdc++.h>

using namespace std;

int p(int a, int b)
{
    return a + rand() % (b - a);
}

int main()
{
    int z, t = 1e9;
    cin >> z;
    srand(z);
    int n = 10;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << p(1, t) << " ";
    }
}