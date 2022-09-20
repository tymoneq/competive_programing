#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    int *pointer{};
    //pointer = new int (7);

    if (!(pointer == nullptr))
    {
        cout << "pointer point to a valid address : " << pointer << endl;
    }
    else
    {
        cout << "Pointer pounts to an invalid address " << endl;
    }
    */
    int *pointer{};

    if (pointer)
    {
        cout << "pointer point to a valid address : " << pointer << endl;
    }
    else
    {
        cout << "Pointer pounts to an invalid address " << endl;
    }
    delete pointer;
    pointer = nullptr;
    return 0;
}
