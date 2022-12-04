#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file;
    file.open("ple3.in");
    file << 200 << "\n";
    for (int i = 0; i < 200; i++)
    {
        file << i % 47 + 1 << " ";
    }
}