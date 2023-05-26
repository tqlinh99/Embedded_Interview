#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

class Car{
    private:
        string COLOR;
        uint32_t ODO;
        string ENGINETYPE;
    public:
        Car(string color, string enginetype, uint32_t odo);
        uint32_t maintainFee();
        uint32_t getODO();
        void getCarInfo();
};

Car::Car(string color, string enginetype, uint32_t odo){
    Car::COLOR = color;
    Car::ENGINETYPE = enginetype;
    Car::ODO = odo;
}

uint32_t Car::maintainFee(){
    if(Car::ENGINETYPE=="I3"){
        return Car::ODO*10;
    }else if(Car::ENGINETYPE=="I4"){
        return Car::ODO*10*2;
    }else if(Car::ENGINETYPE=="V4"){
        return Car::ODO*10*3;
    }else if(Car::ENGINETYPE=="V6"){
        return Car::ODO*10*4;
    }else{
        return Car::ODO*10*5;
    }
}
uint32_t Car::getODO(){
    return Car::ODO;
}   

void Car::getCarInfo(){
    printf("Color: %s\n", Car::COLOR.c_str());
    printf("Engine Type: %s\n", Car::ENGINETYPE.c_str());
    printf("ODO: %d\n", Car::getODO());
}

int main(int argc, char const *argv[])
{
    Car toyota1("Black", "I3", 150000);
    toyota1.getCarInfo();
    printf("Chi phi bao duong: %d",toyota1.maintainFee());
    return 0;
}

