/*
* File Name: main.cpp
* Author: Quang Linh
* Date: 25/05/2023
* Description: This program is made for managing student information by a function menu
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
cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n"; \
cout << "| STT |  ID   |      TEN      | GIOI TINH | TUOI | DIEM TOAN | DIEM LY | DIEM HOA | DTB  |    HOC LUC      |\n"; \
cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n"; \

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeRankAcademic;

/*
 * Function: Class SinhVien
 * Description: The class contains all properties and methods of a student.
 * Input:
 *    None
 * Output:
 *    None
*/
class SinhVien{
    private:
        int ID;
        string NAME;
        string GENDER;
        uint8_t AGE;
        float DIEM_TOAN;
        float DIEM_LY;
        float DIEM_HOA;
        float DIEM_TRUNG_BINH;
        TypeRankAcademic HOC_LUC;
    public:
        SinhVien(string name, string gender, uint8_t age, float diemToan, float diemLy, float diemHoa);
        SinhVien();
        int getID();
        void setName(string name);
        string getName();
        void setGender(string gender);
        string getGender();
        void setAge(uint8_t age);
        uint8_t getAge();
        void setDiemToan(float toan);
        float getDiemToan();
        void setDiemLy(float ly);
        float getDiemLy();
        void setDiemHoa(float hoa);
        float getDiemHoa();
        float getDiemTrungBinh();
        TypeRankAcademic getHocLuc();
};

/*
* Function: Constructor SinhVien
* Description: import input parameters for an object belong to class SinhVien
* Input:
*    name: string
*    gender: TypeGender
*    age: uint8_t
*    diemToan: float
*    diemLy: float
*    diemHoa: float
* Output:
*    None
*/
SinhVien::SinhVien(string name, string gender, uint8_t age, float diemToan, float diemLy, float diemHoa){
    static uint8_t id = 100;
    SinhVien::ID = id;
    id++;
    NAME = name;
    GENDER = gender;
    AGE = age;
    DIEM_TOAN = diemToan;
    DIEM_LY = diemLy;
    DIEM_HOA = diemHoa;
}

SinhVien::SinhVien(){   
}

/*
 * Function: SinhVien::getID()
 * Description: used to get ID
 * Input:
 *    none
 * Output:
 *    return SinhVien::ID in type of uint8_t
*/
int SinhVien::getID(){
    return this->ID;
}

/*
 * Function: SinhVien::setName()
 * Description: set name for object
 * Input:
 *    name: string
 * Output:
 *    none
*/
void SinhVien::setName(string name){
    NAME = name;
}

/*
 * Function: SinhVien::getName()
 * Description: used to get name
 * Input:
 *    none
 * Output:
 *    return SinhVien::NAME in type of string
*/
string SinhVien::getName(){
    return this->NAME;
}

/*
 * Function: SinhVien::setGender()
 * Description: set gender for object
 * Input:
 *    gender: TypeGender
 * Output:
 *    none
*/
void SinhVien::setGender(string gender){
    GENDER = gender;
}

/*
 * Function: SinhVien::getGender()
 * Description: used to get gender
 * Input:
 *    none
 * Output:
 *    return SinhVien::GENDER in type of TypeGender
*/
string SinhVien::getGender(){
    return this->GENDER;
}

/*
 * Function: SinhVien::setAge()
 * Description: set gender for object
 * Input:
 *    age: uint8_t
 * Output:
 *    none
*/
void SinhVien::setAge(uint8_t age){
    AGE = age;
}

/*
 * Function: SinhVien::getAge()
 * Description: used to get age
 * Input:
 *    none
 * Output:
 *    return SinhVien::AGE in type of uint8_t
*/
uint8_t SinhVien::getAge(){
    return this->AGE;
}

/*
 * Function: SinhVien::setDiemToan()
 * Description: set math score for object
 * Input:
 *    diemToan: float
 * Output:
 *    none
*/
void SinhVien::setDiemToan(float diemToan){
    DIEM_TOAN = diemToan;
}

/*
 * Function: SinhVien::getDiemToan()
 * Description: used to get math score
 * Input:
 *    none
 * Output:
 *    return SinhVien::DIEM_TOAN in type of float
*/
float SinhVien::getDiemToan(){
    return this->DIEM_TOAN;
}

/*
 * Function: SinhVien::setDiemLy()
 * Description: set physic score for object
 * Input:
 *    diemLy: float
 * Output:
 *    none
*/
void SinhVien::setDiemLy(float diemLy){
    DIEM_LY = diemLy;
}

/*
 * Function: SinhVien::getDiemLy()
 * Description: used to get physic score
 * Input:
 *    none
 * Output:
 *    return SinhVien::DIEM_LY in type of float
*/
float SinhVien::getDiemLy(){
    return this->DIEM_LY;
}

