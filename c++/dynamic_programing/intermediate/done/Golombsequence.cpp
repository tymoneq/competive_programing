#include <bits/stdc++.h>
using namespace std;
int findGolumb(int n)
{
    if (n == 1)
        return 1;
    return 1 + findGolumb(n - findGolumb(findGolumb(n - 1)));
}
void printGolumb(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << findGolumb(i) << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    printGolumb(n);
}