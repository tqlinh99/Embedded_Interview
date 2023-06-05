/*
* File Name: Menu.cpp
* Author: Quang Linh
* Date: 03/06/2023
* Description: code constructor for class Menu
*/

#include "header.hpp"

Menu::Menu(){
    int phim = 3;

    while(phim!=0){
        switch (phim)
        {
        case 0:
            break;
        
        case 1:
            static DrinksManagement quanly;
            quanly.DrinksManagementMenu();
            phim=3;
            break;

        case 2:
            static OrderManagement nhanvien(quanly.getNumberOfTables());
            if (quanly.getNumberOfTables() == 0){
                cout << "   Chua thiet lap so ban!!! Vui long thiet lap va thu lai\n";
                phim = 3;
                break;
            }
            if (quanly.getDrinksDatabase().size() == 0){
                cout << "   Chua co du lieu do uong!!! Vui long thiet lap va thu lai\n";
                phim = 3;
                break;
            }
            nhanvien.SelectTable(quanly.getDrinksDatabase(),quanly.getNumberOfTables());
            phim =3;
            break;

        case 3:
            cout << "\n(0) MENU QUAN LY NHA HANG\n";
            cout << "1. Quan ly\n";
            cout << "2. Nhan vien\n";
            cout << "0. Thoat chuong trinh\n";
            cout << "\nVui long nhap phim: ";
            scanf("%d", &phim);
            break;
            
        default:
            phim = 3;
            break;
        }
    }
}