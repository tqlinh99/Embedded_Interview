#ifndef __DO_UONG_H
#define __Do_UONG_H

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INPUT_TYPE(text, var)       \
cout << text;                       \
cin  >> var;                        \

#define PRINT_TITLE()   \
cout << "+-----+-------+-------------+-----------+\n"; \
cout << "| STT |  ID   | TEN DO UONG |    GIA    |\n"; \
cout << "+-----+-------+-------------+-----------+\n"; 

class Drinks{
    private:
        uint8_t ID;
        string NAME;
        uint16_t PRICE;
    public:
        Drinks(string name, uint16_t price);
        Drinks();
        uint8_t getID();
        void setName(string name);
        string getName();
        void setPrice(uint16_t price);
        uint16_t getPrice();
};

class DrinksManagement{
    private:
        vector<Drinks> DrinksDatabase;
        int NumberOfTables;
        void setNumberOfTables();
        void drinksAdding();
        void drinksEditting();
        void drinksDeleting();
        void drinkListing();
    public:
        DrinksManagement();
        void DrinksManagementMenu();
        int getNumberOfTables();
        vector<Drinks> getDrinksDatabase();
        
};

typedef struct
{
    Drinks NAME;
    uint8_t QUANTITY;
}DrinksOrder;

typedef struct
{
    uint8_t TABLE;
    bool STATUS;
    vector<DrinksOrder> TableOrderDatabase;
}Table;


class OrderManagement{
    private:
        vector<Drinks> DrinksDatabase;
        vector<Table> OrderDatabase;
        int NumberOfTables;
        void OrderMenu(int tableIndex);
        void Order(int tableIndex);
        void OrderEditting(int tableIndex);
        void OrderDeleting(int tableIndex);
        void OrderListing(int tableIndex);
        void OrderPay(int tableIndex);
    public:
        void SelectTable(vector<Drinks> drinksDatabase, int numberOfTables);
        OrderManagement(int numberOfTables);    
};

class Menu{
     public:
        Menu();    
};

#endif