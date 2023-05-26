#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

class bankAccount{
    private:
        uint64_t STK;
        string NAME;
        uint64_t BALANCE;
    public:
        bankAccount(uint64_t stk, string name, uint64_t balance);
        void cashOut(uint64_t moneyAmount);
        void cashIn(uint64_t moneyAmount);
        void balanceCheck();
};

bankAccount::bankAccount(uint64_t stk, string name, uint64_t balance){
    bankAccount::STK = stk;
    bankAccount::NAME = name;
    bankAccount::BALANCE = balance;
}

void bankAccount::cashOut(uint64_t moneyAmount){
    printf("So du: %d\n",bankAccount::BALANCE);
    if(moneyAmount > bankAccount::BALANCE)
        printf("Giao dich khong thanh cong! So du trong tai khoan khong du\n");
    else{
        bankAccount::BALANCE-=moneyAmount;
        printf("Giao dich thanh cong\n");
        printf("So du con lai trong tai khoan: %d",bankAccount::BALANCE);
    }
}

void bankAccount::cashIn(uint64_t moneyAmount){
    printf("So du: %d\n",bankAccount::BALANCE);
    bankAccount::BALANCE+=moneyAmount;
    printf("Giao dich thanh cong\n");
    printf("So du moi: %d",bankAccount::BALANCE);
}

void bankAccount::balanceCheck(){
    printf("So du hien tai: %d",bankAccount::BALANCE);
}

int main(int argc, char const *argv[])
{
    bankAccount acc1(435425723, "Quang Linh", 5000000);
    acc1.cashOut(5000001);
    return 0;
}
