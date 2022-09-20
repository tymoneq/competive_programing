#include <bits/stdc++.h>

using namespace std;

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
public:
    double volume()
    {
        return PI * pow(base_radius, 2) * height;
    }

public:
    double base_radius{1.0};
    double height{1.0};
};

int main()
{
    Cylinder cylinder1;
    cout << "volume c1 : " << cylinder1.volume() << "\n";

    cylinder1.base_radius = 30.0; // error if in private
    cylinder1.height = 6.5;       // error if in private

    cout << "Volume c1 : " << cylinder1.volume() << "\n";

    return 0;
}