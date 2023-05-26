#include <stdio.h>
#include <stdint.h>
#include <cmath>

class Diem{
    private:
        int8_t X;
        int8_t Y;
    public:
        Diem(int8_t x = 0, int8_t y = 0);
        int8_t getX();
        int8_t getY();
};

Diem::Diem(int8_t x, int8_t y){
    Diem::X = x;
    Diem::Y = y;
}

int8_t Diem::getX(){
    return Diem::X;
}

int8_t Diem::getY(){
    return Diem::Y;
}

class PheptoanOXY{
    private:
        Diem A;
        Diem B;
        Diem C;
        typedef enum{
            KhoangCach,
            DienTich
        }PhepToan;
        PhepToan kiemTra;
    public:
        PheptoanOXY(Diem a, Diem b);
        PheptoanOXY(Diem a, Diem b, Diem c);
        double KhoangCach2Diem();
        double DienTichTamGiac();
};

PheptoanOXY::PheptoanOXY(Diem a, Diem b){
    PheptoanOXY::A = a;
    PheptoanOXY::B = b;
    kiemTra = KhoangCach;
}

PheptoanOXY::PheptoanOXY(Diem a, Diem b, Diem c){
    PheptoanOXY::A = a;
    PheptoanOXY::B = b;
    PheptoanOXY::C = c;
    PheptoanOXY::kiemTra = DienTich;
}

double PheptoanOXY::KhoangCach2Diem(){
    if (kiemTra == KhoangCach)
    {
        return printf("%.2f",sqrt(pow(A.getX()-B.getX(),2)+pow(A.getY()-B.getY(),2)));
    }else{
        printf("ERROR! Khong tinh duoc khoang cach\n");
    }
}

double PheptoanOXY::DienTichTamGiac(){
    if (kiemTra == DienTich)
    {
        return printf("%.2f",(double(1)/2)*fabs((B.getX()-A.getX())*(C.getY()-A.getY())-(C.getX()-A.getX())*(B.getY()-A.getY())));
    }else{
        printf("ERROR! Khong tinh duoc dien tich\n");
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}

