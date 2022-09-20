#include <bits/stdc++.h>

using namespace std;
/*
template <typename T>
requires integral<T>
    T add(T a, T b)
{
    return a + b;
}


template <integral T>

T add(T a, T b)
{
    return a + b;
}


auto add(integral auto a,  integral auto b)
{
    return a + b;
}
*/

template <typename T>
T add(T a, T b) requires integral<T>
{
    return a + b;
}

int main()
{
    int a{8}, b{7};
    auto result = add(a, b);
    cout << "result " << result << "\n";

    char c{10}, d{6};
    auto resut_a = add(c, d);
    cout << "result_a " << static_cast<int>(resut_a) << '\n';

    // double e{5.6}, f{7.7};
    // auto result_b = add(e, f);
    // cout << result_b << "\n";

    return 0;
}