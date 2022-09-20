
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    double result; 
    cin >> a >> b >> c;
    if (c !=0){
    result = (a+b) / c;
    }
    cout.precision(2);
    cout << fixed << sqrt(result);

   return 0;
}

