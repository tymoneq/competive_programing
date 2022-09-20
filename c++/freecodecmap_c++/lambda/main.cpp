#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    auto func = []()
    {
        cout << "Hello World" << "\n" ;
    };
    func();

    []() {
        cout << "Hello World!" << "\n";
    }();

    [](double a, double b)
    {
        cout << a + b
             << "\n";
    }(10.7, 5.6);

    auto func = [](double a, double b)
    {
        cout << a + b
             << "\n";
    };
    func(10, 20);
    func(44.6, 3.1415);


    auto func = [](double a, double b)
    {
        return a + b;
    };

    cout << func(10, 20) << "\n"
         << func(44.6, 3.1415);


    auto func = [](double a, double b)
    {
        return a + b;
    };
    auto result = func(23, 7);
    cout << result << '\n';
    auto result2 = func(26, 777.55);
    cout << result2 << "\n";


    auto func = [](double a, double b) -> int
    {
        return a + b;
    };
    auto result = func(23, 7);
    cout << result << '\n';
    auto result2 = func(26, 777.66);
    cout << result2 << "\n";

    double a{10}, b{20};
    auto func = [&a, &b]()
    {
        cout << a + b << "\n";
    };
    for (size_t i{}; i < 5; i++)
    {
        func();
        ++a;
        ++b;
    }

    // kopiuje wszystkie wartości
    int c{45};
    double d{678.9};
    auto func = [=]()
    {
        cout << "Inner value : " << c << "\n";
        cout << "D iner " << d << "\n";
    };
    for (size_t i{}; i < 5; ++i)
    {
        cout << "Value of C " << c << "Value of D " << d << "\n";
        func();
        ++c;
        d += 0.5;
    }
*/
    // robi referencje do wszystich wartości
    int c{45};
    double d{678.9};
    auto func = [&]()
    {
        cout << "Inner value : " << c << "\n";
        cout << "D iner " << d << "\n";
    };
    for (size_t i{}; i < 5; ++i)
    {
        cout << "Value of C " << c << "\n"
             << "Value of D " << d << "\n";
        func();
        ++c;
        d += 0.5;
    }
    return 0;
}