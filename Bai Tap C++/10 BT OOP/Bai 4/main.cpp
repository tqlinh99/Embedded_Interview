/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create classes to contain properties of an animal and some methods about animal
*/

#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
 * Function: Class Animal
 * Description: The class contains properties of an animal
 * Input:
 *    None
 * Output:
 *    None
*/
class Animal{
    private:
        string NAME;
        uint8_t AGE;
        double WEIGHT;
        double HEIGHT;
    public:
        Animal(string name=" ", uint8_t age=0, double weight=0, double height=0);
        string getName();
        uint8_t getAge();
        double getWeight();
        double BMI();
};

/*
* Function: Constructor Animal
* Description: import input parameters for an object belong to class Animal
* Input:
*    name: string
*    age: int8_t
*    weight: double
*    height: double
* Output:
*    None
*/
Animal::Animal(string name, uint8_t age, double weight, double height){
    Animal::NAME = name;
    Animal::AGE = age;
    Animal::WEIGHT = weight;
    Animal::HEIGHT = height;
}

/*
 * Function: Animal::getName()
 * Description: used to get name of animal
 * Input:
 *    none
 * Output:
 *    return animal name in type of string
*/
string Animal::getName(){
    return Animal::NAME;
}

/*
 * Function: Animal::getAge()
 * Description: used to get age of animal
 * Input:
 *    none
 * Output:
 *    return animal age in type of uint8_t
*/
uint8_t Animal::getAge(){
    return Animal::AGE;
}

/*
 * Function: Animal::getWeight()
 * Description: used to get weight of animal
 * Input:
 *    none
 * Output:
 *    return animal weight in type of double
*/
double Animal::getWeight(){
    return Animal::WEIGHT;
}

/*
 * Function: Animal::getHeight()
 * Description: used to get height of animal
 * Input:
 *    none
 * Output:
 *    return animal height in type of double
*/
double Animal::BMI(){
    return WEIGHT/(HEIGHT*HEIGHT);
}

/*
 * Function: Class animalCompare
 * Description: The class contains methods to compare weight and age of 2 animals
 * Input:
 *    None
 * Output:
 *    None
*/
class animalCompare{
    private:
        Animal A;
        Animal B;
    public:
        animalCompare(Animal a, Animal b);
        void ageCompare();
        void weightCompare();
};

/*
* Function: Constructor animalCompare
* Description: import 2 animals for object belongs to class animalCompare
* Input:
*    a: Animal
*    b: Animal
* Output:
*    None
*/
animalCompare::animalCompare(Animal a, Animal b){
    animalCompare::A = a;
    animalCompare::B = b;
}

/*
 * Function: animalCompare::ageCompare()
 * Description: compare age between 2 animals
 * Input:
 *    none
 * Output:
 *    none
*/
void animalCompare::ageCompare(){
    if (A.getAge()<B.getAge())
    {
        printf("%s co tuoi it hon %s\n",A.getName().c_str(), B.getName().c_str());
    }else if(A.getAge()>B.getAge()){
        printf("%s co tuoi nhieu hon %s\n",A.getName().c_str(), B.getName().c_str());
    }else{
        printf("%s co tuoi bang %s\n",A.getName().c_str(), B.getName().c_str());
    }
}

/*
 * Function: animalCompare::weightCompare()
 * Description: compare weight between 2 animals
 * Input:
 *    none
 * Output:
 *    none
*/
void animalCompare::weightCompare(){
    if (A.getWeight()<B.getWeight())
    {
        printf("%s nhe hon %s\n",A.getName().c_str(), B.getName().c_str());
    }else if(A.getWeight()>B.getWeight()){
        printf("%s nặng hon %s\n",A.getName().c_str(), B.getName().c_str());
    }else{
        printf("%s co trong luong bang %s\n",A.getName().c_str(), B.getName().c_str());
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}   
