#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file;
    file.open("pla3.in");
    file << pow(10, 6) - 1 << " " << 1000000 << " " << pow(10, 5) << "\n";
    for (int i = 1; i < pow(10, 5); i++)
    {
        file << i << "\n";
    }
}