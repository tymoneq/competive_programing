#include <iostream>
#include <string>

using namespace std;

string word, oij;
int wynik, size_a;
int main(){
    wynik = 0;
    oij = "";
    cin >> word;
    size_a = size(word);
    for(int i = 0; i< size_a; i++){
        
        if(word[i] == 'o'){
            if(oij==""){
                oij = "o";
            }      
            
        }
        else if(word[i] == 'i'){
            if(oij == "o"){
                oij = "oi";
               
            }
        }
        else if(word[i]=='j'){
            if(oij == "oi"){
                oij ="oij";
                
            }
        }
        if(oij =="oij"){
            oij ="";
            wynik+=1;
        }
       
    }
    if(wynik == 0){
        cout << "NIE" << endl;
    }
    else {
        cout << wynik << endl;
    }
    return 0;
}