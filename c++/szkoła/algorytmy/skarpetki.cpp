#include <iostream>

using namespace std;

string skarpetki, znak;
int dl, biale = 0, czarne = 0, pary=0 ,b_pary = 0, c_pary = 0;
int main(){
    cin >> skarpetki;
    dl = size(skarpetki);
    
    for (int i=0; i< dl; i++){
        znak = skarpetki[i];
        if( znak == "B"){
            biale += 1;
        }
        else if (znak == "C"){
            czarne += 1;
        }
    }

    b_pary = biale / 2;
    c_pary = czarne /2;
    pary = b_pary + c_pary;
    cout << pary;
    
    return 0;
}