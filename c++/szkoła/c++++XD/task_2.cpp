#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream a_in, b_in;
ofstream wynik;
int main()
{
    a_in.open("a.txt");
    b_in.open("b.txt");
    wynik.open("zadanie2.txt");
    int a, b, c, d;
    while ((a_in >> a >> b) && (b_in >> c >> d))
    {
        if (b == d)
        {
            wynik << "Odcinek równoległy do osi X";
        }
        else if (a == c)
        {
            wynik << "Odcinek równoległy do osi Y";
        }
    }

    wynik.close();
    a_in.close();
    b_in.close();

    return 0;
}