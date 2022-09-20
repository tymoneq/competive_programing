#include <bits/stdc++.h>
#include "fun_decl.h"
using namespace std;


int main()
{
    int a,b;
    cin >> a >> b;
    cout << max(a,b) << endl;
    cout << "min" << min(a,b) << endl;
    cout << incr_multi(a,b) << endl;
    return 0;
}