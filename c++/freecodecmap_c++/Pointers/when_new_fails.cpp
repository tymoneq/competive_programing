#include <bits/stdc++.h>

using namespace std;

int main()
{
    // exception
    /*
    for (size_t i{0}; i < 100; i++)
    {
        try
        {
            int *lots_of_int3{new int[100000000000]};
        }
        catch (exception &ex)
        {
            cout << "Cought exception ourselves: " << ex.what() << endl;

        }
    }
    cout << "Program finished good " << endl;

    */
    for (size_t i{0}; i < 100; i++)
    {
        int *lots_of_int3{new (nothrow) int[100000000000]};
        if (lots_of_int3 != nullptr)
        {
            cout << " Data allocated" << endl;
        }
        else
        {
            cout << "Data allocation fail" << endl;
        }
    }
    cout << "Program finished good " << endl;
    return 0;
}