#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char present, past;
    int res = 0;
    cin >> past;
    for (int i = 1; i < 10000; i++)
    {
        cin >> present;
        if(present!=past)
            res++;
        past = present;
    }
    cout << res;
    return 0;
}