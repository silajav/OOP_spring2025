// Online C++ compiler to run C++ program online
#include "iostream"
using namespace std;
class teamug{
    string brand;
    string colour;
    int capacity;
    int currentlevel;
    
    public:
    teamug(string b, string c, int ct, int l){
        brand=b;
        colour=c;
        capacity=ct;
        currentlevel=l;
    }
    void sip(){
        if (currentlevel==0){
            cout<<"You need a new cup of tea."<<endl;
        }else if(currentlevel>0){
            cout<<"sipping.."<<endl;
            currentlevel--;
        }
    }
    
    void refill(){
        currentlevel=capacity;
    }
     void show(){
         cout<<"brand: "<<brand<<endl;
         cout<<"colour: "<<colour<<endl;
         cout<<"capacity: "<<capacity<<endl;
         cout<<"current level: "<<currentlevel<<endl;
     }
};

int main(){
    teamug mug1("abc","pink",10,10);
    teamug mug2("def","black",10,2);
    cout<<"MUG 1: "<<endl;
    mug1.sip();
    mug1.sip();
    mug1.sip();
    mug1.refill();
    mug1.show();
    cout<<"MUG 2: "<<endl;
    mug2.sip();
    mug2.sip();
    mug2.sip();
    return 0;
    
}
