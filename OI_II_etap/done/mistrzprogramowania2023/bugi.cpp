#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long res = 0, bugs = 0;
    cin >> bugs;
    res = bugs * 1.5;
    if (bugs % 2 == 1)
        res++;
    cout << res;
}