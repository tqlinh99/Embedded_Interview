#include <stdio.h>
#include <stdint.h>

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
        void setYear(uint8_t y);
        uint16_t getYear();
};

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

void Date::setDay(uint8_t d){
    Date::Day = d;
}

uint8_t Date::getDay(){
    return Date::Day;
}

void Date::setMonth(uint8_t m){
    Date::Month = m;
}

uint8_t Date::getMonth(){
    return Date::Month;
}

void Date::setYear(uint8_t y){
    Date::Year = y;
}

uint16_t Date::getYear(){
    return Date::Year;
}

class dayMath{
    private:
        Date A;
        Date B;
    public:
        dayMath(Date a, Date b);
        uint16_t ageCalculator();
        bool dayOffCheck();
};

dayMath::dayMath(Date a, Date b){
    dayMath::A = a;
    dayMath::B = b;
}

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

