#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException: Number is negative.";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException: Type is not numeric.";
    }
};

template <typename T>
double computeSqrt(T num) {
    if (typeid(num) != typeid(int) && typeid(num) != typeid(double)) {
        throw InvalidTypeException();
    }

    if (num < 0) {
        throw NegativeNumberException();
    }

    return sqrt(num);
}

int main() {
    try {
        cout << "sqrt(-4): ";
        cout << computeSqrt(-4) << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): ";
        cout << computeSqrt(string("hello")) << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(25): ";
        cout << computeSqrt(25) << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
