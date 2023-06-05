/*
* File Name: header.hpp
* Author: Quang Linh
* Date: 03/06/2023
* Description: This file contains all header of classes used in Drinks Shop
*/

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

/*
 * Class: Drinks
 * Description: The class contains all properties and methods of a Drinks.
 * Input:
 *    None
 * Output:
 *    None
*/
class Drinks{
    private:
        uint8_t ID; //ID of a drink (exp: 101, 102,...)
        string NAME; //Name of a drink (exp: coca, pepsi,...)
        uint16_t PRICE; //Price of a drink (exp: 1000, 2000,...)
    public:

        /*
        * Function: Constructor Drinks 1
        * Class: Drinks
        * Description: import input parameters for an object belong to class Drinks
        * Input:
        *    name: string
        *    price: uint16_t
        * Output:
        *    None
        */
        Drinks(string name, uint16_t price);

        /*
        * Function: Constructor Drinks 2
        * Class: Drinks
        * Description: used when want to declare an object without input parameter
        * Input:
        *    none
        * Output:
        *    None
        */
        Drinks();

        /*
        * Function: getID()
        * Class: Drinks
        * Description: used to get ID of an object belongs to class Drinks
        * Input:
        *    none
        * Output:
        *    return the id of the object 
        */
        uint8_t getID();

        /*
        * Function: setName()
        * Class: Drinks
        * Description: used to set a name for an object belongs to class Drinks
        * Input:
        *    name: string
        * Output:
        *    none
        */
        void setName(string name);

        /*
        * Function: getName()
        * Class: Drinks
        * Description: used to get the name of an object belongs to class Drinks
        * Input:
        *    none
        * Output:
        *    return the name of the object 
        */
        string getName();

        /*
        * Function: setPrice()
        * Class: Drinks
        * Description: used to set a price for an object belongs to class Drinks
        * Input:
        *    price: uint16_t
        * Output:
        *    none
        */
        void setPrice(uint16_t price);

        /*
        * Function: getPrice()
        * Class: Drinks
        * Description: used to get the price of an object belongs to class Drinks
        * Input:
        *    none
        * Output:
        *    return the price of the object 
        */
        uint16_t getPrice();
};


/*
 * Class: DrinksManagement
 * Description: This class is made for managing (adding, editting, deleting,...) objects which belong to class Drinks
 * Input:
 *    None
 * Output:
 *    None
*/
class DrinksManagement{
    private:
        vector<Drinks> DrinksDatabase; //A vector store elements which belongs to class Drinks
        int NumberOfTables; // The amount of tables in Drink Shop

        /*
        * Function: setNumberOfTables()
        * Class: DrinksManagement
        * Description: used to set the amount of tables in Drink Shop
        * Input:
        *    none
        * Output:
        *    None
        */
        void setNumberOfTables();

        /*
        * Function: drinksAdding()
        * Class: DrinksManagement
        * Description: used to push back a new object (class Drinks) to the vector DrinksDatabase
        * Input:
        *    none
        * Output:
        *    None
        */ 
        void drinksAdding();

        /*
        * Function: drinksEditting()
        * Class: DrinksManagement
        * Description: used to editting an element (class Drinks) by ID in the vector DrinksDatabase
        * Input:
        *    none
        * Output:
        *    None
        */ 
        void drinksEditting();

        /*
        * Function: drinksDeleting()
        * Class: DrinksManagement
        * Description: used to delete an element (class Drinks) by ID in the vector DrinksDatabase
        * Input:
        *    none
        * Output:
        *    None
        */ 
        void drinksDeleting();

        /*
        * Function: drinksListing()
        * Class: DrinksManagement
        * Description: used to display all elements (class Drinks) in the vector DrinksDatabase in shape of a table
        * Input:
        *    none
        * Output:
        *    None
        */ 
        void drinkListing();
    public:

        /*
        * Function: DrinksManagementMenu()
        * Class: DrinksManagement
        * Description: display a menu with choices to run function (exp: drinkAdding(), drinkEditting(),...)
        * Input:
        *    none
        * Output:
        *    None
        */
        void DrinksManagementMenu();

        /*
        * Function: getNumberOfTables()
        * Class: DrinksManagement
        * Description: used to get the amount of tables of the Drink Shop
        * Input:
        *    none
        * Output:
        *    return the number of tables
        */
        int getNumberOfTables();

        /*
        * Function: getDrinksDatabase()
        * Class: DrinksManagement
        * Description: used to get the vector DrinksDatabase
        * Input:
        *    none
        * Output:
        *    return a vector which copied from DrinksDatabase
        */
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


/*
 * Class: OrderManagement
 * Description: This class is made for managing orders of each table 
 * Input:
 *    None
 * Output:
 *    None
*/
class OrderManagement{
    private:
        vector<Drinks> DrinksDatabase; //A vector store elements which belongs to class Drinks
        vector<Table> OrderDatabase; //A vector store elements belongs to struct Table
        int NumberOfTables; // The amount of tables in Drink Shop

        /*
        * Function: OrderMenu()
        * Class: OrderManagement
        * Description: display a menu with choices to run function (exp: Order(), OrderEditting(), OrderListing(),...)
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        void OrderMenu(int tableIndex);

        /*
        * Function: Order()
        * Class: OrderManagement
        * Description: add data to an element in vector OrderDatabase
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        void Order(int tableIndex);

        /*
        * Function: OrderEditting()
        * Class: OrderManagement
        * Description: edit data of the element in vector OrderDatabase
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        void OrderEditting(int tableIndex);

        /*
        * Function: OrderEditting()
        * Class: OrderManagement
        * Description: delete data of the element in vector OrderDatabase
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        void OrderDeleting(int tableIndex);

        /*
        * Function: OrderLisitng()
        * Class: OrderManagement
        * Description: display all elements of vector TableOrderDatabase which is an element in vector OrderDatabase
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        void OrderListing(int tableIndex);

        /*
        * Function: OrderPaying()
        * Class: OrderManagement
        * Description: give choice to user to delete all elements of vector TableOrderDatabase which is an element in vector OrderDatabase
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        void OrderPay(int tableIndex);
    public:

        /*
        * Function: Constructor OrderManagement()
        * Class: OrderManagement
        * Description: declare number of elements for vector OrderDatabase corresponding to number of tables
        * Input:
        *    tableIndex: int   //The index of a table
        * Output:
        *    none
        */
        OrderManagement(int numberOfTables);    

/*
        * Function: SelectTable()
        * Class: OrderManagement
        * Description: create a list of available tables and give choices to user to choose specific table to order
        * Input:
        *    tableIndex: int   //The index of a table
        *    drinksDatabase : vector<Drinks>     //Database of available drinks
        * Output:
        *    none
        */
        void SelectTable(vector<Drinks> drinksDatabase, int numberOfTables);
};

/*
 * Class: Menu
 * Description: A main menu for user to choose between 2 mode (drinks management and order management)
 * Input:
 *    None
 * Output:
 *    None
*/
class Menu{
     public:

        /*
        * Function: Constructor Menu()
        * Class: Menu
        * Description: create a menu with 2 choices (drinks management and order management) 
        * Input:
        *    none
        * Output:
        *    none
        */
        Menu();    
};