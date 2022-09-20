
#include <iostream>
#include <cmath>

using namespace std;
int x,y;
int main()
{
    cin >> x >> y;
    while (x!=y)
        if(x>y)x =- y ; 
        else y = y - x;

    cout << x;

    return 0 ;
}