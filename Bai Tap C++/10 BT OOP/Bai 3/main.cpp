/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create a class to contain properties of a circle and some method to do math with circle
*/

#include <stdio.h>
#include <stdint.h>
#include <cmath>

/*
 * Function: Class Circle
 * Description: The class contains properties and methods of a circle
 * Input:
 *    None
 * Output:
 *    None
*/
class Circle{
    private:
        double Radius;
    public:
        Circle(double r);
        double perimeter();
        double area();
};

/*
* Function: Constructor Circle
* Description: import input parameters for an object belong to class Circle
* Input:
*    r: double
* Output:
*    None
*/
Circle::Circle(double r){
    Circle::Radius = r;
}

/*
 * Function: Circle::perimeter()
 * Description: calculate perimeter of a circle
 * Input:
 *    none
 * Output:
 *    return perimeter of a circle in type of double
*/
double Circle::perimeter(){
    return (Radius*2)*M_PI;
}

/*
 * Function: Circle::area()
 * Description: calculate area of a circle
 * Input:
 *    none
 * Output:
 *    return area of a circle in type of double
*/
double Circle::area(){
    return pow(Radius,2)*M_PI ;
}

int main(int argc, char const *argv[])
{
    Circle ht(7);
    printf("Chu vi: %.2f\nDien Tich: %.2f\n", ht.perimeter(), ht.area());
    return 0;
}