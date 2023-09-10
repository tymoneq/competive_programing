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
    int n = 1e4;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 4;
        x++;
        if (x % 4 == 0)
            cout << "#";
        else
            cout << ".";
    }

    return 0;
}