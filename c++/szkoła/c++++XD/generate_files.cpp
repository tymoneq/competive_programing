#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int a, b;
ofstream out_a, out_b, out_c;
int main()
{
    out_a.open("a.txt");
    out_b.open("b.txt");
    out_c.open("c.txt");
    srand(time(NULL));
    for (int i{0}; i < 1000; i++)
    {

        a = rand() % 2000;
        b = rand() % 2000;
        a -= 1000;
        b -= 1000;
        out_a << a << " " << b << '\n';
        Sleep(10);
    }
    out_a.close();

    
    
    for (int i{0}; i < 10; i++)
    {

        a = rand() % 2000;
        b = rand() % 2000;
        a -= 1000;
        b -= 1000;
        out_b<< a << " " << b << '\n';
        Sleep(10);
    }
    out_b.close();

    
    
    for (int i{0}; i < 10; i++)
    {

        a = rand() % 2000;
        b = rand() % 2000;
        a -= 1000;
        b -= 1000;
        out_c << a << " " << b << '\n';
        Sleep(10);
    }
    out_c.close();
    return 0;
}
