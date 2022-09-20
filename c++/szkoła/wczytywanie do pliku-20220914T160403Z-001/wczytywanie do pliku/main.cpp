#include <iostream>
#include <fstream>


using namespace std;
string s, liczba = "", pom = "";
char litera;
int A[1000000];
int B[1000000];
int k = 1;
ifstream file;
ofstream file_out;
int zamien(string a)
{
    int potega = 1, wynik = 0, cyfra;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        cyfra = a[i];
        cyfra -= 48;
        wynik += cyfra * potega;
        potega *= 10;
    }
    return wynik;
}

int main()
{
    file.open("data.txt");
    file_out.open("result.txt");
    for (size_t i{0}; i < 100; i++){
    file >> s;
    litera = s[0];
    for (int i = 1; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            liczba = liczba + s[i];
        else
        {
            for (int i = 0; i < zamien(liczba); i++)
                pom = pom + litera;
            liczba = "";
            litera = s[i];
        }
    for (int i = 0; i < zamien(liczba); i++)
        pom = pom + litera;
    s = pom;

    A[0] = 0;
    for (int i = 1; i <= s.size(); i++)
        if (s[i - 1] == 'a')
            A[i] = A[i - 1] + 1;
        else
            A[i] = A[i - 1];
    B[s.size() + 1] = 0;
    for (int i = s.size(); i >= 1; i--)
        if (s[i - 1] == 'b')
            B[i] = B[i + 1] + 1;
        else
            B[i] = B[i + 1];
    for (int i = 0; i <= s.size(); i++)
        if ((A[i] + B[i + 1]) > k)
            k = A[i] + B[i + 1];
    file_out << k << "\n";
    }
    file.close();
    file_out.close();
    return 0;
}

