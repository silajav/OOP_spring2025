// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class battery{
    string capacity;
    public:
    battery(string m){
        capacity=m;
    }
    
    battery(){
        capacity="unknown";
    }
    ~battery(){
        cout<<"battery destructor."<<endl;
    }
    string getcapacity(){
        return capacity;
    }
    void setcapacity(string c){
        capacity=c;
    }
};

class smartphone{
    string model;
    string brand;
    battery battery1;
    
    public:
    smartphone(string m, string b, string c){
        model=m;
        brand=b;
        battery1.setcapacity(c);
    }
    
    void displayphone(){
        cout<<"Phone details: "<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"capacity of battery: "<<battery1.getcapacity()<<endl;
    }
};

int main(){
    smartphone s1("123", "samsung", "30");
    smartphone s2("456", "iphone", "45");
    s1.displayphone();
    s2.displayphone();
    return 0;
}
