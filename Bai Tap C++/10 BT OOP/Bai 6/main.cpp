#include <stdio.h>
#include <stdint.h>
#include <string>

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

void Fraction::setNumerator(int8_t numerator){
    Fraction::NUMERATOR = numerator;
}

int8_t Fraction::getNumerator(){
    return Fraction::NUMERATOR;
}

void Fraction::setDenominator(int8_t denominator){
    Fraction::DENOMINATOR = denominator;
}

int8_t Fraction::getDenominator(){
    return Fraction::DENOMINATOR;
}

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

fractionMath::fractionMath(Fraction a, Fraction b){
    fractionMath::A = a;
    fractionMath::B = b;
}

void fractionMath::addFraction(){
    C.setDenominator(A.getDenominator()*B.getDenominator());
    C.setNumerator(A.getDenominator()*B.getNumerator() + A.getNumerator()*B.getDenominator());
    shortFraction();
    getResult();
}
    
void fractionMath::subFraction(){
    C.setDenominator(A.getDenominator()*B.getNumerator());
    C.setNumerator(B.getDenominator()*A.getNumerator() - B.getNumerator()*A.getDenominator());
    shortFraction();
    getResult();
}

void fractionMath::mulFraction(){
    C.setNumerator(A.getNumerator()*B.getNumerator());
    C.setDenominator(A.getDenominator()*B.getDenominator());
    shortFraction();
    getResult();
}

void fractionMath::divFraction(){
    C.setNumerator(A.getNumerator()*B.getDenominator());
    C.setDenominator(A.getDenominator()*B.getNumerator());
    shortFraction();
    getResult();
}

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
