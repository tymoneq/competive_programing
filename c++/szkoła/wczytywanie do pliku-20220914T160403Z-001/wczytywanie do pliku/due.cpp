#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int a, b;
ofstream file;

int main()
{
    
    
    file.open("data.txt");
    for (size_t i{0}; i < 100; i++)
    {

        srand(time(NULL));
        a = rand() % 2 + 1;
        b = rand() % 100 + 2;
        for (int i = a; i <= b; i++)
        {
            if (i % 2 == 0)
                file << "a";
            else
                file << "b";
            file << rand() % 20 + 1;
        }
        file << "\n";
        usleep(1000000);
    }
    file.close();
    return 0;
}
