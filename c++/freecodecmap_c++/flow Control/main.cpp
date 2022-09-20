#include <iostream>

using namespace std;

int main()
{
    const int num {6};
    switch (num)
    {
    case 5: {
        cout << false << endl;
    }
        break;
    case 4:{
        cout << true << endl;
    }
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
    return 0;
    
}