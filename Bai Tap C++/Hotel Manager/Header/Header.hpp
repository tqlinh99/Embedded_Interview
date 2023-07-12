#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INPUT_TYPE(text, var)       \
cout << text;                       \
cin  >> var;                        \

class Room{
    private:
        uint8_t roomNumber;
        bool isBooked;
        bool isCleaned;
    public:
        Room(uint8_t number);
        uint8_t getRoomNumber();
        bool isAvailable();
        void bookRoom();
        void checkIn();
        void checkOut();
};

class HotelManager{
    private:
        vector<Room> RoomDatabase;
        void displayAvailableRooms();
        void bookRoom(uint8_t roomNumber);
        void checkIn(uint8_t roomNumber);
        void checkOut(uint8_t roomNumber);
    public:

};

typedef struct{
    uint8_t day;
    uint8_t month;
    uint8_t year;
}typeDate;

typedef struct{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}typeTime;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef struct{
    typeDate date;
    typeTime time;
    typeStatus status;
}bookingHistory;

class Customer{
    private:
        uint8_t roomID;
        string name;
        string phoneNumber;
        string address;
        vector<bookingHistory> bookingHistorys;
    public:
        Customer(string customerName, string customerPhone, string customerAddress);
        string getName();
        void setName(string customerName);
        string getCustomerPhone();
        void setCustomerPhone(string customerPhone);
        string getCustomerAddress();
        void setCustomerAddress(string customerAddress);
        void addBookingHistory(bookingHistory bookingDetails);
        void displayBookingHistory();
};

class CustomerManger{
    private:
        vector<Customer> databaseCustomer;
    public:
        void menu();
        void addCustomer();
        void editCustomer();
        void deleteCustomer();
        void displayCustomer();
};