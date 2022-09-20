#include <iostream>
using namespace std;

int x, maxi,mini;
int main(){

    cin >> x;
    mini = x;
    maxi = x;
    while (cin >> x)
    {
        if (x < mini) mini = x;
        if (x> maxi) maxi = x;
    
    }
    cout << mini << " " << maxi;
    return 0;
}
