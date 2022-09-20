#include <iostream>
using namespace std;


int x,a,b,c;
char r;
int main()
{
    
    cout << "Podaj liczbe: " << endl;
    cin >> x;
    if (x >= 0 ) {
        cout << x << endl;
        if (x == 0 ){
            cout << "0" << endl;
        }
        else{
            cout << "+" << endl;
        }
    }

    else if (x < 0 ) {  
        x = x * -1;
        cout << x << endl;
        cout << "-" << endl;
    }

    if (x % 2 == 0 ){
        cout << "Liczba jest parzysta" << endl;
    }
    else if (x % 2 != 0){
        cout << "Liczba nie jest parzysta" << endl;
    }


    cout <<"Podaj trzy liczby" << endl;
    cin >> a >> b >> c;
 
    if (a < b && a < c ){
        cout << a << " jest najmniejsza" << endl;
    }
    else if ( b < a && b < c ){
        cout << b << " jest najmniejsza" << endl;
    }
    else if ( c < a && c < b){
        cout << c << " jest najmniejsza" << endl;
    }

    cout << "Podaj symbol" << endl;
    cin >> r;
    if ((r =='a') || (r=='e') || (r=='i') || (r='o') || (r=='u') || (r=='y') ){
        cout << "JEST" ; 
    }
    return 0;
}