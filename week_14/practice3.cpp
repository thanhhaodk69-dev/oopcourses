#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MenuItem {
protected:
    string name;
    double price;

public:
    MenuItem(string name, double price) : name(name), price(price) {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual ~MenuItem() = default;
};

class Drinks : public MenuItem {
public:
    Drinks(string name, double price) : MenuItem(name, price) {}
};

class Coffee : public Drinks {
public:
    Coffee(string name, double price) : Drinks(name, price) {}
};

class Tea : public Drinks {
public:
    Tea(string name, double price) : Drinks(name, price) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(string name, double price) : Drinks(name, price) {}
};

class Juices : public Drinks {
public:
    Juices(string name, double price) : Drinks(name, price) {}
};

class Foods : public MenuItem {
public:
    Foods(string name, double price) : MenuItem(name, price) {}
};

class Cake : public Foods {
public:
    Cake(string name, double price) : Foods(name, price) {}
};

class Breads : public Foods {
public:
    Breads(string name, double price) : Foods(name, price) {}
};

class OrderItem {
private:
    MenuItem* item;
    int quantity;
    string date;

public:
    OrderItem(MenuItem* item, int quantity, string date)
        : item(item), quantity(quantity), date(date) {}

    MenuItem* getItem() const { return item; }
    int getQuantity() const { return quantity; }
    string getDate() const { return date; }

    double getTotalPrice() const {
        return item->getPrice() * quantity;
    }
};

void calculateDailyRevenue(const vector<OrderItem>& orders, const string& targetDate) {
    double totalDrinks = 0;
    double totalFoods = 0;

    for (const auto& order : orders) {
        if (order.getDate() == targetDate) {
            if (dynamic_cast<Drinks*>(order.getItem())) {
                totalDrinks += order.getTotalPrice();
            }
            else if (dynamic_cast<Foods*>(order.getItem())) {
                totalFoods += order.getTotalPrice();
            }
        }
    }

    cout << "Doanh thu ngay " << targetDate << ":" << endl;
    cout << "- Drinks: " << totalDrinks << " VND" << endl;
    cout << "- Foods: "  << totalFoods  << " VND" << endl;
}

int main() {
    Coffee espresso("Espresso", 35000);
    Tea milkTea("Tra Sua", 40000);
    Smoothies mangoSmoothie("Sinh to xoai", 45000);
    Juices orangeJuice("Nuoc cam", 35000);

    Cake tiramisu("Banh Tiramisu", 50000);
    Breads croissant("Banh Sừng Bò", 30000);

    vector<OrderItem> orders = {
        OrderItem(&espresso, 2, "16/10/2026"),
        OrderItem(&milkTea, 3, "16/10/2026"),
        OrderItem(&tiramisu, 1, "16/10/2026"),
        OrderItem(&croissant, 4, "16/10/2026"),
        OrderItem(&orangeJuice, 1, "17/10/2026")
    };

    calculateDailyRevenue(orders, "16/10/2026");

    return 0;
}