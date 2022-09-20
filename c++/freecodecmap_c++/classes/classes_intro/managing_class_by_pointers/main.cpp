#include <bits/stdc++.h>

using namespace std;

const double PI{3.1415926535897932384626433832795};

/* A class is a blueprint for an object */
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

    Cylinder *c2 = new Cylinder(11, 20);
    cout << "volume c2 : " << (*c2).volume() << "\n";
    cout << "volume c2: " << c2->volume() << "\n";


    Cylinder *c3 = &cylinder1;

    cout << "volume c3 : " << (*c3).volume() << "\n";
    cout << "volume c3: " << c3->volume() << "\n";
    delete c2;
    return 0;
}