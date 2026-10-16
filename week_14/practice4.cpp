#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Vehicle {
private:
    string id;
    string brand;
    double basePricePerDay;

public:
    Vehicle() : id(""), brand(""), basePricePerDay(0.0) {}
    
    Vehicle(string id, string brand, double price) 
        : id(id), brand(brand), basePricePerDay(price) {}

    // Getters & Setters
    string getId() const { return id; }
    void setId(string id) { this->id = id; }

    string getBrand() const { return brand; }
    void setBrand(string brand) { this->brand = brand; }

    double getBasePricePerDay() const { return basePricePerDay; }
    void setBasePricePerDay(double price) { this->basePricePerDay = price; }

    // 3. Hàm displayInfo()
    virtual void displayInfo() const {
        cout << "Ma xe: " << id << " | Hang: " << brand 
             << " | Don gia/ngay: " << fixed << setprecision(0) << basePricePerDay;
    }

    virtual double calculateRentalFee(int days) const = 0;

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int numberOfSeats;

public:
    Car() : Vehicle(), numberOfSeats(4) {}
    
    Car(string id, string brand, double price, int seats)
        : Vehicle(id, brand, price), numberOfSeats(seats) {}

    int getNumberOfSeats() const { return numberOfSeats; }
    void setNumberOfSeats(int seats) { this->numberOfSeats = seats; }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " | Loai: Oto | So cho: " << numberOfSeats;
    }

    double calculateRentalFee(int days) const override {
        double total = days * getBasePricePerDay();
        if (days >= 7) {
            total *= 0.90; // Giảm 10%
        }
        return total;
    }
};

class Motorbike : public Vehicle {
private:
    int engineCapacity;

public:
    Motorbike() : Vehicle(), engineCapacity(110) {}
    
    Motorbike(string id, string brand, double price, int capacity)
        : Vehicle(id, brand, price), engineCapacity(capacity) {}

    int getEngineCapacity() const { return engineCapacity; }
    void setEngineCapacity(int capacity) { this->engineCapacity = capacity; }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " | Loai: Xe may | Dung tich: " << engineCapacity << "cc";
    }

    double calculateRentalFee(int days) const override {
        double total = days * getBasePricePerDay();
        if (days >= 5) {
            total *= 0.95;
        }
        return total;
    }
};

class Truck : public Vehicle {
private:
    double fixedShippingFee;

public:
    Truck() : Vehicle(), fixedShippingFee(0.0) {}
    
    Truck(string id, string brand, double price, double shippingFee)
        : Vehicle(id, brand, price), fixedShippingFee(shippingFee) {}

    double getFixedShippingFee() const { return fixedShippingFee; }
    void setFixedShippingFee(double fee) { this->fixedShippingFee = fee; }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " | Loai: Xe tai | Phi VC co dinh: " << fixedShippingFee;
    }

    double calculateRentalFee(int days) const override {
        return (days * getBasePricePerDay()) + fixedShippingFee;
    }
};

int main() {
    int rentalDays = 7;

    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("C01", "Toyota", 800000, 5));
    vehicles.push_back(new Motorbike("M01", "Honda", 150000, 125));
    vehicles.push_back(new Truck("T01", "Isuzu", 1200000, 500000));
    vehicles.push_back(new Car("C02", "Mercedes", 2000000, 4));

    cout << "=== DANH SACH PHUONG TIEN & PHI THUE (" << rentalDays << " NGAY) ===" << endl;
    
    double totalRevenue = 0.0;
    Vehicle* maxFeeVehicle = nullptr;
    double maxFee = 0.0;

    for (Vehicle* v : vehicles) {
        v->displayInfo();
        
        double fee = v->calculateRentalFee(rentalDays);
        cout << " => Phi thue: " << fixed << setprecision(0) << fee << " VND" << endl;

        totalRevenue += fee;

        if (maxFeeVehicle == nullptr || fee > maxFee) {
            maxFee = fee;
            maxFeeVehicle = v;
        }
    }

    cout << "\n--------------------------------------------------" << endl;
    cout << "Tong doanh thu thue xe: " << totalRevenue << " VND" << endl;

    if (maxFeeVehicle != nullptr) {
        cout << "\nPhuong tien co phi thue cao nhat:" << endl;
        maxFeeVehicle->displayInfo();
        cout << " => Phi thue: " << maxFee << " VND" << endl;
    }

    for (Vehicle* v : vehicles) {
        delete v;
    }
    vehicles.clear();

    return 0;
}