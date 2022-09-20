#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    int *pointer{new int{56}};
    if (pointer != nullptr)
    {
        cout << "*pointer " << *pointer << endl;
    }
    else
    {
        cout << "Invalid address" << endl;
    }
    delete pointer;
    pointer = nullptr;

    */

    int *pointer_1{new int{665}};
    int *pointer_2{pointer_1};

    cout << pointer_1 << " - " << *pointer_1 << endl;

    if (!(pointer_1 == nullptr))
    {
        cout << "pointer 2 " << pointer_2 << " - " << *pointer_2 << endl;
    }
    delete pointer_1;
    pointer_1 = nullptr;

    if (!(pointer_1 == nullptr))
    {
        cout << "pointer 2 " << pointer_2 << " - " << *pointer_2 << endl;
    }
    else
    {
        cerr << "Warning : Trying to use an invalid pointer" << endl;
    }
    return 0;
}