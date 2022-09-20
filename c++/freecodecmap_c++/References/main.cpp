#include <bits/stdc++.h>

using namespace std;

int main()
{
    int int_data{33};
    double double_data{44};

    // references
    int &ref_int_data{int_data};
    double &ref_double_data{double_data};


    cout << int_data << endl;
    cout << &int_data << endl;
    cout << double_data << endl;
    cout << &double_data << endl;


    cout << ref_int_data << endl;
    cout << &ref_int_data << endl;
    cout << ref_double_data << endl;
    cout << &ref_double_data << endl;

    int_data = 111;
    double_data = 68.7;

    cout << "==================" << endl;
    cout << int_data << endl;
    cout << &int_data << endl;
    cout << double_data << endl;
    cout << &double_data << endl;


    cout << ref_int_data << endl;
    cout << &ref_int_data << endl;
    cout << ref_double_data << endl;
    cout << &ref_double_data << endl;


    ref_int_data = 112;
    ref_double_data = 145.66;


    cout << "==================" << endl;
    cout << int_data << endl;
    cout << &int_data << endl;
    cout << double_data << endl;
    cout << &double_data << endl;


    cout << ref_int_data << endl;
    cout << &ref_int_data << endl;
    cout << ref_double_data << endl;
    cout << &ref_double_data << endl;

    return 0;
}