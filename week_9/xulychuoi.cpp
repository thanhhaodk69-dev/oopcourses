#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

// HÀM HỖ TRỢ XỬ LÝ CHUỖI

string toLowerString(string str) {
    for (char& c : str) {
        c = tolower(c);
    }
    return str;
}

string formatFoodName(string name) {
    string result = "";
    int n = name.length();
    int i = 0;

    while (i < n && isspace(name[i])) i++;

    bool newWord = true;

    while (i < n) {
        if (isspace(name[i])) {
            while (i < n && isspace(name[i])) i++;

            if (i < n)
                result += " ";

            newWord = true;
        }
        else {
            if (newWord) {
                result += toupper(name[i]);
                newWord = false;
            }
            else {
                result += tolower(name[i]);
            }

            i++;
        }
    }

    return result;
}


// STRUCT FOOD

struct FOOD {
    string id;
    string name;
    double price;
    int quantity;

    void inputInfo() {
        cout << "   Nhap ma mon an (ID): ";
        cin >> id;

        cin.ignore();

        cout << "   Nhap ten mon an: ";
        getline(cin, name);
        name = formatFoodName(name);

        cout << "   Nhap don gia (VND): ";
        cin >> price;

        cout << "   So luong nhap kho: ";
        cin >> quantity;
    }

    void outputInfo() {
        cout << "   --------------------------------" << endl;
        cout << "   ID       : " << id << endl;
        cout << "   Ten mon  : " << name << endl;
        cout << "   Don gia  : " << price << " VND" << endl;
        cout << "   Ton kho  : " << quantity << " phan" << endl;
    }
};


// STRUCT ORDER

struct ORDER {
    string id;
    string customerName;
    string address;
    FOOD food;
    int quantity;
    string status;

    void generateOrderID(string phone) {
        string shortName = "";

        for (char c : customerName) {
            if (!isspace(c))
                shortName += toupper(c);
        }

        string shortPhone =
            (phone.length() >= 4)
            ? phone.substr(phone.length() - 4)
            : phone;

        id = "DH_" + shortName + "_" + shortPhone;

        cout << "   He thong da tao ma don: [" << id << "]" << endl;
    }

    void inputInfo(
        FOOD availableFood[],
        int availableCount,
        string resPhone = ""
    ) {
        cin.ignore();

        cout << "   Ten khach hang: ";
        getline(cin, customerName);

        generateOrderID(resPhone);

        cout << "   Dia chi giao hang: ";
        getline(cin, address);

        string foodSearch;

        cout << "   Nhap Ma hoac Ten mon: ";
        getline(cin, foodSearch);

        bool found = false;

        for (int i = 0; i < availableCount; i++) {
            if (foodSearch == availableFood[i].id ||
                foodSearch == availableFood[i].name) {

                food = availableFood[i];
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "   Mon nay chua co trong menu." << endl;
            cout << "   Vui long nhap thong tin mon moi:" << endl;

            food.inputInfo();
        }

        cout << "   So luong khach order: ";
        cin >> quantity;

        cin.ignore();

        cout << "   Trang thai don (Completed / Pending / Cancelled): ";
        getline(cin, status);

        displayDeliveryNotification();
    }

    void displayDeliveryNotification() {
        cout << "\n   Don hang [" << id << "] cua ["
             << customerName
             << "] dang duoc giao den dia chi ["
             << address << "]."
             << endl;
    }

    double getTotalPrice() {
        return food.price * quantity;
    }

    void outputInfo() {
        cout << "   ================ BILL ==================" << endl;
        cout << "   Ma don hang : " << id << endl;
        cout << "   Khach hang  : " << customerName << endl;
        cout << "   Dia chi     : " << address << endl;
        cout << "   Mon an      : " << food.name
             << " (ID: " << food.id << ")" << endl;
        cout << "   So luong    : " << quantity << endl;
        cout << "   Tong tien   : " << getTotalPrice() << " VND" << endl;
        cout << "   Trang thai  : " << status << endl;
        cout << "   ========================================" << endl;
    }
};


// STRUCT RESTAURANT

struct RESTAURANT {
    string name;
    string address;
    string phone;

    FOOD foods[MAX];
    int foodCount = 0;

    ORDER orders[MAX];
    int orderCount = 0;


    void inputRestaurantInfo() {
        cout << "THIET LAP THONG TIN CUA HANG" << endl;

        cout << "Nhap ten cua hang: ";
        getline(cin, name);

        cout << "Ten cua hang: [" << name << "]" << endl;

        cout << "Dia chi: ";
        getline(cin, address);

        cout << "So dien thoai: ";
        getline(cin, phone);

        cout << "Nhap so luong mon an: ";
        cin >> foodCount;

        for (int i = 0; i < foodCount; i++) {
            cout << "\n--- Nhap thong tin mon thu "
                 << i + 1 << " ---" << endl;

            foods[i].inputInfo();
        }

        cout << "Khoi tao thanh cong." << endl;
    }


