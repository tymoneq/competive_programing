#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    int number {22};
    int *p_number = &number;
    cout << "Dec;laring pointer and assigning address : " << endl;
    cout << "number : " << number << endl;
    cout << " p_number : " << p_number << endl;
    cout << " &number : " << &number << endl;
    cout << "*p_number : " << *p_number << endl;

    int *p_number1;
    int number1 {12};
    p_number1 = &number1;
    cout << *p_number1 << endl;
    */

    int *p_number{nullptr};
    p_number = new int;

    *p_number = 77;
    cout << "Dynamically allocating memory : " << *p_number << endl;

    delete p_number;
    p_number = nullptr;

    p_number = new int(81);
    cout << "*p_number : " << *p_number << endl;
    delete p_number;
    p_number = nullptr;

    return 0;
}
