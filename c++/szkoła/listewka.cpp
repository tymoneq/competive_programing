#include <iostream>
using namespace std;



int NWW (int a, int b) {

    int pom=a*b;
    while (a!=b)
        if (a>b) a=a-b;
        else b =b-a;
    
    return pom/a;
}

int n , x , y, nww, wynik;

int main(){

    cin >> n >> x>> y;
    nww = NWW(x,y); 
    wynik = (n/  nww) - 1;
    cout << wynik << endl; 

    return 0;
}