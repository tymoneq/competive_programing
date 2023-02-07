#include <bits/stdc++.h>

using namespace std;
int p(int a, int b)
{
    return a + rand() % (b - a);
}
int main()
{
    int n = 10000;
    int z;
    cin >> z;
    srand(z);
    cout << n << "\n";

    for (int i = 1; i <= n; i++)
        cout << i << " ";
}