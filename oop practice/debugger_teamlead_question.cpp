#include "iostream"
using namespace std;


enum debug{
    manual,
    autodebugger,
};

enum develop{
    frontend,
    backend,
};

class employee{
    string name;
    int age;
    string date;
    
    public:
    employee(string n, int a, string d): name(n), age(a), date(d){}
    
    void display(){
        cout<<"name: "<<name<<"\nage: "<<age<<"\ndate: "<<date<<endl;
    }
    
    string getname(){
        return name;
    }
    string getdate(){
        return date;
    };
    
    int getage(){
        return age;
    };
    
    void setage(int a){
        age=a;
    }
    void setname(string n){
        name=n;
    }
    
    void setdate(string d){
        date=d;
    }
};

class debugger:virtual public employee{
    debug role;
    
    public:
    debugger(string n, int a, string d, debug r): employee(n,a,d), role(r){}
    
    void display(){
        employee::display();
        cout<<"Role(debugger): "<<(role==autodebugger?"auto debugger": "manual debugger")<<endl;
    }
    
};

class developer: virtual public employee{
    develop role;
    public:
    developer(string n, int a, string d,develop r): employee(n,a,d), role(r){}
    
    void display(){
        employee::display();
        cout<<"Role(developer): "<<(role==frontend? "frontend": "backend")<<endl;
    }
};

class teamlead: public debugger, public developer{
    public:
    teamlead(string n, int a, string d, debug r, develop role): employee(n,a,d), debugger(n,a,d,r), developer(n,a,d,role){}
    void display(){
        cout<<"Team lead: "<<endl;
        employee::display();
        
    }
};

int main(){
    teamlead leader("mr james",35, "23-05-2009", autodebugger,frontend);
    leader.display();
    return 0;
}
