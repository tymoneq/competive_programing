#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file;
    file.open("test.in");
    file << 10000 << " " << 10000 << "\n";
    for (int i = 0; i < 100000; i++)
        file << 100000 - i << " ";
    file << "\n";
    for (int i = 0; i < 10000; i++)
        file << 100000 - i << " ";
}