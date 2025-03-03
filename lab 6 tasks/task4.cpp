#include "iostream"
using namespace std;

class account{
    protected:
    int num;
    float balance;
    
    public:
    account(int n, float b):num(n), balance(b){}
    
    void displaydetails(){
        cout<<"account number: "<<num<<endl;
        cout<<"balance: "<<balance<<endl;
    }
};

class savings: public account{
    protected:
    float interest;
    
    public:
    savings(int n, float b, float i): account(n,b),interest(i){}
    
    void displaydetails(){
        account::displaydetails();
        cout<<"interest rate: "<<interest<<endl;
    }
};

class checking: public account{
    protected:
    float limit;
    
    public:
    checking(int n, float b, float l): account(n,b),limit(l){}
    
    void displaydetails(){
        account::displaydetails();
        cout<<"over draft limit: "<<limit<<endl;
    }
};

int main(){
    int num;
    float balance;
    float temp;
    int choice;
    cout<<"Do you want a savings account or checkings account? (1 for savings and 2 for checkings: "<<endl;
    cin>>choice;
    cout<<"enter number of account: "<<endl;
    cin>>num;
    cout<<"enter balance: "<<endl;
    cin>>balance;
    if (choice==1){
        cout<<"enter interest rate: "<<endl;
        cin>>temp;
        savings s(num,balance,temp);
         cout<<"The saving account details are as follows: "<<endl;
        s.displaydetails();
    }
    else if (choice==2){
        cout<<"enter over draft limit: "<<endl;
        cin>>temp;
        checking c(num, balance, temp);
        cout<<"The checking account details are as follows: "<<endl;
        c.displaydetails();
    }
    else{
        cout<<"invalid choice entered. exiting..."<<endl;
    }
    return 0;
}
