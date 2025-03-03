#include "iostream"
using namespace std;


class person{
    protected:
    string name;
    int age;
    
    public:
    person(string n, int a):name(n),age(a){}
    
    void displaydetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class teacher:public person{
    protected:
    string subject;
    
    public:
    teacher(string n, int a, string s):person(n,a), subject(s){}
    
    void displaydetails(){
        person::displaydetails();
        cout<<"subject: "<<subject<<endl;
    }
};

class researcher:public teacher{
    protected:
    string researcharea;
    public:
    researcher(string n, int a, string s, string r):teacher(n,a,s),researcharea(r){}
    
    void displaydetails(){
        teacher::displaydetails();
        cout<<"research area: "<<researcharea<<endl;
    }
};

class professor:public researcher{
    protected:
    int publications;
    
    public:
    professor(string n, int a, string s, string r, int p): researcher(n,a,s,r), publications(p){}
    
    void displaydetails(){
        researcher::displaydetails();
        cout<<"publications: "<<publications<<endl;
    }
};

int main(){
    professor p("mr ahmad", 52, "physics", "string theory",3);
    p.displaydetails();
    return 0;
}
