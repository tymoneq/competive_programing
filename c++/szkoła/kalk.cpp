#include <iostream>
using namespace std;

int a,c;
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
        case '%':  cout << a %c;
    }
    if(b=='+'){
        cout << a+c << endl;
    }
    if(b=='-'){
        cout<< a-c << endl;
    }
    if (b=='*'){
        cout << a*b << endl;
    }
    if ((b=='/') && (c !=0)){
            cout << a/c;
        }

    else{
        cout << "Dzielenie przez zero";
    }

    if (b=='%'){
        cout << a %c;
    }
    return 0;
}
