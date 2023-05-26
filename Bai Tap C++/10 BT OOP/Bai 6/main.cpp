/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create classes to contain properties of fractions and some methods to do math with fraction
*/

#include <stdio.h>
#include <stdint.h>
#include <string>

/*
 * Function: Class Fraction
 * Description: The class contains properties of a fraction
 * Input:
 *    None
 * Output:
 *    None
*/
class Fraction{
    private:
        int8_t NUMERATOR;
        int8_t DENOMINATOR;
    public:
        Fraction(int8_t numerator=0, int8_t denominator=1);
        void setNumerator(int8_t numerator);
        int8_t getNumerator();
        void setDenominator(int8_t denominator);
        int8_t getDenominator();
};

/*
* Function: Constructor Fraction
* Description: import numerator and denominator of a fraction
* Input:
*    numerator: int8_t
*    denominator: int8_t
* Output:
*    None
*/
Fraction::Fraction(int8_t numerator, int8_t denominator){
    while(denominator == 0){
        printf("Error! Phan so %d/%d khong ton tai! Moi nhap lai\n", numerator, denominator);
        printf("Tu so: ");
        scanf("%d",&numerator);
        printf("Mau so: ");
        scanf("%d",&denominator);
    }
    
    Fraction::NUMERATOR = numerator;
    Fraction::DENOMINATOR = denominator;
}

/*
 * Function: Fraction::setNumerator
 * Description: set numerator for fraction
 * Input:
 *    numerator: int8_t
 * Output:
 *    none
*/
void Fraction::setNumerator(int8_t numerator){
    Fraction::NUMERATOR = numerator;
}

/*
 * Function: Fraction::getNumerator()
 * Description: used to get numerator of a fraction
 * Input:
 *    none
 * Output:
 *    return numerator in type of int8_t
*/
int8_t Fraction::getNumerator(){
    return Fraction::NUMERATOR;
}

/*
 * Function: Fraction::setDenominator
 * Description: set denominator for fraction
 * Input:
 *    denominator: int8_t
 * Output:
 *    none
*/
void Fraction::setDenominator(int8_t denominator){
    Fraction::DENOMINATOR = denominator;
}

/*
 * Function: Fraction::getDenominator()
 * Description: used to get denominator of a fraction
 * Input:
 *    none
 * Output:
 *    return denominator in type of int8_t
*/
int8_t Fraction::getDenominator(){
    return Fraction::DENOMINATOR;
}

/*
 * Function: Class fractionMath
 * Description: The class contains properties and methods to do fraction math with 2 fractions
 *    None
 * Output:
 *    None
*/
class fractionMath{
    private:
        Fraction A;
        Fraction B;
        Fraction C;
    public:
        fractionMath(Fraction a, Fraction b);
        void addFraction();
        void subFraction();
        void mulFraction();
        void divFraction();
        void shortFraction();
        void getResult();
};

/*
* Function: Constructor fractionMath
* Description: import 2 fraction to object belongs to class fractionMath
* Input:
*    a: Fraction
*    b: Fraction
* Output:
*    None
*/
fractionMath::fractionMath(Fraction a, Fraction b){
    fractionMath::A = a;
    fractionMath::B = b;
}

/*
 * Function: fractionMath::addFraction()
 * Description: addition of 2 fraction
 * Input:
 *    none
 * Output:
 *    none
*/
void fractionMath::addFraction(){
    C.setDenominator(A.getDenominator()*B.getDenominator());
    C.setNumerator(A.getDenominator()*B.getNumerator() + A.getNumerator()*B.getDenominator());
    shortFraction();
    getResult();
}
    
/*
 * Function: fractionMath::subFraction()
 * Description: subtraction of 2 fraction
 * Input:
 *    none
 * Output:
 *    none
*/
void fractionMath::subFraction(){
    C.setDenominator(A.getDenominator()*B.getNumerator());
    C.setNumerator(B.getDenominator()*A.getNumerator() - B.getNumerator()*A.getDenominator());
    shortFraction();
    getResult();
}

/*
 * Function: fractionMath::mulFraction()
 * Description: multiplication of 2 fraction
 * Input:
 *    none
 * Output:
 *    none
*/
void fractionMath::mulFraction(){
    C.setNumerator(A.getNumerator()*B.getNumerator());
    C.setDenominator(A.getDenominator()*B.getDenominator());
    shortFraction();
    getResult();
}

/*
 * Function: fractionMath::divFraction()
 * Description: division of 2 fraction
 * Input:
 *    none
 * Output:
 *    none
*/
void fractionMath::divFraction(){
    C.setNumerator(A.getNumerator()*B.getDenominator());
    C.setDenominator(A.getDenominator()*B.getNumerator());
    shortFraction();
    getResult();
}

/*
 * Function: fractionMath::shortFraction()
 * Description: short result fraction
 * Input:
 *    none
 * Output:
 *    none
*/
void fractionMath::shortFraction(){
    for (uint8_t i = 9; i > 1; i--)
    {
        if((C.getNumerator()%i == 0) & (C.getDenominator()%i ==0)){
            printf("Yes and i = %d\n",i);
            C.setNumerator(C.getNumerator()/i);
            C.setDenominator(C.getDenominator()/i);
            i=9;
        }
    }
}

/*
 * Function: fractionMath::getResult()
 * Description: display result fraction
 * Input:
 *    none
 * Output:
 *    none
*/
void fractionMath::getResult(){
    printf("Ket qua:\n");
    printf("%d\n-\n%d\n", C.getNumerator(), C.getDenominator());
}

int main(int argc, char const *argv[])
{
    Fraction A(5,0);
    Fraction B(1,2);
    fractionMath exp(A,B);
    exp.mulFraction();
    return 0;
}
