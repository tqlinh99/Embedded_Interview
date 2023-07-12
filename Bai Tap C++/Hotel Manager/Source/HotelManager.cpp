#include "Header.hpp"

void HotelManager::displayAvailableRooms(){
    int STT = 1;

    cout << "\nDANH SACH PHONG\n";
    cout << "+-----+------------+---------------+\n"; \
    cout << "| STT |  SO PHONG  |   TRANG THAI   |\n"; \
    cout << "+-----+------------+---------------+\n"; 

    for (auto room : RoomDatabase){
        printf("|  %-3d|    %-8d", STT, room.getRoomNumber());
        if (room.isAvailable() == true){
            printf("|  Available  |\n");
        }else{
            printf("| Unavailable |\n");
        }
        STT++;
    }
}

void HotelManager::bookRoom(uint8_t roomNumber){
    Room room(roomNumber);
    RoomDatabase.push_back(room);
}

void HotelManager::checkIn(uint8_t roomNumber){
    int index = 0;

    for(auto room : RoomDatabase){
        if(room.getRoomNumber() == roomNumber){
            room.checkIn();
            RoomDatabase[index] = room;
        }
        index++;
    }
}

void HotelManager::checkOut(uint8_t roomNumber){
    int index = 0;

    for(auto room : RoomDatabase){
        if(room.getRoomNumber() == roomNumber){
            room.checkOut();
            RoomDatabase[index] = room;
        }
        index++;
    }
}