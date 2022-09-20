#include <bits/stdc++.h>

using namespace std;

int sum(int a, int b)
{
    int result = a + b;
    cout << "In : &result(int) : " << &result << "\n";
    return result;
}
int main()
{

    int a{34}, b{566};
    int result = sum(a,b);
    cout << "Out : & result(int) : " << &result << "\n";
    cout << "sum: " << result << "\n"; 
    return 0;
}