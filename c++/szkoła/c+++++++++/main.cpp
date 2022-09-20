#include <bits/stdc++.h>

using namespace std;
string s, out;
char litera;
int A[1000000];
int B[1000000];

ifstream infile;
ifstream file_out;
ofstream result;
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
    infile.open("in1.txt");
    file_out.open("out1.txt");
    result.open("result.txt");
    while (getline(infile, s) && getline(file_out, out))
    {
        string liczba = "", pom = "";
        int k = 1;
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
        if (to_string(k) == out)
        {
            result << "[+] True"
                   << "\n";
        }
        else
        {
            result << "[-] Error in output " << out << " expected output " << k << "\n";
        }
    }
    infile.close();
    file_out.close();
    result.close();
    return 0;
}
