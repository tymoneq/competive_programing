#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int t = 24 - c;
    int sum = a + b;
    cout << abs(sum - t);
}