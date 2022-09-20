#include <bits/stdc++.h>

using namespace std;

void max_str(const string &input1, const string input2, string &output)
{
    if (input1 > input2)
        output = input1;
    else
        output = input2;
}

void min(int a, int b, int &output)
{
    if (a < b)
        output = a;
    else
        output = b;
}

void max_double(double input1, double input2, double *output)
{
    if (input1 > input2)
    {
        *output = input1;
    }
    else
        *output = input2;
}

int main()
{
    /*
    string str1("Cassablanca");
    string str2("Belleuve");
    string output;
    max_str(str1, str2, output);
    cout << "Max_Str " << output << "\n";

    int out_int;
    int int1{46}, int2{55};
    min(int1, int2, out_int);
    cout << "Min " << out_int << "\n";
    */
    double out;
    double double_1{66.5}, double_2{55.6};
    max_double(double_1, double_2, &out);
    cout << out << '\n';
    return 0;
}