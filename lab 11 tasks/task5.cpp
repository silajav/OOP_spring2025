#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class InsufficientFundsException : public exception {
private:
    string message;

public:
    InsufficientFundsException(double deficit) {
        stringstream ss;
        ss << "Insufficient funds. Deficit: $" << deficit;
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initialBalance) {
        balance = initialBalance;
    }

    void withdraw(T amount) {
        if (amount > balance) {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
    }

    T getBalance() {
        return balance;
    }
};

int main() {
    BankAccount<double> account(500.00);
    cout << "Balance: $" << account.getBalance() << endl;

    try {
        account.withdraw(600.00);
    } catch (const InsufficientFundsException& ex) {
        cout << "Withdraw $600: " << ex.what() << endl;
    }

    return 0;
}
