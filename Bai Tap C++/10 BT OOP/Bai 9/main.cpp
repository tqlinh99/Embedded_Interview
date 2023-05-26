/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create a class to contain properties of a car and some methods about car
*/

#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
 * Function: Class Car
 * Description: The class contains all properties and methods of a car
 * Input:
 *    None
 * Output:
 *    None
*/
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

/*
* Function: Constructor Car
* Description: import input parameters for an object belong to class Car
* Input:
*    color: string
*    enginetype: string
*    odo: uint32_t
* Output:
*    None
*/
Car::Car(string color, string enginetype, uint32_t odo){
    Car::COLOR = color;
    Car::ENGINETYPE = enginetype;
    Car::ODO = odo;
}

/*
 * Function: Car::maintainFee()
 * Description: used to calculate maintenance fee of a car depend on engine type and odo
 * Input:
 *    none
 * Output:
 *    return maintenance fee of a car intype of uint32_t
*/
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

/*
 * Function: Car::getODO()
 * Description: used to get odo of a car
 * Input:
 *    none
 * Output:
 *    return odo in type of int32_t
*/
uint32_t Car::getODO(){
    return Car::ODO;
}   

/*
 * Function: Car::getODO()
 * Description: used to display all information about car (color, engine type, odo)
 *    none
 * Output:
 *    none
*/
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

