#include <iostream>
using namespace std;

int a,c;
char b;
int main()
{
    cin >> b >> a >> c ;

    switch (b){
        case '+': cout << a+c << endl; break;
        case '-': cout<< a-c << endl; break;
        case '*': cout<< a*c << endl; break;
        case '/': if (c!=0) cout << a/c << endl; 
                    else cout << "null"; break;
    }
   
   return 0;

}