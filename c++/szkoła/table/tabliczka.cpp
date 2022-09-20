#include <iostream>

using namespace std;

int m , n, suma;
int main(){
    cin >> m >> n;
    for(int i=1; i <= m; i++){
        for(int j = 1; j <=n; j++){
            suma = j *i;
            cout << suma << " ";

        }
        cout << endl;
    }


    return 0;
}