    void addFood() {
        if (foodCount < MAX) {
            cout << "\n=== THEM MON MOI VAO MENU ===" << endl;

            foods[foodCount].inputInfo();
            foodCount++;

            cout << "Da them mon vao menu thanh cong." << endl;
        }
        else {
            cout << "Menu da day (100 mon)." << endl;
        }
    }


    void displatMenu() {
        cout << "\n<<<<<<<<<< MENU HOM NAY >>>>>>>>>>" << endl;

        if (foodCount == 0) {
            cout << "Chua co mon nao trong menu." << endl;
            return;
        }

        for (int i = 0; i < foodCount; i++) {
            foods[i].outputInfo();
        }
    }


    int findFoodIdex(string key) {
        string lowerKey = toLowerString(key);

        for (int i = 0; i < foodCount; i++) {
            if (toLowerString(foods[i].id) == lowerKey ||
                toLowerString(foods[i].name) == lowerKey) {

                return i;
            }
        }

        return -1;
    }


    void checkFoodExists(string key) {
        int idx = findFoodIdex(key);

        if (idx != -1) {
            cout << "Mon [" << foods[idx].name
                 << "] co trong menu." << endl;

            foods[idx].outputInfo();
        }
        else {
            cout << "Mon [" << key
                 << "] khong ton tai trong thuc don." << endl;
        }
    }


    void updateFoodIndex(string key) {
        int idx = findFoodIdex(key);

        if (idx != -1) {
            cout << "\nDa tim thay mon: "
                 << foods[idx].name << endl;

            cout << "Nhap gia tien moi: ";
            cin >> foods[idx].price;

            cout << "Nhap so luong ton kho moi: ";
            cin >> foods[idx].quantity;

            cout << "Chinh sua thong tin thanh cong." << endl;
        }
        else {
            cout << "Khong tim thay mon an nay de cap nhat."
                 << endl;
        }
    }


    void createOrder() {
        if (orderCount < MAX) {
            cout << "\n=== LEN DON CHO KHACH HANG ===" << endl;

            ORDER newOrder;

            newOrder.inputInfo(
                foods,
                foodCount,
                phone
            );

            int idx = findFoodIdex(newOrder.food.id);

            if (idx != -1) {
                if (foods[idx].quantity >= newOrder.quantity) {

                    foods[idx].quantity -= newOrder.quantity;

                    orders[orderCount] = newOrder;
                    orderCount++;

                    cout << "Chot don thanh cong. "
                         << "Kho da tu dong tru hang."
                         << endl;
                }
                else {
                    cout << "Trong kho chi con "
                         << foods[idx].quantity
                         << " phan. Khong du hang."
                         << endl;
                }
            }
            else {
                orders[orderCount] = newOrder;
                orderCount++;

                cout << "Chot don voi mon an ngoai menu thanh cong."
                     << endl;
            }
        }
        else {
            cout << "He thong qua tai. "
                 << "Khong the nhan them don."
                 << endl;
        }
    }


    void displayOrders() {
        cout << "\n<<<<<<<<<< DANH SACH DON HANG >>>>>>>>>>" << endl;

        if (orderCount == 0) {
            cout << "Chua co don hang nao." << endl;
            return;
        }

        for (int i = 0; i < orderCount; i++) {
            orders[i].outputInfo();
        }
    }


    void findOrderbyID(string orderID) {
        for (int i = 0; i < orderCount; i++) {

            if (orders[i].id == orderID) {
                cout << "\nDa tim thay don hang:" << endl;

                orders[i].outputInfo();

                return;
            }
        }

        cout << "Khong tim thay ma don: "
             << orderID << endl;
    }


    void updateOrderStatus(
        string orderID,
        string newStatus
    ) {
        for (int i = 0; i < orderCount; i++) {

            if (orders[i].id == orderID) {

                orders[i].status = newStatus;

                cout << "Trang thai don hang da duoc cap nhat thanh: ["
                     << newStatus << "]"
                     << endl;

                return;
            }
        }

        cout << "Ma don hang "
             << orderID
             << " khong ton tai."
             << endl;
    }


    void searchOrdersByCustomerName(string keyword) {
        cout << "\n========== TIM DON THEO TEN KHACH =========="
             << endl;

        string lowerKey = toLowerString(keyword);

        bool found = false;

        for (int i = 0; i < orderCount; i++) {

            if (toLowerString(orders[i].customerName)
                    .find(lowerKey) != string::npos) {

                orders[i].outputInfo();

                found = true;
            }
        }

        if (!found) {
            cout << "Khong tim thay don nao cua khach co ten: "
                 << keyword << endl;
        }
    }


