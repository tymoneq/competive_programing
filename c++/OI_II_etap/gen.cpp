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
    n = p(5, 10);
    cout << 1 << "\n";
    cout << n << "\n";
    string s = "";
    for (int i = 0; i < n; i++)
        s += p(0, 9) + 48;
    cout << s;
}