#include <iostream>

using namespace std;

int main()
{
    int number_1 = 15;         // Decimal
    int number_2 = 017;        // Octal
    int number_3 = 0x0f;       // Hexadecimal
    int number_4 = 0b00001111; // bin
    // cout << "number 1 " << number_1 << endl;
    // cout << "number 2 " << number_2 << endl;
    // cout << "number 3 " << number_3 << endl;
    // cout << "number 4 " << number_4 << endl;
    int num = 0b0, num2 = 0b0;
    cin >> num >> num2;
    cout << num;
    if (num % 2 == 0)
        cout << "\nTAK"
             << "\n";
    int res = 0b0;
    res = num + num2;
    cout << res<< "\n";

    return 0;
}