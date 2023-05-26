#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

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

Person::Person(string name, uint16_t birth, string address){
    Person::NAME = name;
    Person::BIRTH = birth;
    Person::ADDRESS = address;
}



void Person::getInfo(){
    printf("Ten: %s\n", Person::NAME.c_str());
    printf("Nam sinh: %d\n", Person::BIRTH);
    printf("Dia chi: %s\n", Person::ADDRESS.c_str());
}


uint8_t Person::ageCalculator(){
    return 2023-Person::BIRTH;
}

int main(int argc, char const *argv[])
{
    Person A("Nguyen Van A", 1999, "tphcm");
    A.getInfo();
    return 0;
}
