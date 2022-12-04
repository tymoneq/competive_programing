#include <bits/stdc++.h>

using namespace std;
int main(int argc, char **argv)
{
    ifstream plik, plik_2;
    string test, test_2;

    // cin >> argv[1];
    // cout << argv[1] << endl;
    test_2 = "res.out";
    plik.open(argv[1]);
    plik_2.open(test_2);
    int a, b, counter = 1;
    bool error = false;
    while (plik >> a && plik_2 >> b)
    {
        if (!(a == b))
        {
            cout << "Error in line " << counter << " " << argv[1] << "\n";
            error = true;
        }
        counter += 1;
    }
    if (!error)
        cout << "1000%\n";

    return 0;
}