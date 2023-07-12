#include "Header.hpp"

Room::Room(uint8_t number){
    roomNumber = number;
    isBooked = false;
    isCleaned = true;
}

uint8_t Room::getRoomNumber(){
    return roomNumber;
}

bool Room::isAvailable(){
    return !isBooked && isCleaned; 
}

void Room::bookRoom(){
    isBooked = true;
}

void Room::checkIn(){
    isBooked = true;
    isCleaned = true;
}

void Room::checkOut(){
    isBooked = false;
    isCleaned = false;
}