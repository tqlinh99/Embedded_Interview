/*
* File Name: OrderManagement.cpp
* Author: Quang Linh
* Date: 03/06/2023
* Description: code all methods of class OrdersManagement
*/

#include "header.hpp"

OrderManagement::OrderManagement(int numberOfTables){
    for (int i=1; i <= numberOfTables; i++)
        {
            Table table;
            table.TABLE = i;
            table.STATUS = false;
            OrderDatabase.push_back(table);
    }
    NumberOfTables = numberOfTables;
}

void OrderManagement::SelectTable(vector<Drinks> drinksDatabase, int numberOfTables){
    int TableIndex = 0;

    DrinksDatabase.clear();
    for (Drinks drink : drinksDatabase){
        DrinksDatabase.push_back(drink);
    }

    if(numberOfTables > NumberOfTables){
        for (int i = NumberOfTables+1; i <= numberOfTables; i++)
        {
            Table table;
            table.TABLE = i;
            table.STATUS = false;
            OrderDatabase.push_back(table);
        }
    }else if(numberOfTables < NumberOfTables){
        for (int i = NumberOfTables - numberOfTables; i > 0; i--)
        {
            OrderDatabase.pop_back();
        }   
    }
    NumberOfTables = numberOfTables;

    cout << "\n(1) MENU NHAN VIEN\n";
    cout << "\nBan       ";

    for (auto ban : OrderDatabase){
        printf("| %d ", ban.TABLE);
    }

    cout <<"\n----------";
    for (auto ban : OrderDatabase){
        printf("+---");
    }

    cout<< "\nTrang thai";
    for (auto ban : OrderDatabase){
        if(ban.STATUS == true){
            cout << "| x ";
        }else{
            cout << "| o ";
        }
    }
    
    INPUT_TYPE("\n\nChon ban: ", TableIndex);
    OrderMenu(TableIndex);
}

void OrderManagement::OrderMenu(int tableIndex){
    int phim = 5;

    while (phim != 0){
        switch (phim)
        {
        case 0:
            break;
        
        case 1:
            Order(tableIndex);
            phim = 5;
            break;

        case 2:
            OrderListing(tableIndex);
            OrderEditting(tableIndex);
            phim = 5;
            break;

        case 3:
            OrderListing(tableIndex);
            OrderDeleting(tableIndex);
            phim = 5;
            break;
        
        case 4:
            OrderListing(tableIndex);
            OrderPay(tableIndex);
            phim = 5;
            break;

        default:
            printf("\n(2) MENU DAT MON (BAN %d)\n", tableIndex);
            cout << "1. Dat mon\n";
            cout << "2. Sua mon\n";
            cout << "3. Xoa mon\n";
            cout << "4. Danh sach mon va thanh toan\n";
            cout << "0. Quay lai\n";
            cout << "\nVui long nhap phim: ";
            scanf("%d", &phim);
            break;   
        }
    }
}

void OrderManagement::Order(int tableIndex){
    uint8_t STT = 1;
    int id;
    int index = 0;
    uint8_t idFound = 0;
    uint8_t existFlag = 0;
    int DrinkQuantity;
    DrinksOrder DRINK;


    PRINT_TITLE();
    for (auto drink : DrinksDatabase){
        printf("| %-4d|  %-5d| %-12s|    %-7d|\n", STT, drink.getID(), drink.getName().c_str(), drink.getPrice());
        cout << "+-----+-------+-------------+-----------+\n";
        STT++;
    }

    INPUT_TYPE( "\nNhap ID mon muon chon: ", id);
    for(auto drink : DrinksDatabase){
        if (drink.getID() == id){
            idFound = 1;
            DRINK.NAME = drink;
            break;
        }
    }
    if (idFound == 0){
        cout << "   ID not found\n";
        return;
    }
    

    INPUT_TYPE( "\nSo luong: ", DrinkQuantity);
    if (DrinkQuantity != 0){
        for (auto drink : OrderDatabase[tableIndex-1].TableOrderDatabase){
            if (DRINK.NAME.getName() == drink.NAME.getName()){
                existFlag = 1;
                OrderDatabase[tableIndex-1].TableOrderDatabase[index].QUANTITY +=DrinkQuantity;
            }
            index++;
        }
    if (existFlag == 0){
        DRINK.QUANTITY = DrinkQuantity;
        OrderDatabase[tableIndex-1].TableOrderDatabase.push_back(DRINK);
    }
    }
    if (OrderDatabase[tableIndex-1].TableOrderDatabase.size() != 0){
        OrderDatabase[tableIndex-1].STATUS = true;
    }else{
        OrderDatabase[tableIndex-1].STATUS = false;
    }
    
}

void OrderManagement::OrderEditting(int tableIndex){
    int id;
    uint8_t index = 0;
    
    INPUT_TYPE( "\nNhap ID mon muon sua: ", id);
    for(auto drink : OrderDatabase[tableIndex-1].TableOrderDatabase){
        if (drink.NAME.getID() == id){
            OrderDatabase[tableIndex-1].TableOrderDatabase.erase(OrderDatabase[tableIndex-1].TableOrderDatabase.begin()+index);
            Order(tableIndex);
            return;
        }
        index++;
    }
    cout << "   ID not found\n";

}

void OrderManagement::OrderDeleting(int tableIndex){
    int id;
    uint8_t index = 0;
    
    
    INPUT_TYPE( "\nNhap ID mon muon xoa: ", id);
    for(auto drink : OrderDatabase[tableIndex-1].TableOrderDatabase){
        if (drink.NAME.getID() == id){
            OrderDatabase[tableIndex-1].TableOrderDatabase.erase(OrderDatabase[tableIndex-1].TableOrderDatabase.begin()+index);
            if (OrderDatabase[tableIndex-1].TableOrderDatabase.size() != 0){
                OrderDatabase[tableIndex-1].STATUS = true;
            }else{
                OrderDatabase[tableIndex-1].STATUS = false;
            } 
            return;
        }
        index++;
    }
    cout << "   ID not found\n";
    
}

void OrderManagement::OrderListing(int tableIndex){
    int STT=1;
    uint32_t SUM=0;

    cout << "+-----+-------+-------------+-------------+----------+--------------+\n"; 
    cout << "| STT |  ID   | TEN DO UONG |   DON GIA   | SO LUONG |  THANH TIEN  |\n"; 
    cout << "+-----+-------+-------------+-------------+----------+--------------+\n"; 

    for(auto drink : OrderDatabase[tableIndex-1].TableOrderDatabase){
        SUM += drink.QUANTITY*drink.NAME.getPrice();
        printf("| %-4d|  %-5d| %-12s|    %-9d|    %-6d|    %-10d|\n", STT, drink.NAME.getID(), drink.NAME.getName().c_str(), drink.NAME.getPrice(),drink.QUANTITY,drink.QUANTITY*drink.NAME.getPrice());
        cout << "+-----+-------+-------------+-------------+----------+--------------+\n"; 
        STT++;
    }
    printf("|         TONG CONG         |               %-24d|\n", SUM); 
    cout << "+-----+-------+-------------+-------------+----------+--------------+\n"; 
}

void OrderManagement::OrderPay(int tableIndex){
    char paid;
    
    INPUT_TYPE( "\nDa thanh toan?(y/n): ", paid);
    if(paid == 121){
        OrderDatabase[tableIndex-1].TableOrderDatabase.clear();
        OrderDatabase[tableIndex-1].STATUS = false;
    }
    cout << "\nThanh toan thanh cong!\n";

}