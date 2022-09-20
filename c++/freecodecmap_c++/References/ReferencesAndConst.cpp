#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    int age{27};
    int &ref_age{age};

    ref_age++;
    cout << age << endl
         << ref_age << endl;


    int age2{27};
    const int &ref_age2{age2};


    // ref_age2 ++; compailer error
    cout << age2 << endl
         << ref_age2 << endl;

    */

    int age{27};
    int &ref_age{age};
    const int *const p_age{&age};

    //*p_age = 45; compailor error

    return 0;
}