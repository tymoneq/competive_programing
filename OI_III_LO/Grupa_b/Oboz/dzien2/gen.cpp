#include <bits/stdc++.h>

using namespace std;
int p(int a, int b)
{
    return a + rand() % (b - a);
}
int main()
{
    int n = 1000;
    int z;
    cin >> z;
    srand(z);
    cout << n << "\n";
    vector<int> Val(n + 1);
    for (int i = 1; i <= n; i++)
        Val[i] = i;
    int g = rand() % n;
    for (int i = 0; i < g; i++)
    {
        int a = p(1, n);
        int b = p(1, n);
        swap(Val[a], Val[b]);
    }
    for (int i = 1; i <= n; i++)
        cout << Val[i] << " ";
}