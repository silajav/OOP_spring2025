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
    book(string t, float p, int s){
        title=t;
        price=p;
        *stock=s;
    }
    
    float applyDiscount(int qty){
        if (qty>10){
            cout<<"You got a 10% discount!!"<<endl;
            return (0.90 * price);
        }
        else if (qty>5){
            cout<<"You got a 5% discount!!"<<endl;
            return (0.95 * price);
        }
        else{
            return price;
        }
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
            cout<<"You are trying to exceed the stock level. we donot have this quantity of books available."<<endl;
            cout<<"Max books available are : "<<*stock<<endl;
        }
        else{
            cout<<"buying the book for you..."<<endl;
            *stock -= qty;
            cout<<"The amount of this purchase is: "<<applyDiscount(qty)<<endl;
        }        
       if (*stock<5){
            cout<<"WARNING!! stock levels low. has reached below 5."<<endl;
        }
        }
    };
    
int main(){
    int qty;
    book b("harry potter", 23.0, 20);
    cout<<"initial stock levels before purchase: "<<endl;
    b.displayStock();
    cout<<"\n";
    cout<<"purchase 1: "<<endl;
    cout<<"enter how many books you want to purchase: ";
    cin>>qty;
    b.simulate(qty);
    cout<<"purchase 2: "<<endl;
    cout<<"enter qty: "<<endl;
    cin>>qty;
    b.simulate(qty);
    cout<<"stock after purchase: "<<endl;
    b.displayStock();
    return 0;
}    
