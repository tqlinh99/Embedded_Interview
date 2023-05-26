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

typedef enum{
    NAM,
    NU
}TypeGender;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeRankAcademic;

/*
 * Function: Class SinhVien
 * Description: The class contains all properties and methods of a student
 * Input:
 *    None
 * Output:
 *    None
*/
class SinhVien{
    private:
        int ID;
        string NAME;
        TypeGender GENDER;
        uint8_t AGE;
        float DIEM_TOAN;
        float DIEM_LY;
        float DIEM_HOA;
        float DIEM_TRUNG_BINH;
        TypeRankAcademic HOC_LUC;
    public:
        SinhVien(string name, TypeGender gender, uint8_t age, float diemToan, float diemLy, float diemHoa);
        int getID();
        void setName(string name);
        string getName();
        void setGender(TypeGender gender);
        TypeGender getGender();
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
SinhVien::SinhVien(string name, TypeGender gender, uint8_t age, float diemToan, float diemLy, float diemHoa){
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
void SinhVien::setGender(TypeGender gender){
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
TypeGender SinhVien::getGender(){
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
        void themSinhVien();
        void capNhatThongTin();
        void xoaSinhVien();
        void timSinhVien();
        void sortByGPA();
        void sortByName();
        void hienThiDanhSach();
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
            themSinhVien();
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
            capNhatThongTin();
            phim = 0;
            break;

        case 3:
            xoaSinhVien();
            phim = 0;
            break;

        case 4:
            timSinhVien();
            phim = 0;
            break;

        case 5:
            sortByGPA();
            hienThiDanhSach();
            phim = 0;
            break;
        
        case 6:
            sortByName();
            hienThiDanhSach();
            phim = 0;
            break;

        case 7:
            hienThiDanhSach();
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
 * Function: Menu::themSinhVien()
 * Description: This method is used for adding student information into an element and store in database
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::themSinhVien(){
    printf("\nNhap thong tin sinh vien\n");
    string name;
    string s_gender;
    TypeGender gender;
    uint8_t age;
    float diemToan;
    float diemLy;
    float diemHoa;

    cout << "   Ten: ";
    cin.ignore(100, '\n');
    getline(cin, name);

    do
    {
        cout << "   Gioi tinh(Nam/Nu): ";
        cin >> s_gender;
        if(s_gender == "Nam")   gender = NAM;
        else if(s_gender == "Nu")   gender = NU;
        else   printf("    FORMAT ERROR!!!\n\n");
    } while (!(s_gender == "Nam" | s_gender == "Nu"));

    printf("   Tuoi: ");
    scanf("%d", &age);

    do
    {
        printf("   Diem Toan: ");
        scanf("%f", &diemToan);
        if (diemToan > 10 | diemToan < 0){
            printf("    FORMAT ERROR!!!\n\n");
        }
    } while (diemToan > 10 | diemToan < 0);
    
    do
    {
        printf("   Diem Ly: ");
        scanf("%f", &diemLy);
        if (diemLy > 10 | diemLy < 0){
            printf("    FORMAT ERROR!!!\n\n");
        }
    } while (diemLy > 10 | diemLy < 0);

    do
    {
        printf("   Diem Hoa: ");
        scanf("%f", &diemHoa);
        if (diemHoa > 10 | diemHoa < 0){
            printf("    FORMAT ERROR!!!\n\n");
        }
    } while (diemHoa > 10 | diemHoa < 0);

    cout << "\nThem thong tin thanh cong!\n";

    SinhVien sv(name, gender, age, diemToan, diemLy, diemHoa);
    Database.push_back(sv);
}

/*
 * Function: Menu::capNhatThongTin()
 * Description: This method is used for updating student information storing already in database
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::capNhatThongTin(){
    uint8_t index = 0;
    uint8_t id;
    uint8_t idFound = 0;
    string name;
    string s_gender;
    TypeGender gender;
    uint8_t age;
    float diemToan;
    float diemLy;
    float diemHoa;

    cout << "\nNhap ID can cap nhat: ";
    scanf("%d", &id);

    for(SinhVien sv : Database){
        idFound = 1;
        if(sv.getID() == id){
            cout << "   Ten: ";
            cin.ignore(100, '\n');
            getline(cin, name);

            do
            {
                cout << "   Gioi tinh(Nam/Nu): ";
                cin >> s_gender;
                if(s_gender == "Nam")   gender = NAM;
                else if(s_gender == "Nu")   gender = NU;
                else   printf("    FORMAT ERROR!!!\n\n");
            } while (!(s_gender == "Nam" | s_gender == "Nu"));

            printf("   Tuoi: ");
            scanf("%d", &age);

            do
            {
                cout << "   Diem Toan: ";
                cin >> diemToan;
                if (diemToan > 10 || diemToan < 0){
                    printf("    FORMAT ERROR!!!\n\n");
                }
            } while (diemToan > 10 || diemToan < 0);
    
            do
            {
                cout << "   Diem Ly: ";
                cin >> diemLy;
                if (diemLy > 10 || diemLy < 0){
                    printf("    FORMAT ERROR!!!\n\n");
                }
            } while (diemLy > 10 || diemLy < 0);

            do
            {
                cout << "   Diem Hoa: ";
                cin >> diemHoa;
                if (diemHoa > 10 || diemHoa < 0){
                    printf("    FORMAT ERROR!!!\n\n");
                }
            } while (diemHoa > 10 || diemHoa < 0);

            sv.setName(name);
            sv.setGender(gender);
            sv.setAge(age);
            sv.setDiemToan(diemToan);
            sv.setDiemLy(diemLy);
            sv.setDiemHoa(diemHoa);
            Database[index] = sv;

            cout << "\nCap nhat thong tin thanh cong!\n";
        }
        index++;
    }
    if(idFound == 0) cout << "\n    ID not found!\n";
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

    cout << "\nNhap ID cua sinh vien can xoa: ";
    scanf("%d", &id);

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
 * Function: Menu::timSinhVien()
 * Description: This method is used for searching student information in database
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::timSinhVien(){
    string name;
    uint8_t STT = 1;
    uint8_t nameFound = 0;
    string s_Gender;
    string s_rankAcademic;

    cout << "\nNhap ten sinh vien can tim: ";
    cin.ignore(100, '\n');
    getline(cin, name);

    cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n";
    cout << "| STT |  ID   |      TEN      | GIOI TINH | TUOI | DIEM TOAN | DIEM LY | DIEM HOA | DTB  |    HOC LUC      |\n";
    cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n";

    for(SinhVien sv : Database){
        if (sv.getName().c_str() == name){
            nameFound = 1;
            if(sv.getGender() == NAM) s_Gender = "Nam";
            else s_Gender = "Nu";

            if(sv.getHocLuc() == GIOI) s_rankAcademic = "Gioi";
            else if(sv.getHocLuc() == KHA) s_rankAcademic = "Kha";
            else if(sv.getHocLuc() == TRUNG_BINH) s_rankAcademic = "Trung Binh";
            else s_rankAcademic = "Yeu";

            
            printf("| %3d ", STT);
            printf("|  %-5d", sv.getID());
            printf("| %-14s", sv.getName().c_str());
            printf("|    %-7s", s_Gender.c_str());
            printf("|  %-4d", sv.getAge());
            printf("|    %-7.2f", sv.getDiemToan());
            printf("|   %-6.2f", sv.getDiemLy());
            printf("|   %-7.2f", sv.getDiemHoa());
            printf("| %-5.2f", sv.getDiemTrungBinh());
            printf("|   %-14s|\n", s_rankAcademic.c_str());
            cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n";
        }
        STT++;
    }
    if(nameFound == 0) cout << "\n    Khong tim thay ten trong danh sach!\n";
}

/*
 * Function: Menu::sortByGPA()
 * Description: This method is used for sorting student list in database by average score
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::sortByGPA(){
    for(uint8_t i=0; i < Database.size()-1; i++){
        for (uint8_t j = i+1; j < Database.size(); j++){
            if(Database[i].getDiemTrungBinh() > Database[j].getDiemTrungBinh()){
                Database.push_back(Database[i]);
                Database[Database.size()-1]=Database[j];
                Database[j]=Database[i];
                Database[i]=Database[Database.size()-1];
                Database.pop_back();
            }
        }
    }           
}

/*
 * Function: Menu::sortByName()
 * Description: This method is used for sorting student list in database by name
 * Input:
 *    none
 * Output:
 *    none
*/
void Menu::sortByName(){
    for(uint8_t i=0; i < Database.size()-1; i++){
        for (uint8_t j = i+1; j < Database.size(); j++){
            if(Database[i].getName().compare(Database[j].getName()) > 0){
                Database.push_back(Database[i]);
                Database[Database.size()-1]=Database[j];
                Database[j]=Database[i];
                Database[i]=Database[Database.size()-1];
                Database.pop_back();
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
void Menu::hienThiDanhSach(){
    int STT=1;
    string s_Gender;
    string s_rankAcademic;

    cout << "\nDANH SACH SINH VIEN\n";
    cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n";
    cout << "| STT |  ID   |      TEN      | GIOI TINH | TUOI | DIEM TOAN | DIEM LY | DIEM HOA | DTB  |    HOC LUC      |\n";
    cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n";

    for (SinhVien sv : Database){

        if(sv.getGender() == NAM) s_Gender = "Nam";
        else s_Gender = "Nu";

        if(sv.getHocLuc() == GIOI) s_rankAcademic = "Gioi";
        else if(sv.getHocLuc() == KHA) s_rankAcademic = "Kha";
        else if(sv.getHocLuc() == TRUNG_BINH) s_rankAcademic = "Trung Binh";
        else s_rankAcademic = "Yeu";

        printf("| %3d ", STT);
        printf("|  %-5d", sv.getID());
        printf("| %-14s", sv.getName().c_str());
        printf("|    %-7s", s_Gender.c_str());
        printf("|  %-4d", sv.getAge());
        printf("|    %-7.2f", sv.getDiemToan());
        printf("|   %-6.2f", sv.getDiemLy());
        printf("|   %-7.2f", sv.getDiemHoa());
        printf("| %-5.2f", sv.getDiemTrungBinh());
        printf("|   %-14s|\n", s_rankAcademic.c_str());
        cout << "+-------------+---------------+-----------+------+-----------+---------+----------+------+-----------------+\n";

        STT++; 
    }
}

int main(int argc, char const *argv[]){
    Menu quanlysinhvien;
    return 0;
}
