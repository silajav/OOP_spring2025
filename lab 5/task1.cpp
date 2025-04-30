// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#this is a comment
class car{
    int num;//registration number.
    string model;
    string owner;
     public:
     car(int n, string m, string o){
         num=n;
         model=m;
         owner=o;
     }
#this is a comment
     car(car& obj, string str){
         //the rest of the details are the same.
         num=obj.num;
         model=obj.model;
         owner=str;
     }
     void display(){
         cout<<"Registration number: "<<num<<endl;
         cout<<"Model: "<<model<<endl;
         cout<<"Owner: "<<owner<<endl;
     }
     
};

int main(){
    //first object:
    car obj1(1, "abc", "sil");
    //second object:
    car obj2(obj1, "def");
    obj1.display();
    obj2.display();
}
