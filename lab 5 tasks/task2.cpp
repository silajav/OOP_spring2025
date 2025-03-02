#include "iostream"
using namespace std;

class patient{
    int id;
    string name;
    string array[10];//max set to 10;
    int count;
    
    public:
    patient(int i, string n){
        id=i;
        name=n;
        count=0;
    }
    
    ~patient(){
        cout<<"destructor: patient class."<<endl;
    }
    
    patient(){
        cout<<"default constructor called."<<endl;
        id=0;
        name="unknown";
        count=0;
    }
    void addtests(string t){
        array[count]=t;
        count++;
    }
        
    
    
    //copy constructor:
    patient(const patient &obj){
        id=obj.id;
        name=obj.name;
        count=0;
    }
    
    void display(){
        cout<<"patient details: "<<endl;
        cout<<"Id: "<<id<<"\nName: "<<name<<endl;
        for (int i=0; i<count; i++){
            cout<<i+1<<": "<<array[i]<<endl;
        }
    }
};

int main(){
    patient p(1, "sam");
    p.addtests("positive");
    p.addtests("increased blood pressure.");
    p.addtests("high cholestrol");
    p.addtests("corona negative.");
    cout<<"patient record: "<<endl;
    p.display();
    patient p_updated(p);
    p_updated.addtests("negative");;
    p_updated.addtests("heart rate better");
    p_updated.addtests("low sugar");
    cout<<"other tests ran on the same patient: "<<endl;
    p_updated.display();
    return 0;
}
