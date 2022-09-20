#include <bits/stdc++.h>

using namespace std;

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a{10}, b{435};
    double c{44.6}, d{556.7};
    string e{"Hello"}, f{"World"};

    cout << maximum<double>(a,d) << "\n";
    

    return 0;
}