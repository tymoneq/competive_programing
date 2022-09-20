//The above code is defining a class called Cylinder. It has a default constructor and a constructor that takes two parameters. It also has getters and setters for the base radius and height. It also has a function called volume that returns the volume of the cylinder.
#include "constants.h"
#include <bits/stdc++.h>
#ifndef CYLINDER_H
#define CYLINDER_H
class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double rad_param, double height_param);

    // getters
    double get_base_radius();

    double get_height();

    // setters
    void set_base_radius(double radius_param);

    void set_height(double height_param);

    double volume();

private:
    double base_radius{1.0};
    double height{1.0};
};

#endif