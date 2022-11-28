#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> Data(n);
    for (int i = 0; i < n; i++)
        cin >> Data[i];
    // indexy to n+1
    int tmp = log2(n);
    if (pow(2, tmp) != n)
        tmp++;
    vector<int> Tree(pow(2, tmp + 1));
    int index = 0;
    for (int i = pow(2, tmp); i < Tree.size(); i++)
    {
        if (index == n)
            break;
        Tree[i] = Data[index];
        index++;
    }
    for (int i = pow(2, tmp) - 1; i > 0; i--)
    {
        int suma = Tree[2 * i] + Tree[2 * i + 1];
        Tree[i] = suma;
    }
    return 0;
}