#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream file;
    file.open("data.txt");
    file << 1000 << " " << 1000 << "\n";
    for (size_t i = 0; i < 1000; i++)
    {
        /* code */

        for (int j = 0; j < 1000; j++)
        {
            file << pow(10, 7) << " ";
        }
        file << "\n";
    }
    file.close();
    return 0;
}