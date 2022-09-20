#include <bits/stdc++.h>

using namespace std;

template <typename T>
const T &maximum(const T &a, const T &b)
{
    cout << "In- &a " << &a << "\n";
    return (a > b) ? a : b;
}
int main()
{
    int a{10}, b{435};
    double c{44.6}, d{556.7};
    string e{"Hello"}, f{"World"};
    cout << "Out- &a " << &a << "\n";
    auto result =  maximum(a, b);
    cout << "Out- &a " << &a << "\n";

    return 0;
}