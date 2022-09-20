#include <iostream>
#include <concepts>
#include <type_traits>

using namespace std;

template <typename T>
concept MyIntegral = is_integral_v<T>;

template <typename T>
requires MyIntegral<T>
    T add(T a, T b)
{
    return a + b;
}

int main()
{
    int x{7}, y{6};
    cout << add(x, y) << '\n';

    return 0;
}