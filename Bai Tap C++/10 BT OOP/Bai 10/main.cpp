/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 24/05/2023
* Description: This file create some classes to contain properties of books and some methods about books
*/

#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
 * Function: Class bookInfo
 * Description: The class contains all properties and methods about books
 * Input:
 *    None
 * Output:
 *    None
*/
class bookInfo{
    private:
        string NAME;
        string AUTHOR;
        uint16_t PUBLICYEAR;
        uint16_t QUANTITY;
    public:
        bookInfo(string name, string author, uint16_t publicYear, uint16_t quantity);
        void getBookInfo();
        void borrowBook(uint16_t amount);
        void returnBook(uint16_t amount);
};

/*
* Function: Constructor bookInfo
* Description: import input parameters for an object belong to class bookInfo
* Input:
*    name: string
*    author: string
*    publicYear: int16_t
*    quantity: int16_t
* Output:
*    None
*/
bookInfo::bookInfo(string name, string author, uint16_t publicYear, uint16_t quantity){
    bookInfo::NAME = name;
    bookInfo::AUTHOR = author;
    bookInfo::PUBLICYEAR = publicYear;
    bookInfo::QUANTITY = quantity;
}

/*
* Function: bookInfo::getBookInfo()
* Description: used to display all information about books (name, author, public year, quantity)
* Input:
*    none
* Output:
*    None
*/
void bookInfo::getBookInfo(){
    printf("Ten sach: %s\n", bookInfo::NAME.c_str());
    printf("Tac gia: %s\n", bookInfo::AUTHOR.c_str());
    printf("Nam xuat ban: %d\n", bookInfo::PUBLICYEAR);
    printf("So luong: %d\n", bookInfo::QUANTITY);
}

/*
* Function: bookInfo::borrowBook()
* Description: used to display number of remain books after loaning
* Input:
*    none
* Output:
*    None
*/
void bookInfo::borrowBook(uint16_t amount){
    if (amount>bookInfo::QUANTITY){
        printf("Rat tiec, so luong sach con lai khong du\n");
        printf("So luong sach '%s' con lai: %d\n", bookInfo::NAME.c_str() ,bookInfo::QUANTITY);
    }else{
        bookInfo::QUANTITY -= amount;
        printf("So luong sach '%s' con lai: %d\n", bookInfo::NAME.c_str() ,bookInfo::QUANTITY);

    }
}

/*
* Function: bookInfo::returnBook()
* Description: used to display number of remain books after receiving return books
* Input:
*    none
* Output:
*    None
*/
void bookInfo::returnBook(uint16_t amount){
    bookInfo::QUANTITY += amount;
    printf("So luong sach '%s' hien co: %d\n", bookInfo::NAME.c_str() ,bookInfo::QUANTITY);
}

int main(int argc, char const *argv[])
{
    bookInfo book1("De Men Phieu Luu Ky", "To Hoai", 1997, 100);
    book1.getBookInfo();
    book1.borrowBook(99);
    book1.borrowBook(2);
    book1.returnBook(50);
    return 0;
}
