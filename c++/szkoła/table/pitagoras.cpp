#include <iostream>

using namespace std;

bool czyPitagoras(int a, int b , int c){
    return (a*a + b*b == c*c);
}
int n, a,b,c;
int main(){
    cin >> n;
    for(a=1 ; a<=n; a++){
        for(b=1; b<=n ; b++){
            for(c=1; c<=n; c++){
                if (a < b){
                    if(czyPitagoras(a,b,c)){
                        cout << a << " "<< b << " "<< c << endl;
                    }
                }
            }
        }
    }


    return 0;
}