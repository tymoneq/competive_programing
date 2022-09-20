#include <iostream>
using namespace std;


int main()
{
    int n, liczba = 0;
    int k = 2;
    cin >>n;

    while (n > 1)
    {   
        if (n%k==0){
            liczba++;
            n/=k;
        }

        else{ if (liczba>0) cout << k << " " << liczba <<endl;
            k++;
            liczba=0;
        }
    }
    if (liczba>0) cout << k << " " << liczba << endl;

    return 0 ;
}