/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create some classes to contain properties of a point and some method to do Oxy math with 2 or 3 points
*/

#include <stdio.h>
#include <stdint.h>
#include <cmath>

/*
 * Function: Class Diem
 * Description: The class contains all properties and methods of a point
 * Input:
 *    None
 * Output:
 *    None
*/
class Diem{
    private:
        int8_t X;
        int8_t Y;
    public:
        Diem(int8_t x = 0, int8_t y = 0);
        int8_t getX();
        int8_t getY();
};

/*
* Function: Constructor Diem
* Description: import input parameters for an object belong to class Diem
* Input:
*    x: int8_t
*    y: int8_t
* Output:
*    None
*/
Diem::Diem(int8_t x, int8_t y){
    Diem::X = x;
    Diem::Y = y;
}

/*
 * Function: SinhVien::getX()
 * Description: used to get x
 * Input:
 *    none
 * Output:
 *    return x in type of int8_t
*/
int8_t Diem::getX(){
    return Diem::X;
}

/*
 * Function: SinhVien::getY()
 * Description: used to get y
 * Input:
 *    none
 * Output:
 *    return y in type of int8_t
*/
int8_t Diem::getY(){
    return Diem::Y;
}

/*
 * Function: Class PheptoanOXY
 * Description: The class contains properties and methods to do Oxy math with 2 or 3 points
 * Input:
 *    None
 * Output:
 *    None
*/
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

/*
* Function: Constructor Diem
* Description: import 2 points and choose to calculate distance between 2 points
* Input:
*    a: Diem
*    b: Diem
* Output:
*    None
*/
PheptoanOXY::PheptoanOXY(Diem a, Diem b){
    PheptoanOXY::A = a;
    PheptoanOXY::B = b;
    kiemTra = KhoangCach;
}

/*
* Function: Constructor Diem
* Description: import 3 points and choose to calculate area of triangle made from these 3 points
* Input:
*    a: Diem
*    b: Diem
*    c: Diem
* Output:
*    None
*/
PheptoanOXY::PheptoanOXY(Diem a, Diem b, Diem c){
    PheptoanOXY::A = a;
    PheptoanOXY::B = b;
    PheptoanOXY::C = c;
    PheptoanOXY::kiemTra = DienTich;
}

/*
 * Function: PheptoanOXY::KhoangCach2Diem()
 * Description: calculate distance between 2 points
 * Input:
 *    none
 * Output:
 *    display result
*/
double PheptoanOXY::KhoangCach2Diem(){
    if (kiemTra == KhoangCach)
    {
        return printf("%.2f",sqrt(pow(A.getX()-B.getX(),2)+pow(A.getY()-B.getY(),2)));
    }else{
        printf("ERROR! Khong tinh duoc khoang cach\n");
    }
}

/*
 * Function: PheptoanOXY::DienTichTamGiac()
 * Description: calculate area of a triangle made from 3 points
 * Input:
 *    none
 * Output:
 *    display result
*/
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

