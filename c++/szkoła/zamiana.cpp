#include <iostream>
using namespace std;

int decy;
string bin="";

int main()
{
    cin >> decy;
    while (decy > 0){
        if (decy % 2 ==0) bin= '0'+bin;
        else bin = "1" + bin;
        decy /= 2;
    }
    cout << bin;

    return 0 ;
}