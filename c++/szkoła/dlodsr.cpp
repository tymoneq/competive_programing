#include <iostream>
#include <cmath>
using namespace std;

long long int t,x,y;
float odl,maks = 0;
int main(){
    cin >>t;
    for (int i=0; i<t; i++){
        cin >> x >> y;
        odl = sqrt(x*x+y*y);
        if (odl > maks) maks = odl;
    }
    cout.precision(2);
    cout << fixed << maks;
    return 0;
}

