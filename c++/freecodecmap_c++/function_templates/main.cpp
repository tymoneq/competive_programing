#include <bits/stdc++.h>

using namespace std;

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}
template <typename T>
T multiply(T a, T b)
{
    return a * b;
}
int main()
{

    int a{10}, b{435};
    int *p_x{&a};
    int  *p_y(&b);
    double c{44.6}, d{556.7};

    string e{"Hello"}, f{"World"};

    cout << "max int " << maximum(a, b) << "\n";
    cout << "max double " << maximum(c, d) << "\n";
    cout << "max string " << maximum(e, f) << "\n";
    cout << "Multi " << multiply(a, b) << "\n";
    // Error cout << "Multi " << multiply(e,f) << "\n";
    // Eror cout << "max int and double " << maximum(a,d) <<  "\n";
    cout << "max int pointer " << maximum(p_x, p_y) << "\n";
    delete p_x;
    delete p_y;
    return 0;
}