/*
 * Function: SinhVien::setDiemHoa()
 * Description: set chemistry score for object
 * Input:
 *    diemHoa: float
 * Output:
 *    none
*/
void SinhVien::setDiemHoa(float diemHoa){
    DIEM_HOA = diemHoa;
}

/*
 * Function: SinhVien::getDiemHoa()
 * Description: used to get chemistry score
 * Input:
 *    none
 * Output:
 *    return SinhVien::DIEM_HOA in type of float
*/
float SinhVien::getDiemHoa(){
    return this->DIEM_HOA;
}

/*
 * Function: SinhVien::getDiemTrungBinh()
 * Description: used to get average score from math, physic, chemistry score
 * Input:
 *    none
 * Output:
 *    return average score in type of float
*/
float SinhVien::getDiemTrungBinh(){
    return (DIEM_TOAN + DIEM_LY + DIEM_HOA)/3;
}

/*
 * Function: SinhVien::getHocLuc()
 * Description: used to get academic rank depend on average score
 * Input:
 *    none
 * Output:
 *    return academic rank in type of TypeRankAcademic
*/
TypeRankAcademic SinhVien::getHocLuc(){
    if(getDiemTrungBinh() >= 8){
        return GIOI;
    }else if(getDiemTrungBinh() >= 6.5){
        return KHA;
    }else if(getDiemTrungBinh() >= 5){
        return TRUNG_BINH;
    }else{
        return YEU;
    }
}

typedef enum{
            GIOI_TINH,
            DIEM
        }TypeDoiTuong;

typedef enum{
            NAME,
            GPA
        }TypeOfSort;

/*
 * Function: Class Menu
 * Description: The class contains all properties and methods of a menu
 * Input:
 *    None
 * Output:
 *    None
*/
class Menu{
    private:
        vector<SinhVien> Database;
    public:
        Menu();
        void enterInfo(uint8_t mode, uint8_t index);
        void themSinhVien();
        void capNhatThongTin();
        void xoaSinhVien();
        void timSinhVien();
        void sort(TypeOfSort sortType);
        void hienThiDanhSach(SinhVien sv,uint8_t index);
};

/*
 * Function: Constructor Menu
 * Description: Create a menu with 8 functions. User choose function by press number corresponding to that function  
 * Input:
 *    None
 * Output:
 *    None
*/
Menu::Menu(){
    int phim = 0;
    string name;

    uint8_t index = 0;
    uint8_t infoFound = 0;

    while(phim!=8){
        switch (phim)
        {
        case 0:
            do
            {   
                cout << "\nMENU QUAN LY SINH VIEN(0)\n";
                cout << "1. Them sinh vien\n";
                cout << "2. Cap nhat thong tin sinh vien boi ID\n";
                cout << "3. Xoa sinh vien boi ID\n";
                cout << "4. Tim kiem sinh vien theo ten\n";
                cout << "5. Sap xep sinh vien theo diem trung binh (GPA)\n";
                cout << "6. Sap xep sinh vien theo ten\n";
                cout << "7. Hien thi danh sach sinh vien\n";
                cout << "8. Thoat Chuong Trinh\n";
                cout << "\nVui long nhap phim: ";
                scanf("%d", &phim);
            } while (phim > 8);
            break;
    
        case 1:
            enterInfo(0,0);
            do
            {
                cout << "\nMENU QUAN LY SINH VIEN(1)\n";
                cout << "0. Quay lai\n";
                cout << "1. Them sinh vien\n";
                cout << "\nVui long nhap phim: ";
                scanf("%d", &phim);
            } while (phim > 2);
            break;
        
        case 2:
            int id;
            infoFound = 0;
            index = 0;

            INPUT_TYPE("\nNhap ID can cap nhat: ", id);

            for(SinhVien sv : Database){
                if(sv.getID() == id){
                    infoFound = 1;
                    enterInfo(1, index);
                }
                index++;
            }
            if (infoFound == 0)   cout << "\n    ID not found!\n";

            phim = 0;
            break;

        case 3:
            xoaSinhVien();
            phim = 0;
            break;

        case 4:
            index = 1;

            INPUT_TYPE("\nNhap ten sinh vien can tim: ", name);

            for(SinhVien sv : Database){
                if (sv.getName().c_str() == name){
                    infoFound = 1;
                    hienThiDanhSach(sv, index);
                }
                index ++;
            }
            if (infoFound == 0)   cout << "\n    Name not found!\n";

            phim = 0;
            break;

        case 5:
            sort(GPA);
            phim = 7;
            break;
        
        case 6:
            sort(NAME);
            phim = 7;
            break;

        case 7:
            index = 1;

            PRINT_TITLE();
            for(SinhVien sv: Database){
                hienThiDanhSach(sv, index);
                index ++;
            }
            phim = 0;
            break;
    
        case 8:
            break;
            
        default:
            phim=0;
            break;
        }
    } 
}

