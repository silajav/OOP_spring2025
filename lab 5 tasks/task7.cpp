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
    int count;

public:
    Inventory(int maxSize) {
        capacity = maxSize;
        count = 0;
        items = new Product*[capacity];
    }

    ~Inventory() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
        delete[] items;
    }

    void add(int id, string name, double price) {
        if (count < capacity) {
            items[count++] = new Product(id, name, price);
            cout << "Added!" << endl;
        } else {
            cout << "Full!" << endl;
        }
    }

    void showAll() {
        if (count == 0) {
            cout << "Empty." << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            items[i]->show();
        }
    }

    void sortByPrice() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (items[i]->price > items[j]->price) {
                    swap(items[i], items[j]);
                }
            }
        }
        cout << "Sorted." << endl;
    }

    void find(string pname) {
        for (int i = 0; i < count; i++) {
            if (items[i]->name == pname) {
                cout << "Found:" << endl;
                items[i]->show();
                return;
            }
        }
        cout << "Not found." << endl;
    }
};

int main() {
    Inventory store(5);

    store.add(101, "Laptop", 1200.50);
    store.add(102, "T-Shirt", 20.99);
    store.add(103, "Apple", 1.99);

    cout << endl << "Inventory:" << endl;
    store.showAll();

    cout << endl << "Sorting..." << endl;
    store.sortByPrice();
    store.showAll();

    cout << endl << "Searching for 'T-Shirt'..." << endl;
    store.find("T-Shirt");

    return 0;
}
