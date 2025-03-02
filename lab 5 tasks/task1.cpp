#include "iostream"
using namespace std;

class car{
    string rnum;
    string owner;
    string model;
    
    public:
    car(string num, string o, string m){
        rnum=num;
        owner=o;
        model=m;
    }
    
    ~car(){
        cout<<"destructor : car"<<endl;
    }
    
    car(const car &obj, string o){
        rnum=obj.rnum;
        owner=o;
        model=obj.model;
    }
    
    void display(){
        cout<<"CAR DETAILS: "<<endl;
        cout<<"registeration number: "<<rnum<<"\nowner: "<<owner<<"\nmodel: "<<model<<endl;
    }
    void update(string m, string o, string id){
        rnum=id;
        model=m;
        owner=o;
    }
    
};

int main(){
    //original object:
    car c1("123", "mr james", "2004");
    car c2(c1, "mr charles");
    cout<<"object 1: "<<endl;
    c1.display();
    cout<<"object two: "<<endl;
    c2.display();
    cout<<"checking if changing c1 changes c2: "<<endl;
    c1.update("2006", "mrs julie", "345");
    cout<<"c2 after updating c1: "<<endl;
    c2.display();
    
    cout<<"changing c2: "<<endl;
    c2.update("2013", "mr henry", "276");
    c2.display();
    
}
