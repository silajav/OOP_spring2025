// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


class vehicle{
    protected:
    string brand;
    int speed;
    
    public:
    vehicle(string b, int s): brand(b), speed(s){}
    
    void displaydetails(){
        cout<<"brand: "<<brand<<endl;
        cout<<"speed: "<<speed<<endl;
    }
};

class car: public vehicle{
    protected:
    int seats;
    
    public:
    car(string b, int s, int seats): vehicle(b,s), seats(seats){}
    
    void displaydetails(){
        vehicle::displaydetails();
        cout<<"number of seats: "<<seats<<endl;
    }
};

class electriccar:public car{
    protected:
    int blife;
    
    public:
    electriccar(string b, int s, int seats, int life):car(b,s,seats), blife(life){}
    void displaydetails(){
        car::displaydetails();
        cout<<"battery life: "<<blife<<endl;
    }
    
};

int main(){
    electriccar speedo("abc",100,4,20);
    speedo.displaydetails();
    return 0;
}
