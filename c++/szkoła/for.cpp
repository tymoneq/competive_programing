#include <iostream>
using namespace std;
int dzies = 0, potega=1, dl;
string bin;

int main(){

    cin >> bin;
    dl = bin.size();
    for (int i=dl-1; i>=0; i--){
        if (bin[i]=='1')dzies=dzies+potega;
        potega*=2;

    }
    cout << dzies;

    return 0;
}