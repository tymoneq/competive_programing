#include <bits/stdc++.h>

using namespace std;

struct Cat
{
    string m_name;
};

struct Point
{
    double point_x{0};
    double point_y{0};
};

void print_point(const Point &point)
{
    cout << point.point_x << " " << point.point_y <<"\n";
}

int main()
{

    Cat cat1;
    cat1.m_name = "Coco";

    Point point(2,2);
    print_point(point);
    cout << cat1.m_name;
    return 0;
}