#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int M = 1e9 + 1;
    srand(5);
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % M;
        int y = rand() % x;
        cout << y << "\n";
    }
}