// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class professor{
    string name;
    string department;
    
    public:
    professor(string n, string d){
        name=n;
        department=d;
    }
    ~professor(){
        cout<<"destructor: professor."<<endl;
    }
    string getname(){
        return name;
    }
    string getdept(){
        return department;
    }
};

class university{
    string name;
    int count;
    professor** ptr;
    
    public:
    university(string n){
        name=n;
        ptr=nullptr;
        count=0;
    }
    ~university(){
        delete[] ptr;
        cout<<"Destructor: university."<<endl;
    }
    
    void addprof(professor* p){
        //allocating new array size:
        professor** newptr=new professor*[count+1];
        
        //copy previous values:
        for(int i=0; i<count;i++){
            newptr[i]=ptr[i];
        }
        
        newptr[count]=p;
        //free old space:
        
        delete[] ptr;
        ptr=newptr;
        
        count++;
        cout<<"professor added successfully!"<<endl;
}
    void display(){
        cout<<"UNIVERSITY DETAILS:\nName: "<<name<<endl;
        cout<<"Professors: "<<endl;
        for (int i=0; i<count; i++){
            cout<<i+1<<":  "<<ptr[i]->getname()<<"\n"<<ptr[i]->getdept()<<endl;
            
        }
    }
    

};

int main(){
    //make 4 professors:
    professor p1("professor 1", "cs");
    professor p2("professor 2", "ai");
    professor p3("professor 3", "se");
    professor p4("professor 4", "ds");
    
    //make two universities:
    university u1("university 1");
    university u2("u2");
    u1.addprof(&p1);
    u2.addprof(&p2);
    u1.addprof(&p3);
    u2.addprof(&p4);
    u1.display();
    u2.display();
    return 0;
}
