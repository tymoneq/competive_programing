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

    // getters
    double get_base_radius()
    {
        return base_radius;
    }

    double get_height()
    {
        return height;
    }

    // setters
    void set_base_radius(double radius_param)
    {
        base_radius = radius_param;
    }

    void set_height(double height_param)
    {
        height = height_param;
    }
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

    cout << cylinder1.get_base_radius() << "\n";
    cout << cylinder1.get_height() << "\n";
    cylinder1.set_base_radius(5);
    cylinder1.set_height(6);
    cout << "Volume c1 : " << cylinder1.volume() <<"\n";

    return 0;
}