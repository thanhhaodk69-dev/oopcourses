
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

};