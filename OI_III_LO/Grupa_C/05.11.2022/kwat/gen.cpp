#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream file;
    file.open("gen.txt");
    file << 100 << " " << 100 << " " << 100 << " " << 100 << "\n";
    for (int i = 0; i < 100; i++)
    {
        file << 1 << " " << 1 << " " << 1 << "\n";
    }
    return 0;
}