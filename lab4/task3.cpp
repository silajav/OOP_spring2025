#include "iostream"
using namespace std;

class book{
    string title;
    float price;
    int *stock= new int;
    
    public:
    //deep copying:
    book(const book &obj){
        title=obj.title;
        price=obj.price;
        //allocate new memory for stock:
        stock=new int(*obj.stock);
    }
    book(){
        title="unknown";
        price=0.0;
        *stock=30;
    }
    ~book(){
        delete stock;
        cout<<"destructor called."<<endl;
    }
    
    void update(string t, float p,int s){
        title=t;
        price=p;
        *stock=s;
    }
    
    void display(){
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"STOCK LEVELS: "<<*stock<<endl;
        
    }
    
    void simulate(int qty){
        if(qty>*stock){
            cout<<"Stock does not have this many books."<<endl;
            
        }
        else{
            cout<<"buying the book for you..."<<endl;
            *stock -= qty;
        }        
       if (*stock<5){
            cout<<"WARNING!! stock levels low. has reached below 5."<<endl;
        }
        }
    };
    
int main(){
   //object 1:
   book obj1;
   obj1.update("harry potter", 23.0, 20);
   //obj 2:
   book obj2=obj1;
   cout<<"Before modyfing object 1: "<<endl;
   cout<<"Object 1: "<<endl;
   obj1.display();
   cout<<"Object 2: "<<endl;
   obj2.display();
   obj1.update("Never lie", 30, 24);
   cout<<"After modifying object 1: "<<endl;
   cout<<"Object 1: "<<endl;
   obj1.display();
   obj2.display();
   //destructor will be called automatically for both the objects. first object 2 then 1.
   
   return 0;
   
}    
