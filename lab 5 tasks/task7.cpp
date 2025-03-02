#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    double price;

    Product(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }

    void show() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

class Inventory {
    Product** items;
    int capacity;
    int cou
