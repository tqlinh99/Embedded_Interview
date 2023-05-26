#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

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

Animal::Animal(string name, uint8_t age, double weight, double height){
    Animal::NAME = name;
    Animal::AGE = age;
    Animal::WEIGHT = weight;
    Animal::HEIGHT = height;
}

string Animal::getName(){
    return Animal::NAME;
}

uint8_t Animal::getAge(){
    return Animal::AGE;
}

double Animal::getWeight(){
    return Animal::WEIGHT;
}

double Animal::BMI(){
    return WEIGHT/(HEIGHT*HEIGHT);
}

class animalCompare{
    private:
        Animal A;
        Animal B;
    public:
        animalCompare(Animal a, Animal b);
        void ageCompare();
        void weightCompare();
};

animalCompare::animalCompare(Animal a, Animal b){
    animalCompare::A = a;
    animalCompare::B = b;
}

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
