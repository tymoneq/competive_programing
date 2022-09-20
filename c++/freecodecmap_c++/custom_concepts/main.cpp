#include <bits/stdc++.h>

using namespace std;

template <typename T>
concept MyIntegral = is_integral_v<T>;
/*
template <typename T>
requires MyIntegral<T>
    T add(T a, T b)
{
    return a + b;
}

MyIntegral auto add(MyIntegral auto a, MyIntegral auto b)
{
    return a + b;
}
*/

template <typename T>
concept Multipliable = requires(T a, T b)
{
    a *b;
};

template <typename T>
requires Multipliable<T>
    T add(T a, T b)
{
    return a * b;
}

int main()
{
    double x{7}, y{6};
    cout << add(x, y) << '\n';

    return 0;
}