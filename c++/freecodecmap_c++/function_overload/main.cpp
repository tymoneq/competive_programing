#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
double max(double a, double b)
{
    return (a > b) ? a : b;
}
string_view max(string_view a, string_view b)
{
    return (a > b) ? a : b;
}
int main()
{
    int val1{55}, val2{56};
    double val3{66.6}, val4{67.7};
    string_view val5{"Hello"}, val6{"World"};
    cout << "INT " << max(val1, val2) << "\n";
    cout << "Double " << max(val3, val4) <<"\n";
    cout << "String " << max(val5,val6) << "\n";

    return 0;
}