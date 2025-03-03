#include "iostream"
using namespace std;

class device{
    protected:
    int id;
    bool status;
    
    public:
    device(int i, bool s): id(i), status(s){}
    
    void displaydetails(){
        cout<<"device id: "<<id<<endl;
        cout<<"status: "<<status<<endl;
    }
};

class smartphone: virtual public device{
    protected:
    float size;
    
    public:
    smartphone(int i, bool s, float size):device(i,s),size(size){}
    void displaydetails(){
        device::displaydetails();
        cout<<"screen size: "<<size<<endl;
    }
};

class smartwatch: virtual public device{
    protected:
    bool monitor;
    public:
    smartwatch(int i, bool s, bool m): device(i,s),monitor(m){}
    void displaydetails(){
        device::displaydetails();
        cout<<"heart rate monitor: "<<monitor<<endl;
    }
};

class wearable: public smartphone, public smartwatch{
    protected:
    int counter;
    
    public:
    wearable(int i, bool s, float size, bool m, int c):device(i,s), smartphone(i,s,size), smartwatch(i,s,m), counter(c){}
    
    void displaydetails(){
        device::displaydetails();
        cout<<"step counter: "<<counter<<endl;
    }
    
};

int main(){
    wearable w(12,1,7,0,1);
    w.displaydetails();
    return 0;
}
