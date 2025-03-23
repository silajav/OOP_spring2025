#include <iostream>
using namespace std;

class Person {
protected:
    string name, address, phone, email;
    int id;
public:
    Person(string n, int i, string a, string p, string e) : name(n), id(i), address(a), phone(p), email(e) {}

    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id << endl;
    }

    virtual ~Person() {}  // Virtual destructor for proper cleanup
};

class Student : public Person {
    int coursesEnrolled;
    float gpa;
    int enrollmentYear;
public:
    Student(string n, int i, string a, string p, string e, int c, float g, int y)
        : Person(n, i, a, p, e), coursesEnrolled(c), gpa(g), enrollmentYear(y) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses: " << coursesEnrolled << " | GPA: " << gpa << " | Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
    string department;
    int coursesTaught;
    float salary;
public:
    Professor(string n, int i, string a, string p, string e, string d, int c, float s)
        : Person(n, i, a, p, e), department(d), coursesTaught(c), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Courses: " << coursesTaught << " | Salary: " << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    float salary;
public:
    Staff(string n, int i, string a, string p, string e, string d, string pos, float s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Position: " << position << " | Salary: " << salary << endl;
    }
};

class Course {
    int courseId, credits;
    string courseName, instructor, schedule;
public:
    Course(int id, string name, int c, string inst, string sch)
        : courseId(id), courseName(name), credits(c), instructor(inst), schedule(sch) {}

    void registerStudent(Student &s) {
        cout << "Registering student: " << endl;
        s.displayInfo();  // Call the function instead of using `cout << s.displayInfo();`
        cout << "Registered in course: " << courseName << endl;
    }
};

int main() {
    Student s("Alice", 101, "123 Street", "9876543210", "alice@mail.com", 5, 3.8, 2022);
    Professor p("Dr. Bob", 201, "456 Lane", "1234567890", "bob@mail.com", "CS", 3, 70000);
    Staff st("Charlie", 301, "789 Avenue", "1112223333", "charlie@mail.com", "Admin", "Manager", 50000);
    Course c(1, "OOP", 3, "Dr. Bob", "MWF 10AM");
    
    cout << "\n=== Displaying Information ===\n";
    s.displayInfo();
    p.displayInfo();
    st.displayInfo();

    cout << "\n=== Registering Student for Course ===\n";
    c.registerStudent(s);

    return 0;
}
