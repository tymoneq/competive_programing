#include <bits/stdc++.h>

using namespace std;

void printt(int *tab)
{
    for (int i = 0; i < sizeof(tab) / sizeof(int); i++)
    {
        cout << *(tab + i) << ' ';
    }
}
int main()
{
    int *t = new int;
    *t = 1;
    t[1] = 2;
    printt(t);

    return 0;
}
