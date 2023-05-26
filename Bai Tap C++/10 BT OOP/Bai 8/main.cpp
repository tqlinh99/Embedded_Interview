/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create a class to contain properties of a bank account and some function about bank account
*/

#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
 * Function: Class bankAccount
 * Description: The class contains all properties and methods of a bank account
 * Input:
 *    None
 * Output:
 *    None
*/
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

/*
* Function: Constructor bankAccount
* Description: import input parameters for an object belong to class bankAccount
* Input:
*    stk: uint64_t
*    name: string
*    balance: uint64_t
* Output:
*    None
*/
bankAccount::bankAccount(uint64_t stk, string name, uint64_t balance){
    bankAccount::STK = stk;
    bankAccount::NAME = name;
    bankAccount::BALANCE = balance;
}

/*
 * Function: bankAccount::cashOut()
 * Description: calculate and display remain balance after cashout
 * Input:
 *    moneyAmount: uint64_t
 * Output:
 *    none
*/
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

/*
 * Function: bankAccount::cashIn()
 * Description: calculate and display remain balance after cashin
 * Input:
 *    moneyAmount: uint64_t
 * Output:
 *    none
*/
void bankAccount::cashIn(uint64_t moneyAmount){
    printf("So du: %d\n",bankAccount::BALANCE);
    bankAccount::BALANCE+=moneyAmount;
    printf("Giao dich thanh cong\n");
    printf("So du moi: %d",bankAccount::BALANCE);
}

/*
 * Function: bankAccount::balanceCheck()
 * Description: display remain balance
 * Input:
 *    none
 * Output:
 *    none
*/
void bankAccount::balanceCheck(){
    printf("So du hien tai: %d",bankAccount::BALANCE);
}

int main(int argc, char const *argv[])
{
    bankAccount acc1(435425723, "Quang Linh", 5000000);
    acc1.cashOut(5000001);
    return 0;
}
