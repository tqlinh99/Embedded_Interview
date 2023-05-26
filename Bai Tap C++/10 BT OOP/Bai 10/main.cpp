#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

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

bookInfo::bookInfo(string name, string author, uint16_t publicYear, uint16_t quantity){
    bookInfo::NAME = name;
    bookInfo::AUTHOR = author;
    bookInfo::PUBLICYEAR = publicYear;
    bookInfo::QUANTITY = quantity;
}

void bookInfo::getBookInfo(){
    printf("Ten sach: %s\n", bookInfo::NAME.c_str());
    printf("Tac gia: %s\n", bookInfo::AUTHOR.c_str());
    printf("Nam xuat ban: %d\n", bookInfo::PUBLICYEAR);
    printf("So luong: %d\n", bookInfo::QUANTITY);
}

void bookInfo::borrowBook(uint16_t amount){
    if (amount>bookInfo::QUANTITY){
        printf("Rat tiec, so luong sach con lai khong du\n");
        printf("So luong sach '%s' con lai: %d\n", bookInfo::NAME.c_str() ,bookInfo::QUANTITY);
    }else{
        bookInfo::QUANTITY -= amount;
        printf("So luong sach '%s' con lai: %d\n", bookInfo::NAME.c_str() ,bookInfo::QUANTITY);

    }
}

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
