#include <bits/stdc++.h>

using namespace std;

int main()
{
    // allways delete pointers before reusing it

    /*
    // wrong way to do
    int *p_number{new int{56}};


    int number{55};
    p_number = &number;

    cout << "Porgram ending well " << endl;
    */
    // good way to do 
    int *p_number{new int{56}};

    delete p_number;
    p_number = nullptr;

    int number{55};
    p_number = &number;

    cout << "Porgram ending well " << endl;
    return 0;
}