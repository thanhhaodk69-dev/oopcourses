
#include <iostream>
#include <string>
#include <limits>
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
        categoryId = 0;
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

class Category {
private:
    int CategoryId;
    string CategoryName;
    string Description;

public:
    // Constructor không tham số
    Category() {
        CategoryId = 0;
        CategoryName = "Unknown";
        Description = "No description";
    }

    // Constructor có 1 tham số
    Category(int CategoryId) {
        this->CategoryId = CategoryId;
        CategoryName = "Unknown";
        Description = "No description";
    }

    // Constructor có 2 tham số
    Category(int CategoryId, string CategoryName) {
        this->CategoryId = CategoryId;
        this->CategoryName = CategoryName;
        Description = "No description";
    }

    // Constructor có 3 tham số
    Category(int CategoryId, string CategoryName, string Description) {
        this->CategoryId = CategoryId;
        this->CategoryName = CategoryName;
        this->Description = Description;
    }

    // Getter
    int getCategoryId() {
        return CategoryId;
    }

    string getCategoryName() {
        return CategoryName;
    }

    string getDescription() {
        return Description;
    }

    // Setter
    void setCategoryId(int CategoryId) {
        this->CategoryId = CategoryId;
    }

    void setCategoryName(string CategoryName) {
        this->CategoryName = CategoryName;
    }

    void setDescription(string Description) {
        this->Description = Description;
    }

    // Hiển thị thông tin Category
    void displayCategoryInfo() {
        cout << "Category ID: " << CategoryId << endl;
        cout << "Category Name: " << CategoryName << endl;
        cout << "Description: " << Description << endl;
    }
};


class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    string startdate;

    Category categories[4];
    Fish fishes[40];

public:
    // Getter
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getOwner() {
        return owner;
    }

    string getStartdate() {
        return startdate;
    }

    // Setter
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void setOwner(string owner) {
        this->owner = owner;
    }

    void setStartdate(string startdate) {
        this->startdate = startdate;
    }

    // Display shop information
    void displayInfo() {
        cout << "\n===== FISH SHOP INFORMATION =====" << endl;
        cout << "Shop ID: " << id << endl;
        cout << "Shop Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << owner << endl;
        cout << "Start Date: " << startdate << endl;
    }

    // Input 4 categories and 10 fish for each category
    void inputData() {
        for (int i = 0; i < 4; i++) {
            int catId = i + 1;
            string catName, description;

            cout << "\n===== INPUT CATEGORY " << catId
                 << " =====" << endl;

            cout << "Category name: ";
            getline(cin, catName);

            cout << "Description: ";
            getline(cin, description);

            categories[i].setCategoryId(catId);
            categories[i].setCategoryName(catName);
            categories[i].setDescription(description);

            // Input 10 fish for this category
            for (int j = 0; j < 10; j++) {
                int fishId;
                string fishName, color, characteristic;

                cout << "\nInput fish " << j + 1
                     << " of category " << catId << endl;

                cout << "Fish ID: ";
                cin >> fishId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Fish name: ";
                getline(cin, fishName);

                cout << "Color: ";
                getline(cin, color);

                cout << "Characteristic: ";
                getline(cin, characteristic);

                int index = i * 10 + j;

                fishes[index].setId(fishId);
                fishes[index].setName(fishName);
                fishes[index].setColor(color);
                fishes[index].setCharacteristic(characteristic);
                fishes[index].setCategoryId(catId);
            }
        }
    }

    // Display all categories and their fish
    void displayAllInfo() {
        cout << "\n========== ALL CATEGORIES =========="
             << endl;

        for (int i = 0; i < 4; i++) {
            categories[i].displayCategoryInfo();

            cout << "\n--- Fish in this category ---" << endl;

            for (int j = 0; j < 40; j++) {
                if (fishes[j].getCategoryId()
                    == categories[i].getCategoryId()) {
                    fishes[j].displayFishInfo();
                }
            }

            cout << "====================================" << endl;
        }
    }
};

