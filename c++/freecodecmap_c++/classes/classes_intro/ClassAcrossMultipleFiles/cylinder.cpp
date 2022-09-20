/**
 * The function volume() returns the volume of the cylinder
 * 
 * @param rad_param radius of the cylinder
 * @param height_param the height of the cylinder
 */
#include "cylinder.h"

Cylinder::Cylinder(double rad_param, double height_param)
{
    base_radius = rad_param;
    height = height_param;
}
double Cylinder::get_base_radius()
{
    return base_radius;
}

double Cylinder::get_height()
{
    return height;
}

// setters
void Cylinder::set_base_radius(double radius_param)
{
    base_radius = radius_param;
}

void Cylinder::set_height(double height_param)
{
    height = height_param;
}
double Cylinder::volume()
{
    return PI * pow(base_radius, 2) * height;
}
