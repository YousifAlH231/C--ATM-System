#include <iostream>
#include <cmath>
using namespace std;
struct circle{
    double radius;
    double area;
    double circumferenece;
    
};

const double pi = 4 * atan(1.0);

void calculateArea(circle &shape){
    shape.area = pi * pow(shape.radius, 2);
}
circle calculateCircumference(circle shape2){
    shape2.circumferenece = 2 * pi * shape2.radius;
    return shape2;
}

void print(circle shape3){
    cout << "The radius of the circle is: " << shape3.radius << endl;
    cout << "The area of the circle is: " << shape3.area << endl;
    cout << "The circumderence of the circle is: " << shape3.circumferenece << endl;
} 

int main()
{
    circle shape;
    cout << "Enter the radius of the circle: ";
    cin >> shape.radius;
    calculateArea(shape);
    shape = calculateCircumference(shape);
   
    print(shape);
    return 0;
}
