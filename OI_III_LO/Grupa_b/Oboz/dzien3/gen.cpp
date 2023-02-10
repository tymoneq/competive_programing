#include <bits/stdc++.h>

using namespace std;
int p(int a)
{
    return rand() % a;
}
int main()
{
    int z, n;
    cin >> z;
    srand(z);
    n = rand() % 1000 + 1;
    int s = 22;
    cout << n << " " << s << "\n";
    for (int i = 0; i < n; i++)
    {
        int x = p(200000) - 200000/2;
        int y = p(200000) - 200000/2;
        cout << x << " " << y << "\n";
    }
}