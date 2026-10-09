
#include <iostream>
#include <string>
using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

public:

    // Constructor 1: không có tham số
    Fish() {
        id = 0;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // Constructor 2: có 1 tham số
    Fish(int id) {
        this->id = id;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // Constructor 3: có 2 tham số
    Fish(int id, string name) {
        this->id = id;
        this->name = name;
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
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
        categoryId = 0;
    }
    // constructor 6: có 5 tham số
    Fish(int id, string name, string color,
     string characteristic, int categoryId) {
    this->id = id;
    this->name = name;
    this->color = color;
    this->characteristic = characteristic;
    this->categoryId = categoryId;
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

    int getCategoryId() {
        return categoryId;
    }

    void setCategoryId(int categoryId) {
        this->categoryId = categoryId;
    }

    // Hiển thị thông tin cá
    void displayFishInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: "
             << characteristic << endl;
        cout << "Category ID: " << categoryId << endl;
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
    Fish fish6(6, "Koi", "Red and White",
               "Colorful ornamental carp");

    Fish fish7(7, "Angelfish", "Silver",
               "Flat body and long fins");

    Fish fish8(8, "Discus", "Blue",
               "Round body");

    Fish fish9(9, "Neon Tetra", "Blue",
               "Small fish with bright stripes");

    Fish fish10(10, "Molly", "Black",
                "Active aquarium fish");

    Fish fish11(11, "Platy", "Red",
                "Peaceful small fish");

    Fish fish12(12, "Oscar", "Black and Orange",
                "Large freshwater fish");

    Fish fish13(13, "Corydoras", "Brown",
                "Bottom-dwelling fish");

    Fish fish14(14, "White Cloud Minnow", "Silver",
                "Small fish preferring cooler water");

    Fish fish15(15, "Fancy Goldfish", "White",
                "Decorative goldfish");

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
    fish6.displayFishInfo();
    fish7.displayFishInfo();
    fish8.displayFishInfo();
    fish9.displayFishInfo();
    fish10.displayFishInfo();
    fish11.displayFishInfo();
    fish12.displayFishInfo();
    fish13.displayFishInfo();
    fish14.displayFishInfo();
    fish15.displayFishInfo();

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

    // 7. Question 6 - Group fish by color
    
    cout << "\n===== GROUP FISH BY COLOR =====" << endl;

    // Check each fish
    for (int i = 1; i <= 15; i++) {
        string currentColor;

        // Get the color of the current fish
        switch (i) {
        case 1: currentColor = fish1.getColor(); break;
        case 2: currentColor = fish2.getColor(); break;
        case 3: currentColor = fish3.getColor(); break;
        case 4: currentColor = fish4.getColor(); break;
        case 5: currentColor = fish5.getColor(); break;
        case 6: currentColor = fish6.getColor(); break;
        case 7: currentColor = fish7.getColor(); break;
        case 8: currentColor = fish8.getColor(); break;
        case 9: currentColor = fish9.getColor(); break;
        case 10: currentColor = fish10.getColor(); break;
        case 11: currentColor = fish11.getColor(); break;
        case 12: currentColor = fish12.getColor(); break;
        case 13: currentColor = fish13.getColor(); break;
        case 14: currentColor = fish14.getColor(); break;
        case 15: currentColor = fish15.getColor(); break;
        }

        bool colorAlreadyDisplayed = false;

        // Check whether this color was displayed before
        for (int j = 1; j < i; j++) {
            string previousColor;

            switch (j) {
            case 1: previousColor = fish1.getColor(); break;
            case 2: previousColor = fish2.getColor(); break;
            case 3: previousColor = fish3.getColor(); break;
            case 4: previousColor = fish4.getColor(); break;
            case 5: previousColor = fish5.getColor(); break;
            case 6: previousColor = fish6.getColor(); break;
            case 7: previousColor = fish7.getColor(); break;
            case 8: previousColor = fish8.getColor(); break;
            case 9: previousColor = fish9.getColor(); break;
            case 10: previousColor = fish10.getColor(); break;
            case 11: previousColor = fish11.getColor(); break;
            case 12: previousColor = fish12.getColor(); break;
            case 13: previousColor = fish13.getColor(); break;
            case 14: previousColor = fish14.getColor(); break;
            case 15: previousColor = fish15.getColor(); break;
            }

            if (currentColor == previousColor) {
                colorAlreadyDisplayed = true;
                break;
            }
        }

        // Display each color only once
        if (!colorAlreadyDisplayed) {
            cout << "\nColor: " << currentColor << endl;

            // Find all fish with the same color
            for (int j = 1; j <= 15; j++) {
                string fishColor;
                string fishName;

                switch (j) {
                case 1:
                    fishColor = fish1.getColor();
                    fishName = fish1.getName();
                    break;
                case 2:
                    fishColor = fish2.getColor();
                    fishName = fish2.getName();
                    break;
                case 3:
                    fishColor = fish3.getColor();
                    fishName = fish3.getName();
                    break;
                case 4:
                    fishColor = fish4.getColor();
                    fishName = fish4.getName();
                    break;
                case 5:
                    fishColor = fish5.getColor();
                    fishName = fish5.getName();
                    break;
                case 6:
                    fishColor = fish6.getColor();
                    fishName = fish6.getName();
                    break;
                case 7:
                    fishColor = fish7.getColor();
                    fishName = fish7.getName();
                    break;
                case 8:
                    fishColor = fish8.getColor();
                    fishName = fish8.getName();
                    break;
                case 9:
                    fishColor = fish9.getColor();
                    fishName = fish9.getName();
                    break;
                case 10:
                    fishColor = fish10.getColor();
                    fishName = fish10.getName();
                    break;
                case 11:
                    fishColor = fish11.getColor();
                    fishName = fish11.getName();
                    break;
                case 12:
                    fishColor = fish12.getColor();
                    fishName = fish12.getName();
                    break;
                case 13:
                    fishColor = fish13.getColor();
                    fishName = fish13.getName();
                    break;
                case 14:
                    fishColor = fish14.getColor();
                    fishName = fish14.getName();
                    break;
                case 15:
                    fishColor = fish15.getColor();
                    fishName = fish15.getName();
                    break;
                }

                if (fishColor == currentColor) {
                    cout << "  " << fishName << endl;
                }
            }
        }
    }

    return 0;
}