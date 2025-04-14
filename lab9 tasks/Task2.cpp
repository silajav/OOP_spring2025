
#include <iostream>
using namespace std;

class smartdevice{
    public:
    virtual void turnoff()=0;
    virtual void turnon()=0;
    virtual bool getstatus()=0;
};

class lightbulb: public smartdevice{
    protected:
    bool ison;
    int brightness;
    
    public:
    lightbulb():ison(0), brightness(0){}//default values.
    
    void turnoff() override{
        cout<<"Turning off lightbulb.."<<endl;
        ison=0;
    }
    
    void turnon() override{
        cout<<"Turning on lightbulb..."<<endl;
        ison=1;
    }
    
    bool getstatus() override{
        return ison;
    }
};

class Thermostat: public smartdevice{
    protected:
    bool ison;
    double temperature;
    
    public:
    Thermostat():ison(0), temperature(0){}
    void turnoff() override{
        cout<<"turning off thermostat..."<<endl;
        ison=0;
    }
    
    void turnon() override{
        cout<<"turning on thermostat..."<<endl;
        ison=1;
    }
    
    bool getstatus() override{
        return ison;
    }
};


int main() {
    lightbulb l;
    Thermostat t;
    smartdevice* s1=&l;
    smartdevice* s2=&t;
    s1->turnon();
    s1->turnoff();
    s2->turnon();
    s2->turnoff();
    return 0;
}
