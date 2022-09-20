#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << isalnum('*') << endl;

    char input_char{'l'};
    if (isalnum(input_char))
    {
        cout << "Is alfanumeric" << endl;
    }
    else
    {
        cout << "Is not alfanumeric" << endl;
    }
    char message[]{"Hello there"};

    for (size_t i{0}; i < size(message); i++)
    {
        if (isblank(message[i]))
        {
            cout << "IS blank " << i << endl;
        }
    }

    cout << islower(input_char) << endl;

    char test{'5'};
    char dest_str[size(message)]{};


    cout << isdigit(test) << endl;
    for (size_t i{0}; i < size(message); i++)
    {
        dest_str[i] = toupper(message[i]);
    }
    cout << dest_str << endl;

    return 0;
}