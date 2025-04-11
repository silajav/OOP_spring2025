#include <iostream>
using namespace std;

class Teacher;

class Student {
    string n;
    int g[3];
public:
    Student(string x, int a, int b, int c) : n(x) {
        g[0] = a;
        g[1] = b;
        g[2] = c;
    }
    friend class Teacher;
    friend float calculateAverageGrade(Student s);
};

class Teacher {
public:
    void show(Student s) {
        cout << "Name: " << s.n << endl;
        for (int i = 0; i < 3; i++)
            cout << "Grade " << i+1 << ": " << s.g[i] << endl;
    }
    void update(Student &s, int i, int val) {
        s.g[i] = val;
    }
};

float calculateAverageGrade(Student s) {
    float sum = 0;
    for (int i = 0; i < 3; i++)
        sum += s.g[i];
    return sum / 3;
}

int main() {
    Student s("Ali", 85, 90, 80);
    Teacher t;
    t.show(s);
    cout << "Average: " << calculateAverageGrade(s) << endl;
    t.update(s, 1, 95);
    t.show(s);
    cout << "New Average: " << calculateAverageGrade(s) << endl;
}
