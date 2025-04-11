#include <iostream>
using namespace std;

class F {
    int n, d;
public:
    F(int a, int b) : n(a), d(b) {}
    
    F operator+(F x) {
        return F(n * x.d + x.n * d, d * x.d);
    }
    F operator-(F x) {
        return F(n * x.d - x.n * d, d * x.d);
    }
    F operator*(F x) {
        return F(n * x.n, d * x.d);
    }
    F operator/(F x) {
        return F(n * x.d, d * x.n);
    }
    friend ostream& operator<<(ostream& o, F x) {
        return o << x.n << "/" << x.d;
    }
};

int main() {
    F a
