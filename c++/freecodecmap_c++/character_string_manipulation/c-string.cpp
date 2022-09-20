#include <bits/stdc++.h>
#include <cstring>

using namespace std;
// https://en.cppreference.com/w/cpp/header/cstring
int main()
{
    const char message1[]{"The sky is blue."};
    cout << strlen(message1) << endl;

    const char *string_data1{"Alabama"};
    const char *string_data2{"Blabama"};

    cout << strcmp(string_data1, string_data2) << endl;
    return 0;
}