/*
 * Function: Menu::enterInfo()
 * Description: This method is used for adding or updating student information into an element and store in database
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::enterInfo(uint8_t mode, uint8_t index){
    printf("\nNhap thong tin sinh vien\n");
    string name;
    string gender;
    int age;
    float diemToan;
    float diemLy;
    float diemHoa;

    INPUT_TYPE("   Ten: ", name);

    do
    {
        INPUT_TYPE("   Gioi tinh(Nam/Nu): ", gender);

        if (!(gender == "Nam" | gender == "Nu"))   printf("    FORMAT ERROR!!!\n\n");

    } while (!(gender == "Nam" | gender == "Nu"));

    INPUT_TYPE("   Tuoi: ", age);
    
    do
    {
        INPUT_TYPE("   Diem Toan: ", diemToan);

        if (diemToan > 10 | diemToan < 0)   printf("    FORMAT ERROR!!!\n\n");
        
    } while (diemToan > 10 | diemToan < 0);
    
    do
    {
        INPUT_TYPE("   Diem Ly: ", diemLy);

        if (diemLy > 10 | diemLy < 0)       printf("    FORMAT ERROR!!!\n\n");

    } while (diemLy > 10 | diemLy < 0);

    do
    {
        INPUT_TYPE("   Diem Hoa: ", diemHoa);
        if (diemHoa > 10 | diemHoa < 0)     printf("    FORMAT ERROR!!!\n\n");
        
    } while (diemHoa > 10 | diemHoa < 0);

    SinhVien sv(name, gender, age, diemToan, diemLy, diemHoa);

    if (mode == 0){
        Database.push_back(sv);
        cout << "\nThem thong tin thanh cong!\n";
    }
    else if(mode == 1){
        Database[index] = sv;
        cout << "\nCap nhat thong tin thanh cong!\n";
    }
}

/*
 * Function: Menu::xoaSinhVien()
 * Description: This method is used for deleting student information of the element in database
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::xoaSinhVien(){
    uint8_t id;
    uint8_t index = 0;
    uint8_t idFound = 0;

    INPUT_TYPE("\nNhap ID cua sinh vien can xoa: ", id);

    for(SinhVien sv : Database){
        if(sv.getID() == id){
            idFound = 1;
            Database.erase(Database.begin()+index);
            printf("\nXoa sinh vien co ID %d thanh cong!\n", id);
        }
        index++;
    }
    if(idFound == 0) cout << "\n    ID not found!\n";
}

/*
 * Function: Menu::sort()
 * Description: This method is used for sorting student list in database by average score or by name
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::sort(TypeOfSort sortType){
    SinhVien temp;
    for(uint8_t i=0; i < Database.size()-1; i++){
        for (uint8_t j = i+1; j < Database.size(); j++){
            if (sortType == GPA){
                if(Database[i].getDiemTrungBinh() > Database[j].getDiemTrungBinh()){
                    temp=Database[j];
                    Database[j]=Database[i];
                    Database[i]=temp;
                }
            }
            else if (sortType == NAME){
                if(Database[i].getName().compare(Database[j].getName()) > 0){
                    temp=Database[j];
                    Database[j]=Database[i];
                    Database[i]=temp;
                } 
            }
        }           
    }
}

/*
 * Function: Menu::hienThiDanhSach()
 * Description: This method is used for displaying student list in database
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::hienThiDanhSach(SinhVien sv, uint8_t index){
    string s_rankAcademic;

    if(sv.getHocLuc() == GIOI) s_rankAcademic = "Gioi";
    else if(sv.getHocLuc() == KHA) s_rankAcademic = "Kha";
    else if(sv.getHocLuc() == TRUNG_BINH) s_rankAcademic = "Trung Binh";
    else s_rankAcademic = "Yeu";

    printf("| %-4d|  %-5d| %-14s|    %-7s|  %-4d|    %-7.2f|   %-6.2f|   %-7.2f| %-5.2f|   %-14s|\n", index, sv.getID(), sv.getName().c_str(), sv.getGender().c_str(), sv.getAge(), sv.getDiemToan(),sv.getDiemLy(), sv.getDiemHoa(), sv.getDiemTrungBinh(), s_rankAcademic.c_str());
    printf("+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n");
}

int main(int argc, char const *argv[]){
    Menu quanlysinhvien;
    return 0;
}
