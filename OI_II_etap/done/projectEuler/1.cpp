#include <bits/stdc++.h>

using namespace std;

int main()
{

    int res = 0;
    for (int i = 1; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            res += i;

    cout << res << "\n";
}