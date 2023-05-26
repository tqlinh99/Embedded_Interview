/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create a class to contain properties of a rectangle and some method to do math with rectangle
*/

#include <stdio.h>
#include <stdint.h>
#include <cmath>

/*
 * Function: Class Rectangle
 * Description: The class contains properties and methods of a rectangle
 * Input:
 *    None
 * Output:
 *    None
*/
class Rectangle{
    private:
        double Width;
        double Length;
    public:
        Rectangle(double l, double w);
        double perimeter();
        double area();
        double diagonal();
        bool squareCheck();
};

/*
* Function: Constructor Rectangle
* Description: import input parameters for an object belong to class Rectangle
* Input:
*    l: double
*    w: double
* Output:
*    None
*/
Rectangle::Rectangle(double l, double w){
    Rectangle::Length = l;
    Rectangle::Width = w;
}

/*
 * Function: Rectangle::perimeter()
 * Description: calculate perimeter of a rectangle
 * Input:
 *    none
 * Output:
 *    return perimeter of a rectangle in type of double
*/
double Rectangle::perimeter(){
    return (Length+Width)/2;
}

/*
 * Function: Rectangle::area()
 * Description: calculate area of a rectangle
 * Input:
 *    none
 * Output:
 *    return area of a rectangle in type of double
*/
double Rectangle::area(){
    return Length*Width;
}

/*
 * Function: Rectangle::diagonal()
 * Description: calculate diagonal of a rectangle
 * Input:
 *    none
 * Output:
 *    return diagonal of a rectangle in type of double
*/
double Rectangle::diagonal(){
    return sqrt(pow(Length,2)+pow(Width,2));
}

/*
 * Function: Rectangle::squareCheck()
 * Description: check the length and the width to determine this shape is square or not
 * Input:
 *    none
 * Output:
 *    return result (false or true) in type of bool
*/
bool Rectangle::squareCheck(){
    if(Length == Width){
        return true;
    }else{
        return false;
    }
}

int main(int argc, char const *argv[])
{
    Rectangle hcn(5,5);
    printf("Chu vi: %.2f\nDien Tich: %.2f\nDuong Cheo: %.2f\nCo phai hinh vuong khong: %s", hcn.perimeter(), hcn.area(), hcn.diagonal(),hcn.squareCheck() ? "true":"false");
    return 0;
}
