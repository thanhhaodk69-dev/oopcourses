#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// 1. Thiết kế class Book
class Book {
private:
    // Các thuộc tính private (Mục 2 & 4)
    string bookId;
    string title;
    string author;
    int year;

public:
    // Constructor mặc định
    Book() : bookId(""), title(""), author(""), year(0) {}

    // Constructor có đầy đủ tham số (Mục 2)
    Book(string bookId, string title, string author, int year) {
        this->bookId = bookId;
        this->title = title;
        this->author = author;
        this->year = year;
    }

    // Các hàm getter để truy cập dữ liệu private an toàn (Mục 2 & 5)
    string getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Hàm nhập thông tin cuốn sách
    void input() {
        cout << "Nhap thong tin sach:\n";
        cout << "Ma sach: ";
        getline(cin, bookId);
        cout << "Ten sach: ";
        getline(cin, title);
        cout << "Tac gia: ";
        getline(cin, author);
        cout << "Nam xuat ban: ";
        cin >> year;
        cin.ignore(); // Xóa ký tự Enter dư trong bộ nhớ đệm
    }

    // Hàm hiển thị thông tin dạng chi tiết (dùng khi tìm thấy sách)
    void displayDetail() const {
        cout << "Thong tin sach:\n";
        cout << "Ma sach: " << bookId << endl;
        cout << "Ten sach: " << title << endl;
        cout << "Tac gia: " << author << endl;
        cout << "Nam xuat ban: " << year << endl;
    }
};

int main() {
    // Lưu sách trong vector<Book> (Mục 5)
    vector<Book> library;
    int choice;

    do {
        // Giao diện menu chương trình (Mục 5 & 6)
        cout << "\n===== QUAN LY SACH THU VIEN =====\n";
        cout << "1. Them sach\n";
        cout << "2. Hien thi danh sach sach\n";
        cout << "3. Tim sach theo ma sach\n";
        cout << "4. Thoat\n";
        cout << "--------------------------------\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore(); // Xóa bộ nhớ đệm

        switch (choice) {
            case 1: { // 1. Thêm sách vào danh sách (Mục 3 & 6)
                Book b;
                b.input();
                library.push_back(b);
                cout << "Da them sach thanh cong!\n";
                break;
            }
            case 2: { // 2. Hiển thị danh sách sách dạng bảng (Mục 3 & 6)
                if (library.empty()) {
                    cout << "Thu vien hien chua co sach nao!\n";
                } else {
                    cout << "\n===== DANH SACH SACH =====\n";
                    cout << left << setw(10) << "Ma sach" 
                         << setw(25) << "Ten sach" 
                         << setw(20) << "Tac gia" 
                         << setw(10) << "Nam" << endl;
                    cout << string(65, '-') << endl;

                    for (size_t i = 0; i < library.size(); i++) {
                        cout << left << setw(10) << library[i].getBookId()
                             << setw(25) << library[i].getTitle()
                             << setw(20) << library[i].getAuthor()
                             << setw(10) << library[i].getYear() << endl;
                    }
                }
                break;
            }
            case 3: { // 3. Tìm sách theo mã sách (Mục 3 & 6)
                if (library.empty()) {
                    cout << "Thu vien hien chua co sach nao!\n";
                    break;
                }
                string searchId;
                cout << "Nhap ma sach can tim: ";
                getline(cin, searchId);

                bool found = false;
                for (size_t i = 0; i < library.size(); i++) {
                    if (library[i].getBookId() == searchId) {
                        cout << "\n";
                        library[i].displayDetail();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Khong tim thay sach co ma: " << searchId << endl;
                }
                break;
            }
            case 4:
                cout << "Thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "Chuc nang khong hop le, vui long chon lai!\n";
        }
    } while (choice != 4);

    return 0;
}