    void countFoodOccurrences(string foodName) {
        string lowerFood = toLowerString(foodName);

        int count = 0;

        for (int i = 0; i < orderCount; i++) {

            if (toLowerString(orders[i].food.name) == lowerFood ||
                toLowerString(orders[i].food.id) == lowerFood) {

                count++;
            }
        }

        cout << "\nMon ["
             << foodName
             << "] da co mat trong "
             << count
             << " don hang."
             << endl;
    }


    double calculateCompletedReveue() {
        double totalRevenue = 0;

        for (int i = 0; i < orderCount; i++) {

            if (orders[i].status == "Completed" ||
                orders[i].status == "Hoan thanh" ||
                orders[i].status == "Completed ") {

                totalRevenue += orders[i].getTotalPrice();
            }
        }

        return totalRevenue;
    }
};


// MAIN

int main() {

    RESTAURANT myrestaurant;

    cout << "\n==================================================" << endl;
    cout << "        HE THONG QUAN LY NHA HANG" << endl;
    cout << "==================================================\n" << endl;

    myrestaurant.inputRestaurantInfo();

    while (true) {

        cout << "\n================ MENU DIEU KHIEN ================"
             << endl;

        cout << "   [1] Them mon an moi vao thuc don" << endl;
        cout << "   [2] Xem danh sach mon an" << endl;
        cout << "   [3] Cap nhat gia/so luong ton kho" << endl;
        cout << "   [4] Kiem tra mon co ton tai khong" << endl;
        cout << "   [5] Tao don hang moi" << endl;
        cout << "   [6] Xem toan bo lich su don hang" << endl;
        cout << "   [7] Tim don hang theo Ma ID" << endl;
        cout << "   [8] Tim don hang theo Ten khach" << endl;
        cout << "   [9] Doi trang thai don hang" << endl;
        cout << "  [10] Thong ke tan suat xuat hien cua mon an" << endl;
        cout << "  [11] Tinh tong doanh thu" << endl;
        cout << "   [0] Thoat" << endl;

        cout << "=================================================="
             << endl;

        cout << "Chon chuc nang: ";

        int choice;
        cin >> choice;


        if (choice == 0) {

            cout << "\nHe thong da tat." << endl;

            break;
        }


        if (choice == 1) {

            myrestaurant.addFood();
        }


        else if (choice == 2) {

            myrestaurant.displatMenu();
        }


        else if (choice == 3) {

            cin.ignore();

            string key;

            cout << "Nhap Ma hoac Ten mon muon chinh sua: ";
            getline(cin, key);

            myrestaurant.updateFoodIndex(key);
        }


        else if (choice == 4) {

            cin.ignore();

            string foodName;

            cout << "Nhap Ma hoac Ten mon de kiem tra: ";
            getline(cin, foodName);

            myrestaurant.checkFoodExists(foodName);
        }


        else if (choice == 5) {

            myrestaurant.createOrder();
        }


        else if (choice == 6) {

            myrestaurant.displayOrders();
        }


        else if (choice == 7) {

            cin.ignore();

            string id;

            cout << "Nhap Ma don hang (ID) can tim: ";
            getline(cin, id);

            myrestaurant.findOrderbyID(id);
        }


        else if (choice == 8) {

            cin.ignore();

            string customerName;

            cout << "Nhap Ten khach hang can tim: ";
            getline(cin, customerName);

            myrestaurant.searchOrdersByCustomerName(customerName);
        }


        else if (choice == 9) {

            cin.ignore();

            string id;
            string status;

            cout << "Nhap Ma don hang can cap nhat: ";
            getline(cin, id);

            cout << "Nhap trang thai moi "
                 << "(Pending / Completed / Cancelled): ";

            getline(cin, status);

            myrestaurant.updateOrderStatus(id, status);
        }


        else if (choice == 10) {

            cin.ignore();

            string foodName;

            cout << "Nhap Ten mon can xem: ";
            getline(cin, foodName);

            myrestaurant.countFoodOccurrences(foodName);
        }


        else if (choice == 11) {

            cout << "\nKET QUA TAI CHINH: "
                 << "Tong tien tu cac don 'Completed' la: "
                 << myrestaurant.calculateCompletedReveue()
                 << " VND"
                 << endl;
        }


        else {

            cout << "Chuc nang khong hop le. "
                 << "Vui long chon tu 0 - 11."
                 << endl;
        }
    }

    return 0;
}