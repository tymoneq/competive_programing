#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int  szescian, suma, a_range;
bool runing = true;
string number, z;
int main(){

    for(int i = 1; i <=10000; i++){
        suma = 0;
        szescian = pow(i,3);
        number = to_string(szescian);
        a_range = number.size();

        for(int j = 0; j < a_range; j++){
            z = number[j];
            suma += stoi(z);
        }
        if(suma == i){
            cout << i<< endl;
    }
    }

    
    return 0;
}