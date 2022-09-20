#include <bits/stdc++.h>

using namespace std;

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double rad_param, double height_param)
    {
        base_radius = rad_param;
        height = height_param;
    };
    double volume()
    {
        return PI * pow(base_radius, 2) * height;
    }

private:
    double base_radius{1.0};
    double height{1.0};
};

int main()
{
    Cylinder cylinder1;
    cout << "volume c1 : " << cylinder1.volume() << "\n";

    Cylinder cylinder2(55.6, 1);
    cout << "Volume c2 : " << cylinder2.volume() << "\n";

    return 0;
}