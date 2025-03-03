#include "iostream"
using namespace std;

class employee{
    protected:
    string name;
    float salary;
    
    public:
    employee(string n, float s): name(n), salary(s){}
     
    void displaydetails(){
        cout<<"name: "<<name<<endl;
        cout<<"salary: "<<salary<<endl;
    }
};

class manager: public employee{
    protected:
    float bonus;
    
    public:
    manager(string n, float s, float b): employee(n,s), bonus(b){}
    void displaydetails(){
        employee::displaydetails();
        cout<<"bonus: "<<bonus<<endl;
    }
};

int main(){
    manager m("mr charles", 245.0, 23.0);
    m.displaydetails();
    return 0;
}


 
