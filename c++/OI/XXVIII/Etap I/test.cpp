#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int val_array[5][5];
    int count_rows, count_cols, counter1, counter2;
    cout << "Please enter the size of the rows and columns that you want to input: ";
    cin >> count_rows >> count_cols;
    cout << "PLease enter the values for matrics in row wise manner" << endl;
    for (counter1 = 0; counter1 < count_rows; counter1++)
        for (counter2 = 0; counter2 < count_cols; counter2++)
            cin >> val_array[counter1][counter2];
    cout << "The matrix will be as follows" << endl;
    for (counter1 = 0; counter1 < count_rows; counter1++)
    {
        for (counter2 = 0; counter2 < count_cols; counter2++)
            cout << val_array[counter1][counter2] << "  ";
        cout << endl;
    }
    getch();
    return 0;
}