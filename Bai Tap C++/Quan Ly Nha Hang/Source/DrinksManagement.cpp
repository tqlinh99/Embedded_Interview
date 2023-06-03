#include "header.hpp"

DrinksManagement::DrinksManagement(){
} 

void DrinksManagement::DrinksManagementMenu(){
    int phim = 6;
    
    while (phim != 0){
        switch(phim)
        {
        case 0: 
            break;

        case 1:
            setNumberOfTables();
            phim = 6;
            break;

        case 2:
            drinksAdding();
            phim = 6;
            break;

        case 3:
            drinksEditting();
            phim = 6;
            break;

        case 4:
            drinksDeleting();
            phim = 6;
            break;
            
        case 5:
            drinkListing();
            phim = 6;
            break;

        case 6:
            cout << "\n(1) MENU QUAN LY\n";
            cout << "1. Nhap so luong ban\n";
            cout << "2. Them do uong\n";
            cout << "3. Sua do uong\n";
            cout << "4. Xoa do uong\n";
            cout << "5. Danh sach do uong\n";
            cout << "0. Quay lai\n";
            cout << "\nVui long nhap phim: ";
            scanf("%d", &phim);
            break; 
        
        default:
            phim = 6;
            break;   
        }
    }
}

void DrinksManagement::setNumberOfTables(){
    cout << "\nNhap so luong ban\n";
    int numberOfTables;

    INPUT_TYPE("    So luong ban: ", numberOfTables);
    NumberOfTables = numberOfTables;
    cout << "\nThem so luong ban thanh cong!\n";

}

void DrinksManagement::drinksAdding(){
    string name;
    uint16_t price;

    cout << "\nNhap thong tin do uong\n";
    INPUT_TYPE("    Ten do uong: ", name);
    INPUT_TYPE("    Gia: ", price);

    Drinks drink(name, price);
    DrinksDatabase.push_back(drink);
    cout << "\nThem do uong thanh cong!\n";
}

void DrinksManagement::drinksEditting(){
    int id;
    uint8_t index = 0;
    string name;
    uint16_t price;

    INPUT_TYPE("\nNhap ID do uong can cap nhat: ", id);

    for(Drinks drink : DrinksDatabase){
        if(drink.getID() == id){
            INPUT_TYPE("    Ten do uong: ", name);
            INPUT_TYPE("    Gia: ", price);
            drink.setName(name);
            drink.setPrice(price);
            DrinksDatabase[index] = drink;
            cout << "\nCap nhat do uong thanh cong!\n";
            return;
        }
        index++;
    }
    cout << "\n    ID not found!\n";
}


void DrinksManagement::drinksDeleting(){
    int id;
    uint8_t index = 0;

    INPUT_TYPE("\nNhap ID cua do uong can xoa: ", id);

    for(Drinks drink : DrinksDatabase){
        if(drink.getID() == id){
            DrinksDatabase.erase(DrinksDatabase.begin()+index);
            printf("\nXoa do uong co ID %d thanh cong!\n", id);
            return;
        }
        index++;
    }
    cout << "\n    ID not found!\n";
}

void DrinksManagement::drinkListing(){
    uint8_t STT = 1;

    PRINT_TITLE();
    for(auto drink : DrinksDatabase){
        printf("| %-4d|  %-5d| %-12s|    %-7d|\n", STT, drink.getID(), drink.getName().c_str(), drink.getPrice());
        cout << "+-----+-------+-------------+-----------+\n";
        STT++;
    }
}

int DrinksManagement::getNumberOfTables(){
    return this->NumberOfTables;
}

vector<Drinks> DrinksManagement::getDrinksDatabase(){
    return this->DrinksDatabase;
}