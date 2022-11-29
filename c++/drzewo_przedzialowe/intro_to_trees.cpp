#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int tmp = log2(n);
    if (pow(2, tmp) != n)
        tmp++;
    vector<int> Tree(pow(2, tmp + 1));
    for (int i = pow(2, tmp); i < pow(2, tmp) + n; i++)
        cin >> Tree[i];
    
    for (int i = pow(2, tmp) - 1; i > 0; i--)
    {
        int suma = Tree[2 * i] + Tree[2 * i + 1];
        Tree[i] = suma;
    }
    return 0;
}