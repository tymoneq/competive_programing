#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    ifstream plik;
    plik.open("res.txt");
    string a;
    int counter = 1, lines = 0;
    bool error = false;
    while (plik >> a)
    {
        if (a != "1000%")
        {
            cout << "Error in line " << counter << " " << argv[1] << "\n";
            error = true;
            lines += 1;
        }
        counter += 1;
    }
    if (!error)
        cout << "1000% Brak błędów\n";
    else
        cout << "Errors : " << (counter-lines)/counter <<"%\n";
    

    return 0;
}
