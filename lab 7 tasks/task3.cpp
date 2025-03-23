#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    double rate;
    string code;
    
public:
    Currency(double amt, double r, string c) : amount(amt), rate(r), code(c) {}
    virtual ~Currency() {}
    
    double toBase() {
        return amount * rate;
    }
    
    double convertTo(Currency &target) {
        double baseAmt = toBase();
        return baseAmt / target.rate;
    }
    
    virtual void show() {
        cout << code << " " << amount << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, 1.0, "$") {}
    void show() override {
        cout << "$" << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, 1.1, "€") {}
    void show() override {
        cout << amount << " €" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, 0.012, "₹") {}
    void show() override {
        cout << "₹" << amount << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(0);
    Rupee r(0);
    
    double eurAmt = d.convertTo(e);
    double inrAmt = d.convertTo(r);
    
    Euro convertedEur(eurAmt);
    Rupee convertedInr(inrAmt);
    
    d.show();
    convertedEur.show();
    convertedInr.show();
    
    return 0;
}

