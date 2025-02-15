
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
    
    void update(string title, float price ,int stock){
        this->title=title;
        this->price=price;
        *(this->stock)=stock;
    }
    
    void display(){
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"STOCK LEVELS: "<<*stock<<endl;
        
    }
    
    float pricecalc(int qty){
        float newprice=this->price;
        if (*stock<5){
            newprice=this->price+10.0;//increase price if low in stock.
            cout<<"low in stock so price increased."<<endl;
        }
        if (qty>20){
            newprice=this->price * 0.90;//apply a 10 percent discount if brought in bulk.
            cout<<"A discount of 10% is applied."<<endl;
        }
        return newprice*qty;
    }
    void purchaseDetails(int qty){
        cout<<"Book details: "<<endl;
        display();
        cout<<"order details: "<<endl;
        cout<<"Quantity: "<<qty<<endl;
        cout<<"Total price: "<<pricecalc(qty)<<endl;
    }
    
     
    void simulate(int qty){
        if(qty>*stock){
            cout<<"Stock does not have this many books."<<endl;
            
        }
        else{
            cout<<"buying the book for you..."<<endl;
            *stock -= qty;
            purchaseDetails(qty);
            
        }        
       if (*stock<5){
            cout<<"WARNING!! stock levels low. has reached below 5."<<endl;
        }
        }
    };
    
    
    
int main(){
   book b1;
   b1.update("name", 20.0, 45);
   cout<<"PURCHASE 1:(10 BOOKS) "<<endl;
   b1.simulate(10);
   cout<<"\n\n";
   cout<<"PURCHASE 2: (21 BOOKS) "<<endl;
   b1.simulate(21);//will give 10 percent discount.
   cout<<"\n\n";
   cout<<"PURCHASE 3: (10 MORE BOOKS) "<<endl;
   b1.simulate(10);//will increase price as stock would be low.
   
   
   
   return 0;
   
}    
