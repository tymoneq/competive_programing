#include <iostream>

using namespace std;

int n,a,b,c, licznik = 0;

int main(){

    cin >> n;
    cin >> a >> b >> c ;
    for (int i=3; i<n; i++){
        if ((a + b + c) % 3 == 0) licznik++;
        a = b;
        b = c;
        cin >> c;
    }
    if ((a + b + c) % 3 == 0) licznik++;
    cout << licznik ++; 
    return 0;
}