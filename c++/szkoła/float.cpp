#include <iostream>
using namespace std;


float a,c;
char b;
int main()
{
    cin >>a >> b >> c ;

    switch (b){
        case '+': cout << a+c << endl; break;
        case '-': cout<< a-c << endl; break;
        case '*': cout<< a*c << endl; break;
        case '/': if (c!=0) cout << a/c << endl; 
                    else cout << "Dzielenie przez zero"; break;
    }
    return 0;
}