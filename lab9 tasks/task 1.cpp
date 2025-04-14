
#include <iostream>
using namespace std;

class vehicle{
    protected:
    string model;
    double rate;
    
    public:
    vehicle(string m, double r): model(m), rate(r){}
    
    virtual double getDailyRate()=0;
    
    virtual void display()=0;
    
    
    
};

class car: public vehicle{
    public:
    car(string m, double r):vehicle(m,r){}
    
    double getDailyRate() override{
        return rate;
    }
    
    void display() override{
        cout<<"MODEL OF THE CAR IS : "<<model<<endl;
        cout<<"RATE FOR THIS CAR: "<<rate<<endl;
    }
};

class bike:public vehicle{
    public:
    bike(string m, double r):vehicle(m,r){}
    
    double getDailyRate() override{
        return rate;
    }
    
    void display() override{
        cout<<"MODEL OF THIS BIKE IS: "<<model<<endl;
        cout<<"RATE FOR THIS BIKE: "<<rate<<endl;
    }
};

int main() {
   car c("2005", 340);
   bike b("2007", 230);
   vehicle* v1=&c;
   vehicle* v2=&b;
   cout<<"car's rate: "<<v1->getDailyRate()<<endl;
   cout<<"\nbike's rate: "<<v2->getDailyRate()<<endl;
   cout<<"\n\n";
   v1->display();
   cout<<"\n\n";
   v2->display();
    return 0;
}
