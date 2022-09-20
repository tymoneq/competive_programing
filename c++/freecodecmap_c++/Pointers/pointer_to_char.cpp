#include <bits/stdc++.h>

using namespace std;

int main()
{
    const char *p_char_var{"Hello World!"};
    cout << p_char_var << endl;
    cout << *p_char_var << endl;

    char message1[]{"Hello Wordl!"};
    message1[0] = 'B';
    cout << message1 << endl;

    return 0;
}