int main() {
    FishShop shop;

    // Input fish shop information
    int shopId;
    string shopName, address, owner, startdate;

    cout << "===== INPUT FISH SHOP =====" << endl;

    cout << "Shop ID: ";
    cin >> shopId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Shop name: ";
    getline(cin, shopName);

    cout << "Address: ";
    getline(cin, address);

    cout << "Owner: ";
    getline(cin, owner);

    cout << "Start date: ";
    getline(cin, startdate);

    shop.setId(shopId);
    shop.setName(shopName);
    shop.setAddress(address);
    shop.setOwner(owner);
    shop.setStartdate(startdate);

    // Input 4 categories and 40 fish
    shop.inputData();

    // Display shop information
    shop.displayInfo();

    // Display all categories and their fish
    shop.displayAllInfo();
    //  Category category1(1, "Goldfish",
    //                    "Goldfish and decorative goldfish");

    // Category category2(2, "Tropical Fish",
    //                    "Colorful tropical aquarium fish");

    // Category category3(3, "Freshwater Fish",
    //                    "Fish living in freshwater");

    // // Display category information
    // cout << "\n===== CATEGORY INFORMATION =====" << endl;

    // category1.displayCategoryInfo();
    // cout << "------------------------" << endl;

    // category2.displayCategoryInfo();
    // cout << "------------------------" << endl;

    // category3.displayCategoryInfo();
    // cout << "------------------------" << endl;
    // // 1. Tạo 5 đối tượng Fish với các constructor khác nhau
    // Fish fish1;
    // Fish fish2(2);
    // Fish fish3(3, "Betta");
    // Fish fish4(4, "Goldfish", "Orange");
    // Fish fish5(5, "Guppy", "Blue",
    //             "Small fish with colorful tail");
    // Fish fish6(6, "Koi", "Red and White",
    //            "Colorful ornamental carp");

    // Fish fish7(7, "Angelfish", "Silver",
    //            "Flat body and long fins");

    // Fish fish8(8, "Discus", "Blue",
    //            "Round body");

    // Fish fish9(9, "Neon Tetra", "Blue",
    //            "Small fish with bright stripes");

    // Fish fish10(10, "Molly", "Black",
    //             "Active aquarium fish");

    // Fish fish11(11, "Platy", "Red",
    //             "Peaceful small fish");

    // Fish fish12(12, "Oscar", "Black and Orange",
    //             "Large freshwater fish");

    // Fish fish13(13, "Corydoras", "Brown",
    //             "Bottom-dwelling fish");

    // Fish fish14(14, "White Cloud Minnow", "Silver",
    //             "Small fish preferring cooler water");

    // Fish fish15(15, "Fancy Goldfish", "White",
    //             "Decorative goldfish");

    // // 2. Cập nhật thông tin cho các đối tượng
    // fish1.setId(1);
    // fish1.setName("Koi");
    // fish1.setColor("Red and White");
    // fish1.setCharacteristic("Friendly and active");

    // fish2.setName("Angelfish");
    // fish2.setColor("Silver");
    // fish2.setCharacteristic("Flat body");

    // fish3.setColor("Black");
    // fish3.setCharacteristic("Aggressive");

    // fish4.setCharacteristic("Large body");

    // // 3. Hiển thị thông tin của tất cả các đối tượng Fish
    // cout << "===== ORIGINAL FISH INFORMATION ====="
    //      << endl;

    // fish1.displayFishInfo();
    // fish2.displayFishInfo();
    // fish3.displayFishInfo();
    // fish4.displayFishInfo();
    // fish5.displayFishInfo();
    // fish6.displayFishInfo();
    // fish7.displayFishInfo();
    // fish8.displayFishInfo();
    // fish9.displayFishInfo();
    // fish10.displayFishInfo();
    // fish11.displayFishInfo();
    // fish12.displayFishInfo();
    // fish13.displayFishInfo();
    // fish14.displayFishInfo();
    // fish15.displayFishInfo();

    // // 4. ập nhật thông tin của fish3 bằng setters
    // fish3.setName("Siamese Fighting Fish");
    // fish3.setColor("Blue and Red");
    // fish3.setCharacteristic("Territorial fish");

    // // 5. sử dụng getters để lấy và hiển thị thông tin mới
    // cout << "\n===== UPDATED FISH INFORMATION ====="
    //      << endl;

    // cout << "ID: " << fish3.getId() << endl;
    // cout << "Name: " << fish3.getName() << endl;
    // cout << "Color: " << fish3.getColor() << endl;
    // cout << "Characteristic: "
    //      << fish3.getCharacteristic() << endl;

    // // 6. Hiển thị đối tượng sau khi cập nhật để xác nhận các thay đổi
    // cout << "\n===== VERIFY CHANGES =====" << endl;
    // fish3.displayFishInfo();

    // // Category 1: Goldfish
    // fish4.setCategoryId(1);
    // fish15.setCategoryId(1);

    // // Category 2: Tropical Fish
    // fish3.setCategoryId(2);
    // fish5.setCategoryId(2);
    // fish7.setCategoryId(2);
    // fish8.setCategoryId(2);
    // fish9.setCategoryId(2);
    // fish10.setCategoryId(2);
    // fish11.setCategoryId(2);
    // fish12.setCategoryId(2);

    // // Category 3: Freshwater Fish
    // fish1.setCategoryId(3);
    // fish2.setCategoryId(3);
    // fish6.setCategoryId(3);
    // fish13.setCategoryId(3);
    // fish14.setCategoryId(3);

    // // 7. Question 6 - Group fish by color
    
    // cout << "\n===== GROUP FISH BY COLOR =====" << endl;

    // // Check each fish
    // for (int i = 1; i <= 15; i++) {
    //     string currentColor;

    //     // Get the color of the current fish
    //     switch (i) {
    //     case 1: currentColor = fish1.getColor(); break;
    //     case 2: currentColor = fish2.getColor(); break;
    //     case 3: currentColor = fish3.getColor(); break;
    //     case 4: currentColor = fish4.getColor(); break;
    //     case 5: currentColor = fish5.getColor(); break;
    //     case 6: currentColor = fish6.getColor(); break;
    //     case 7: currentColor = fish7.getColor(); break;
    //     case 8: currentColor = fish8.getColor(); break;
    //     case 9: currentColor = fish9.getColor(); break;
    //     case 10: currentColor = fish10.getColor(); break;
    //     case 11: currentColor = fish11.getColor(); break;
    //     case 12: currentColor = fish12.getColor(); break;
    //     case 13: currentColor = fish13.getColor(); break;
    //     case 14: currentColor = fish14.getColor(); break;
    //     case 15: currentColor = fish15.getColor(); break;
    //     }

    //     bool colorAlreadyDisplayed = false;

    //     // Check whether this color was displayed before
    //     for (int j = 1; j < i; j++) {
    //         string previousColor;

    //         switch (j) {
    //         case 1: previousColor = fish1.getColor(); break;
    //         case 2: previousColor = fish2.getColor(); break;
    //         case 3: previousColor = fish3.getColor(); break;
    //         case 4: previousColor = fish4.getColor(); break;
    //         case 5: previousColor = fish5.getColor(); break;
    //         case 6: previousColor = fish6.getColor(); break;
    //         case 7: previousColor = fish7.getColor(); break;
    //         case 8: previousColor = fish8.getColor(); break;
    //         case 9: previousColor = fish9.getColor(); break;
    //         case 10: previousColor = fish10.getColor(); break;
    //         case 11: previousColor = fish11.getColor(); break;
    //         case 12: previousColor = fish12.getColor(); break;
    //         case 13: previousColor = fish13.getColor(); break;
    //         case 14: previousColor = fish14.getColor(); break;
    //         case 15: previousColor = fish15.getColor(); break;
    //         }

    //         if (currentColor == previousColor) {
    //             colorAlreadyDisplayed = true;
    //             break;
    //         }
    //     }

    //     // Display each color only once
    //     if (!colorAlreadyDisplayed) {
    //         cout << "\nColor: " << currentColor << endl;

    //         // Find all fish with the same color
    //         for (int j = 1; j <= 15; j++) {
    //             string fishColor;
    //             string fishName;

    //             switch (j) {
    //             case 1:
    //                 fishColor = fish1.getColor();
    //                 fishName = fish1.getName();
    //                 break;
    //             case 2:
    //                 fishColor = fish2.getColor();
    //                 fishName = fish2.getName();
    //                 break;
    //             case 3:
    //                 fishColor = fish3.getColor();
    //                 fishName = fish3.getName();
    //                 break;
    //             case 4:
    //                 fishColor = fish4.getColor();
    //                 fishName = fish4.getName();
    //                 break;
    //             case 5:
    //                 fishColor = fish5.getColor();
    //                 fishName = fish5.getName();
    //                 break;
    //             case 6:
    //                 fishColor = fish6.getColor();
    //                 fishName = fish6.getName();
    //                 break;
    //             case 7:
    //                 fishColor = fish7.getColor();
    //                 fishName = fish7.getName();
    //                 break;
    //             case 8:
    //                 fishColor = fish8.getColor();
    //                 fishName = fish8.getName();
    //                 break;
    //             case 9:
    //                 fishColor = fish9.getColor();
    //                 fishName = fish9.getName();
    //                 break;
    //             case 10:
    //                 fishColor = fish10.getColor();
    //                 fishName = fish10.getName();
    //                 break;
    //             case 11:
    //                 fishColor = fish11.getColor();
    //                 fishName = fish11.getName();
    //                 break;
    //             case 12:
    //                 fishColor = fish12.getColor();
    //                 fishName = fish12.getName();
    //                 break;
    //             case 13:
    //                 fishColor = fish13.getColor();
    //                 fishName = fish13.getName();
    //                 break;
    //             case 14:
    //                 fishColor = fish14.getColor();
    //                 fishName = fish14.getName();
    //                 break;
    //             case 15:
    //                 fishColor = fish15.getColor();
    //                 fishName = fish15.getName();
    //                 break;
    //             }

    //             if (fishColor == currentColor) {
    //                 cout << "  " << fishName << endl;
    //             }
    //         }
    //     }
    // }

    // int selectedCategoryId;

    // cout << "\n===== SELECT A CATEGORY =====" << endl;
    // cout << "1. Goldfish" << endl;
    // cout << "2. Tropical Fish" << endl;
    // cout << "3. Freshwater Fish" << endl;
    // cout << "Enter category ID: ";
    // cin >> selectedCategoryId;

    // cout << "\n===== FISH IN SELECTED CATEGORY =====" << endl;

    // // Check the selected category
    // if (selectedCategoryId == category1.getCategoryId()) {
    //     category1.displayCategoryInfo();
    // }
    // else if (selectedCategoryId == category2.getCategoryId()) {
    //     category2.displayCategoryInfo();
    // }
    // else if (selectedCategoryId == category3.getCategoryId()) {
    //     category3.displayCategoryInfo();
    // }
    // else {
    //     cout << "Invalid category ID!" << endl;
    // }

    // // Display fish belonging to the selected category
    // if (selectedCategoryId >= 1 && selectedCategoryId <= 3) {
    //     bool found = false;

    //     // Check all 15 fish
    //     if (fish1.getCategoryId() == selectedCategoryId) {
    //         fish1.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish2.getCategoryId() == selectedCategoryId) {
    //         fish2.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish3.getCategoryId() == selectedCategoryId) {
    //         fish3.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish4.getCategoryId() == selectedCategoryId) {
    //         fish4.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish5.getCategoryId() == selectedCategoryId) {
    //         fish5.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish6.getCategoryId() == selectedCategoryId) {
    //         fish6.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish7.getCategoryId() == selectedCategoryId) {
    //         fish7.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish8.getCategoryId() == selectedCategoryId) {
    //         fish8.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish9.getCategoryId() == selectedCategoryId) {
    //         fish9.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish10.getCategoryId() == selectedCategoryId) {
    //         fish10.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish11.getCategoryId() == selectedCategoryId) {
    //         fish11.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish12.getCategoryId() == selectedCategoryId) {
    //         fish12.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish13.getCategoryId() == selectedCategoryId) {
    //         fish13.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish14.getCategoryId() == selectedCategoryId) {
    //         fish14.displayFishInfo();
    //         found = true;
    //     }
    //     if (fish15.getCategoryId() == selectedCategoryId) {
    //         fish15.displayFishInfo();
    //         found = true;
    //     }

    //     if (!found) {
    //         cout << "No fish found in this category." << endl;
    //     }
    // }
    return 0;
}