/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create a class to contain properties of person and some methods about person
*/

#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
 * Function: Class Person
 * Description: The class contains all properties and methods of a point
 * Input:
 *    None
 * Output:
 *    None
*/
class Person{
    private:
        string NAME;
        uint16_t BIRTH;
        string ADDRESS;
    public:
        Person(string name, uint16_t birth, string address);
        void getInfo();
        uint8_t ageCalculator();
};

/*
* Function: Constructor Person
* Description: import input parameters for an object belong to class Person
* Input:
*    nam: string
*    birth: int16_t
*    address: string
* Output:
*    None
*/
Person::Person(string name, uint16_t birth, string address){
    Person::NAME = name;
    Person::BIRTH = birth;
    Person::ADDRESS = address;
}

/*
 * Function: Person::getInfo()
 * Description: used to display all information about person (name, birth, address)
 * Input:
 *    none
 * Output:
 *    none
*/
void Person::getInfo(){
    printf("Ten: %s\n", Person::NAME.c_str());
    printf("Nam sinh: %d\n", Person::BIRTH);
    printf("Dia chi: %s\n", Person::ADDRESS.c_str());
}

/*
 * Function: Person::getInfo()
 * Description: used to calculate the age depend on year of birth
 * Input:
 *    none
 * Output:
 *    none
*/
uint8_t Person::ageCalculator(){
    return 2023-Person::BIRTH;
}

int main(int argc, char const *argv[]){
    Person A("Nguyen Van A", 1999, "tphcm");
    A.getInfo();
    return 0;
}
