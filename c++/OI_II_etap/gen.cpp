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
    n = 3e5;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << p(1,n) << " ";
    cout << p(1,n) << " " << p(1,n);
}