#include <stdio.h>
#include <stdint.h>
#include <cmath>

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

Rectangle::Rectangle(double l, double w){
    Rectangle::Length = l;
    Rectangle::Width = w;
}

double Rectangle::perimeter(){
    return (Length+Width)/2;
}

double Rectangle::area(){
    return Length*Width;
}

double Rectangle::diagonal(){
    return sqrt(pow(Length,2)+pow(Width,2));
}

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
