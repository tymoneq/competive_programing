#include <iostream>
using namespace std;

int a,b,c, wynik;
int main(){
    cin >> a >> b >> c;
    wynik= 0;
    
    if ((a <= b) && (a!=0)){
        if (a <=c){
            if (b <=c){
                wynik = 100 * a + 10 * b + c;
            }
            else{
                wynik = 100*a + 10*c + b;
            }
}
        else if((c<=a)&&(c!=0)){
            wynik = 100* c + 10* a + b;
        }
        else if((c<=a)&&(c==0)){
            wynik = 100* a + 10* c + b;
            }
    }
    else {
        if((b<=c)&&(b!=0)){
            if(a<=c){
                wynik = 100*b + 10*a + c;
            }
            else {
                wynik = 100*b + 10*c+ a;
            }
        }
        else if((b<=c)&&(c!=0)){
            wynik = 100*c + 10*b + a;
        }
        else if((c<=a)&&(c==0)){
            wynik = 100* b + 10* c + a;
            }

    }
    cout << wynik;
    
    return 0;
}