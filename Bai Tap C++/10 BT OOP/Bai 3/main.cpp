#include <stdio.h>
#include <stdint.h>
#include <cmath>

class Circle{
    private:
        double Radius;
    public:
        Circle(double r);
        double perimeter();
        double area();
};

Circle::Circle(double r){
    Circle::Radius = r;
}

double Circle::perimeter(){
    return (Radius*2)*M_PI;
}

double Circle::area(){
    return pow(Radius,2)*M_PI ;
}

int main(int argc, char const *argv[])
{
    Circle ht(7);
    printf("Chu vi: %.2f\nDien Tich: %.2f\n", ht.perimeter(), ht.area());
    return 0;
}