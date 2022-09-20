#include <iostream>
using namespace std;
int x, maxi, mini;
int main(){
    cin >> x;
    if (x % 3 == 0){
        mini = x;
        maxi = x;
    }
    else{
    maxi = 0;
    mini = 921743865;
    }
    while (cin >> x)
    {
       if (x % 3 == 0){
            if (x < mini) mini = x;
            if (x > maxi) maxi = x;
            
       }
    }
    
    cout << mini << " " << maxi;
    return 0;
}