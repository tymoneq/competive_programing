#include <iostream>

using namespace std;


int a, b;
int main(){

    cin >> a;
    for (int i =0; i<a; i++){
        cin >> b;
        cout << ((b / 30) + 1 )*30 << endl; 
    }


    return 0;
}