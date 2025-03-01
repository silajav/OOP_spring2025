#include <iostream>
using namespace std;

class guide{
    string name;
    string expyears;
    string specialisation;
    
    public:
    guide(string n, string e, string s): name(n), expyears(e), specialisation(s){}
    ~guide(){
        cout<<"destructor: guide."<<endl;
    }
    string getname(){
        return name;
    }
    string getexp(){
        return expyears;
    }
    string getspecialisation(){
        return specialisation;
    }
};

class agency{
    guide** list;
    int count;
    public:
    agency(){
        
        list=nullptr;
        count=0;
    }
    ~agency(){
        delete[] list;
        cout<<"Destructor: agency."<<endl;
    }
    
    void add(guide* g){
        //allocating new array size:
        guide** newlist=new guide*[count+1];
        
        //copy previous values:
        for(int i=0; i<count;i++){
            newlist[i]=list[i];
        }
        
        newlist[count]=g;
        //free old space:
        
        if (list != nullptr) delete[] list;
        
        list=newlist;
        
        count++;
        cout<<"guide added successfully!"<<endl;
}
    void display(){
        cout<<"AGENCY DETAILS:\n";
        cout<<"Guides: "<<endl;
        for (int i=0; i<count; i++){
            cout<<i+1<<":  "<<list[i]->getname()<<"\n"<<list[i]->getexp()<<list[i]->getspecialisation()<<endl;
            
        }
    }
};

int main(){
    //make 4 guides:
    guide g1("guide 1", "8","skemdbfe");
    guide g2("guide 2", "6", "dekd");
    guide g3("guide 3", "3", "dwehjb");
    guide g4("guide 4", "4", "ewduei");
    
    //make an agency:
    agency a;
    a.add(&g1);
    a.add(&g2);
    a.add(&g3);
    a.add(&g4);
    a.display();
    return 0;
}
