#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a_x, a_y, b_x, b_y, c_x, c_y, d_x, d_y, result;
    cin >> a_x >> a_y >> b_x >> b_y >> c_x >> c_y >> d_x >> d_y;

    result = a_x * b_y + b_x * c_y + c_x * a_y - c_x * b_y - b_x * a_y - a_x * c_y;
    if (result == 0)
        cout << "Sa wspoliniowe"
             << "\n";
    if ((min(a_x, c_x) <= b_x) && (max(a_x, c_x) >= b_x) && (min(a_y, c_y) <= b_y) && (max(a_y, c_y) >= b_y))
    {
        cout << "B jest na odcinku AB"
             << "\n";
    }
    return 0;
}