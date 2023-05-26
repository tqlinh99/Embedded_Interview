/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create classes to contain properties of a date and some methods to do math with day
*/

#include <stdio.h>
#include <stdint.h>

/*
 * Function: Class Date
 * Description: The class contains properties of a date
 * Input:
 *    None
 * Output:
 *    None
*/
class Date{
    private:
        uint8_t Day;
        uint8_t Month;
        uint16_t Year;
        uint8_t daysInMonth(uint8_t Month, uint16_t Year);
    public:
        Date(uint8_t d=1, uint8_t m=1, uint16_t y=1900);
        void setDay(uint8_t d);
        uint8_t getDay();
        void setMonth(uint8_t m);
        uint8_t getMonth();
        void setYear(uint16_t y);
        uint16_t getYear();
};

/*
* Function: Constructor Date
* Description: import day, month and year of a date
* Input:
*    d: uint8_t
*    m: uint8_t
*    y: uint16_t
* Output:
*    None
*/
Date::Date(uint8_t d, uint8_t m, uint16_t y){
    while(((m < 1) & (m>12))||(d>daysInMonth(m,y))){
        printf("Error!!! %d/%d/%d khong ton tai!\n",d,m,y);
        printf("Moi Nhap Lai: \n");
        printf("Nhap ngay: \n");
        scanf("%d", d);
        printf("Nhap thang: \n");
        scanf("%d", m);
        printf("Nhap nam: \n");
        scanf("%d", y);
    }
    Date::Day = d;
    Date::Month = m;
    Date::Year = y;
}

/*
* Function: Date::daysInMonth()
* Description: determine day number of a specific month depend on year
* Input:
*    m: uint8_t
*    y: uint16_t
* Output:
*    return day number
*/
uint8_t Date::daysInMonth(uint8_t m, uint16_t y){
    switch(m)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if ((y%4==0)&(y%100!=0))     return 29;
            else    return 28;

        default:
            return 31;
    }
}

/*
 * Function: Date::setDay()
 * Description: set day
 * Input:
 *    d: uint8_t
 * Output:
 *    none
*/
void Date::setDay(uint8_t d){
    Date::Day = d;
}

/*
 * Function: Date::getDay()
 * Description: used to get day
 * Input:
 *    none
 * Output:
 *    return day in type of uint8_t
*/
uint8_t Date::getDay(){
    return Date::Day;
}

/*
 * Function: Date::setMonth()
 * Description: set month
 * Input:
 *    m: uint8_t
 * Output:
 *    none
*/
void Date::setMonth(uint8_t m){
    Date::Month = m;
}

/*
 * Function: Date::getMonth()
 * Description: used to get month
 * Input:
 *    none
 * Output:
 *    return month in type of uint8_t
*/
uint8_t Date::getMonth(){
    return Date::Month;
}

/*
 * Function: Date::setYear()
 * Description: set year
 * Input:
 *    y: uint16_t
 * Output:
 *    none
*/
void Date::setYear(uint16_t y){
    Date::Year = y;
}

/*
 * Function: Date::getYear()
 * Description: used to get year
 * Input:
 *    none
 * Output:
 *    return year in type of uint16_t
*/
uint16_t Date::getYear(){
    return Date::Year;
}

/*
 * Function: Class dayMath
 * Description: The class contains properties and methods to do math with 2 dates
 *    None
 * Output:
 *    None
*/
class dayMath{
    private:
        Date A;
        Date B;
    public:
        dayMath(Date a, Date b);
        uint16_t ageCalculator();
        bool dayOffCheck();
};

/*
* Function: Constructor dayMath
* Description: import 2 dates to object belongs to class dayMath
* Input:
*    a: Date
*    b: Date
* Output:
*    None
*/
dayMath::dayMath(Date a, Date b){
    dayMath::A = a;
    dayMath::B = b;
}

/*
 * Function: dayMath::ageCalculator()
 * Description: calculate number of year between 2 dates
 * Input:
 *    none
 * Output:
 *    return number of year in type of uint16_t
*/
uint16_t dayMath::ageCalculator(){
    if (A.getMonth()>B.getMonth()){
        return B.getYear()-A.getYear()-1;
    }else if(A.getMonth()<B.getMonth()){
        return B.getYear()-A.getYear();
    }else{
        if (A.getDay()>B.getDay()){
            return B.getYear()-A.getYear()-1;
        }else{
            return B.getYear()-A.getYear();
        }
    }
}

/*
 * Function: dayMath::dayOffCheck()
 * Description: check if the entered is offday or not
 * Input:
 *    none
 * Output:
 *    return true or false in type of bool
*/
bool dayMath::dayOffCheck(){
    return true;
}

int main(int argc, char const *argv[])
{
    Date d1(17, 3, 1999);
    Date d2(18, 3, 2023);
    dayMath exp(d1, d2);
    printf("tuoi:%d\n", exp.ageCalculator());
    return 0;
}

