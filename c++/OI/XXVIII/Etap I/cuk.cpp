#include <iostream>

using namespace std;

int n, d, p, r, resoult= 0;
int array[5][3];
int counter1;
int main()
{
    cin >> n;
    for (counter1 = 0; counter1 < n; counter1++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> array[counter1][i];
        }
    }
    for (counter1 = 0; counter1 < n; counter1++)
    {
        for (int i  = 0; i < 3; i++)
            cout << array[counter1][i] << "  ";
        cout << endl;
    }
    
    return 0;

    return 0;
}