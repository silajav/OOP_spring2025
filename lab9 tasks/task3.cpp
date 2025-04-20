#include <iostream>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCard(string num) {
        cardNumber = num;
    }

    void processPayment(double amount) {
        cout << "CreditCard payment: " << amount << " with " << cardNumber << endl;
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;
public:
    DigitalWallet(double b) {
        balance = b;
    }

    void processPayment(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Wallet payment: " << amount << ", left: " << balance << endl;
        } else {
            cout << "no balance lol" << endl;
        }
    }
};

int main() {
    CreditCard cc("1111-2222");
    cc.processPayment(100);

    DigitalWallet dw(150);
    dw.processPayment(50);
    dw.processPayment(200);

    return 0;
}
