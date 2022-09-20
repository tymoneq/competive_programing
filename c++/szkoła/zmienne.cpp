#include <iostream>

using namespace std;


string x;
int y;
int main()
{
    cout << "Podaj Imie" << endl;
    cin >> x;
    y = x.size();
    if (x[y-1] == 'a'){
        cout << "Ona" << endl;
    }
    else{
        cout << "ON" << endl;
    }
    return 0;
}