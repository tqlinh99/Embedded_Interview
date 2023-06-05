/*
* File Name: Drinks.cpp
* Author: Quang Linh
* Date: 03/06/2023
* Description: code all methods of class Drinks
*/

#include "header.hpp"

Drinks::Drinks(string name, uint16_t price){
    static uint8_t id = 100;
    Drinks::ID = id;
    id++;
    NAME = name;
    PRICE = price;
}

Drinks::Drinks(){}

uint8_t Drinks::getID(){
    return this->ID;
}

void Drinks::setName(string name){
    NAME = name;
}

string Drinks::getName(){
    return this->NAME;
}

void Drinks::setPrice(uint16_t price){
    PRICE = price;
}

uint16_t Drinks::getPrice(){
    return this->PRICE;
}