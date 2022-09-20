#include <bits/stdc++.h>

using namespace std;

template <typename T>
concept TinyType = requires(T t)
{
    // sizeof(T) < 4;
    requires sizeof(T) <= 4;
};

template <typename T>
concept Addable = requires(T a, T b)
{
    {
        a + b
    }
    noexcept->convertible_to<int>;
};

template <typename T>
// requires integral<T> || floating_point<T>
requires TinyType<T> && integral<T>
    T add(T a, T b)
{
    return a + b;
}

int main()
{
    long int x{6}, y{5};

    cout << add(x, y);
    return 0;
}