#include <iostream>
using namespace std;

int x, y, kura, krowa;
int main(){

    cin >> x >> y ; // Wczystaj liczbe głów i nóg
    kura = 2*x - 0.5* y;
    krowa = x - kura;
    cout << kura << " " << krowa;
    

    return 0;

}