#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
    int n, zakres_start, zakres_stop, przecinek, zakres;
    double a;
    string file_name;
    ofstream file;
    srand(time(NULL));

    cin >> n >> zakres_start >> zakres_stop >> przecinek >> file_name;
    file_name += ".txt";
    file.open(file_name);
    file.precision(przecinek);
    if (zakres_start < 0)
    {
        zakres = zakres_start * -1 + zakres_stop;
    }
    else
        zakres = zakres_start + zakres_stop;
    zakres = zakres * pow(10, przecinek);

    for (int i = 0; i < n; i++)
    {

        a = ((rand() % zakres) - zakres / 2) / pow(10, przecinek);
        //cout << a << "\n";
        file << a << " ";
        Sleep(10);
    }
    file.close();
    return 0;
}