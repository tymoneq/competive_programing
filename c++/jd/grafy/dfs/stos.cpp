#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    int dec = 23;
    while (dec > 0)
    {
        s.push(dec % 2);
        dec /= 2;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}