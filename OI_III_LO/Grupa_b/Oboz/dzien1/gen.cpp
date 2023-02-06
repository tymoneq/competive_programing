#include <bits/stdc++.h>

using namespace std;
int p(int a, int b)
{
    return a + rand() % (b - a + 1);
}
int main()
{
    int z, n;
    cin >> z;
    srand(z);
    n = rand() % 5;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << p(1, 10) << "\n";
    }
    int k = rand() % 10;
    cout << k << "\n";
    for (int i = 0; i < k; i++)
        cout << p(1, 100) << "\n";
}