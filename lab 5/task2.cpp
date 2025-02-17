#include "iostream"
using namespace std;

class patient{
    int id;
    string name;
    int *ptr=new int[5];
    
    public:
    patient(int i, string n){
        id=i;
        name=n;
    }
    void addTests(){
        for (int i=0; i<5; i++) {
            cout<<"enter the results of test "<<i+1<<endl;
            cin>>ptr[i];
        }
    }
    
    patient(const patient& obj){
        id=obj.id;
        name=obj.name;
        ptr=new int[5];
        for (int i=0; i<5; i++){
           ptr[i]=obj.ptr[i];
        }
    }    
    
    
    void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        for (int i=0; i<5; i++){
            cout<<"results for Test "<<i+1<<": "<<ptr[i+1]<<endl;
            
        }
    }
    
    ~patient(){
        cout<<"destructor called"<<endl;
        delete[] ptr;
    }
};

int main(){
    patient obj1(1,"abc");
    obj1.addTests();
    cout<<"OBJECT 1: "<<endl;
    obj1.display();
    patient obj2(obj1);
    obj2.addTests();
    cout<<"OBJECT 2: "<<endl;
    obj2.display();
    
    
}
