#include <iostream>
#include <string>
using namespace std;

int quanity, a, c , wynik,int_b, winners, max_p;
string cards,b, id, text_g;

int main(){
    winners = 0;
    max_p = 0;
    id = "";
    cin >> quanity;
    int list_of_results [quanity];
    for (int i = 0; i < quanity; i++){
        cin >> cards;
        a = size(cards);
        wynik = 0;
        for (int j = a-1; j >= 0; j--){
            

            b = cards[j];
            if ((b == "2") || (b == "3") || (b=="4") || (b=="5") || (b== "6") || (b== "7") || (b == "8") || (b == "9")){
                int_b = stoi(b);
                wynik += int_b;
            }

            else if ((b=="T") || (b == "J") || (b=="Q") || (b=="K")){
                wynik += 10;
            }

            else if (b == "A"){
                if (wynik + 11 <= 21){
                    wynik += 11;
                }

                else{
                    wynik += 1;
                }
            }
        }
        if (wynik > 21){
                wynik = -1;
            }
    list_of_results[i] = wynik;
    if( wynik > max_p){
        max_p = wynik;
    }
    }


    int l = 0;
    for (int h: list_of_results ){
        if (h == max_p) {
            winners += 1;
            id += to_string(l+1) + " ";

        }
        l += 1;
    }

    cout << winners << endl;
    cout << id;

    return 0;
}