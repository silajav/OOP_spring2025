#include <iostream>
using namespace std;

class Librarian;

class Book {
    string t;
    float p;
public:
    Book(string x, float y) : t(x), p(y) {}
    friend class Librarian;
};

class Librarian {
public:
    void show(Book b) {
        cout << "Title: " << b.t << endl;
        cout << "Price: " << b.p << endl;
    }
    void discount(Book &b, float d) {
        b.p = b.p - (b.p * d / 100);
    }
};

int main() {
    Book b("C++ Basics", 500);
    Librarian l;
    l.show(b);
    l.discount(b, 20);
    l.show(b);
}
