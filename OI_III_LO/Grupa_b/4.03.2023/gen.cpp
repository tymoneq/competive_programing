#include <bits/stdc++.h>
using namespace std;

int main()
{
    int z;
    cin >> z;
    srand(z);
    int n = rand() % 300000;
    int k = rand() % 300000;
    n++, k++;
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 1000;
        int val = rand() % 1000000;
        val++, m++;
        cout << m << " " << val << "\n";
    }
    for (int i = 0; i < k; i++)
    {
        int val = rand() % 1000000;
        val++;
        cout << val << "\n";
    }
}