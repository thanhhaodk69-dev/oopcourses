
#include <iostream>
#include <string>
using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

public:

    // Constructor 1: không có tham số
    Fish() {
        id = 0;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
    }

    // Constructor 2: có 1 tham số
    Fish(int id) {
        this->id = id;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
    }

    // Constructor 3: có 2 tham số
    Fish(int id, string name) {
        this->id = id;
        this->name = name;
        color = "Unknown";
        characteristic = "Unknown";
    }

    // Constructor 4: có 3 tham số
    Fish(int id, string name, string color) {
        this->id = id;
        this->name = name;
        this->color = color;
        characteristic = "Unknown";
    }

    // Constructor 5: có 4 tham số
    Fish(int id, string name, string color,
         string characteristic) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
    }

    // Getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }

    string getCharacteristic() {
        return characteristic;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setCharacteristic(string characteristic) {
        this->characteristic = characteristic;
    }

    // Hiển thị thông tin cá
    void displayFishInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: "
             << characteristic << endl;
        cout << "------------------------" << endl;
    }

};

int main() {
    // 1. Tạo 5 đối tượng Fish với các constructor khác nhau
    Fish fish1;
    Fish fish2(2);
    Fish fish3(3, "Betta");
    Fish fish4(4, "Goldfish", "Orange");
    Fish fish5(5, "Guppy", "Blue",
                "Small fish with colorful tail");

    // 2. Cập nhật thông tin cho các đối tượng
    fish1.setId(1);
    fish1.setName("Koi");
    fish1.setColor("Red and White");
    fish1.setCharacteristic("Friendly and active");

    fish2.setName("Angelfish");
    fish2.setColor("Silver");
    fish2.setCharacteristic("Flat body");

    fish3.setColor("Black");
    fish3.setCharacteristic("Aggressive");

    fish4.setCharacteristic("Large body");

    // 3. Hiển thị thông tin của tất cả các đối tượng Fish
    cout << "===== ORIGINAL FISH INFORMATION ====="
         << endl;

    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    // 4. ập nhật thông tin của fish3 bằng setters
    fish3.setName("Siamese Fighting Fish");
    fish3.setColor("Blue and Red");
    fish3.setCharacteristic("Territorial fish");

    // 5. sử dụng getters để lấy và hiển thị thông tin mới
    cout << "\n===== UPDATED FISH INFORMATION ====="
         << endl;

    cout << "ID: " << fish3.getId() << endl;
    cout << "Name: " << fish3.getName() << endl;
    cout << "Color: " << fish3.getColor() << endl;
    cout << "Characteristic: "
         << fish3.getCharacteristic() << endl;

    // 6. Hiển thị đối tượng sau khi cập nhật để xác nhận các thay đổi
    cout << "\n===== VERIFY CHANGES =====" << endl;
    fish3.displayFishInfo();

    return 0;
}