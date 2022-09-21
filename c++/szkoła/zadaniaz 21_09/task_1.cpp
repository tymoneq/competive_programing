#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream a_in;
ofstream out_a;
string s;

void sprawdzenie(int x, int y)
{
    if (x * x + y * y <= 10000)
    {
        out_a << "\t"
              << "należy do okręgu"
              << "\n";
    }
    else
    {
        out_a << "\t"
              << " nie należy do okręgu"
              << "\n";
    }
}
int main()
{
    a_in.open("a.txt");
    out_a.open("zadanie1_a.txt");
    int x, y;
    while (a_in >> x >> y)
    {
        if ((x == 0) || (y == 0))
        {
            out_a << "osie nie należą do żadnej ćwiartki";
        }
        else if (x > 0)
        {
            if (y > 0)
            {
                out_a << "I";
            }
            else if (y < 0)
            {
                out_a << "IV";
            }
        }
        else if (x < 0)
        {
            if (y > 0)
            {
                out_a << "III";
            }
            else if (y < 0)
            {
                out_a << "II";
            }
        }
        sprawdzenie(x, y);
    }
    a_in.close();
    out_a.close();
    return 0;
}