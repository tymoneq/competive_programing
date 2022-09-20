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

Addable auto add(Addable auto a, Addable auto b)
{
    return a + b;
}

int main()
{
    double x{6}, y{55};
    auto result = add(x, y);
    cout << sizeof(result);
    return 0;
}
