#include <iostream>
#include <string>

using namespace std;

int main() {
    const int N = 20;       //number of students
    string names[N];        //name[0] .. name[19]
    string ids[N];          //ids[0] .. ids[19]
    string phones[N];       //phones[0] .. phones[19]

    // 1. Gán giá trị cho từng phần tử trong mảng (index từ 0 đến 19)
    names[0] = "Nguyen Van A";   ids[0] = "23110001";   phones[0] = "0901234567";
    names[1] = "Tran Thi B";    ids[1] = "23110002";   phones[1] = "0912345678";
    names[2] = "Le Van C";      ids[2] = "23110003";   phones[2] = "0923456789";
    names[3] = "Pham Minh D";   ids[3] = "23110004";   phones[3] = "0934567890";
    names[4] = "Hoang Anh E";   ids[4] = "23110005";   phones[4] = "0945678901";
    names[5] = "Vu Thi F";      ids[5] = "23110006";   phones[5] = "0956789012";
    names[6] = "Dang Van G";    ids[6] = "23110007";   phones[6] = "0967890123";
    names[7] = "Bui Thi H";     ids[7] = "23110008";   phones[7] = "0978901234";
    names[8] = "Dinh Van I";    ids[8] = "23110009";   phones[8] = "0989012345";
    names[9] = "Do Thi K";      ids[9] = "23110010";   phones[9] = "0990123456";
    names[10] = "Hoang Van L";  ids[10] = "23110011";  phones[10] = "0909876543";
    names[11] = "Ngo Thi M";    ids[11] = "23110012";  phones[11] = "0918765432";
    names[12] = "Duong Van N";  ids[12] = "23110013";  phones[12] = "0927654321";
    names[13] = "Ly Thi O";     ids[13] = "23110014";  phones[13] = "0936543210";
    names[14] = "Truong Van P"; ids[14] = "23110015";  phones[14] = "0945432109";
    names[15] = "Mai Thi Q";    ids[15] = "23110016";  phones[15] = "0954321098";
    names[16] = "Phan Van R";   ids[16] = "23110017";  phones[16] = "0963210987";
    names[17] = "Trinh Thi S";  ids[17] = "23110018";  phones[17] = "0972109876";
    names[18] = "Cao Van T";    ids[18] = "23110019";  phones[18] = "0981098765";
    names[19] = "Le Van U";     ids[19] = "23110020";  phones[19] = "0987654321";

    cout << "              STUDENT LIST              " << endl << endl;

    cout << "Student 1: " << names[0] << " - " << ids[0] << " - " << phones[0] << endl;
    cout << "Student 2: " << names[1] << " - " << ids[1] << " - " << phones[1] << endl;
    cout << "Student 3: " << names[2] << " - " << ids[2] << " - " << phones[2] << endl;
    cout << "Student 4: " << names[3] << " - " << ids[3] << " - " << phones[3] << endl;
    cout << "Student 5: " << names[4] << " - " << ids[4] << " - " << phones[4] << endl;
    cout << "Student 6: " << names[5] << " - " << ids[5] << " - " << phones[5] << endl;
    cout << "Student 7: " << names[6] << " - " << ids[6] << " - " << phones[6] << endl;
    cout << "Student 8: " << names[7] << " - " << ids[7] << " - " << phones[7] << endl;
    cout << "Student 9: " << names[8] << " - " << ids[8] << " - " << phones[8] << endl;
    cout << "Student 10: " << names[9] << " - " << ids[9] << " - " << phones[9] << endl;
    cout << "Student 11: " << names[10] << " - " << ids[10] << " - " << phones[10] << endl;
    cout << "Student 12: " << names[11] << " - " << ids[11] << " - " << phones[11] << endl;
    cout << "Student 13: " << names[12] << " - " << ids[12] << " - " << phones[12] << endl;
    cout << "Student 14: " << names[13] << " - " << ids[13] << " - " << phones[13] << endl;
    cout << "Student 15: " << names[14] << " - " << ids[14] << " - " << phones[14] << endl;
    cout << "Student 16: " << names[15] << " - " << ids[15] << " - " << phones[15] << endl;
    cout << "Student 17: " << names[16] << " - " << ids[16] << " - " << phones[16] << endl;
    cout << "Student 18: " << names[17] << " - " << ids[17] << " - " << phones[17] << endl;
    cout << "Student 19: " << names[18] << " - " << ids[18] << " - " << phones[18] << endl;
    cout << "Student 20: " << names[19] << " - " << ids[19] << " - " << phones[19] << endl;

    return 0;
}