#include <bits/stdc++.h>

using namespace std;

int p(int a, long long b)
{
    return a + rand() % (b - a);
}

int main()
{
    int z;
    cin >> z;
    srand(z);
    int n = (rand() % 10000) + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 100000 + 1;
        cout << a << " ";
    }
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        int a = rand() % 100000 + 1;
        cout << a << " ";
    }
cout << "\n";
    for (int i = 1; i < n; i++)
    {
        int a = rand() % 100000 + 1;
        cout << a << " ";
    }
}