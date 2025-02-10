#include "iostream"
using namespace std;

class book{
    string title;
    float price;
    int *stock= new int;
    
    public:
    book(){
        title="unknown";
        price=0.0;
        *stock=30;
    }
    
    void update(string t, float p,int s){
        title=t;
        price=p;
        *stock=s;
    }
    
    void displayStock(){
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"STOCK LEVELS: "<<endl;
        cout<<*stock;
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
    int qty;
    book b;
    b.update("harry potter", 3.00,25);
    cout<<"initial stock levels before purchase: "<<endl;
    b.displayStock();
    cout<<"\n";
    cout<<"enter how many books you want to purchase: ";
    cin>>qty;
    cout<<"purchase 1 "<<endl;
    b.simulate(qty);
    cout<<"purchase 2 "<<endl;
    b.simulate(20);
    cout<<"purchase 3 "<<endl;
    b.simulate(5);
    cout<<"stock after purchase: "<<endl;
    b.displayStock();
    return 0;
}    
