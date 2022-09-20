#include <iostream>

using namespace std;

int main()
{

    int *p_number{};
    double *p_number2{}; // Will initialize with nullptr

    int *p_number_3{nullptr};

    cout << sizeof(int) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(double *) << endl;
    cout << sizeof(p_number_3) << endl;

    int var {43};
    int *p_int{&var};

    cout << var << endl;
    cout << p_int << endl;
    int new_var{55};
    p_int = &new_var;
    cout << p_int << endl;
    cout << *p_int << endl; //printing value of the pointer

    return 0;
}