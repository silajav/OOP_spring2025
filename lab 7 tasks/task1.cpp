#include "iostream"
using namespace std;

class account{
    protected:
    string accNum;
    string accholdername;
    string accountType;
    float balance;
    
    public:
    account(string n, string h, float b):accNum(n), accholdername(h), balance(b){
        accountType=" ";
    }
    
    void desposit(float a){
        balance+=a;
    }
    
    void withdraw(float a){
        if (balance>=a){
            balance-=a;
            cout<<"Amount successfully withdrawn!!\nRemaining balance: "<<balance<<endl;
        }
        else{
            cout<<"not enough funds to withdraw."<<endl;
        }
    }
    ~account(){
        cout<<"destructor of account class."<<endl;
    }
    virtual void calculateInterest(int sum){
        cout<<"No interest applied."<<endl;
    }
    
    
    float getbal(){
        return balance;
    }
    
    string getaccountnum(){
        return accNum;
    }
    
    string getaccHoldername(){
        return accholdername;
    }
    
    string getacctype(){
        return accountType;
    }
    
    void setaccounttype(string s){
        accountType=s;
    }
    
    virtual void printStatement(){
    cout << "Account Holder: " <<accholdername<< endl;
    cout << "Account Number: " <<accNum<< endl;
    cout << "Account Type: " <<accountType<< endl;
    cout << "Balance: " <<balance<< endl;
}

};

class savings: public account{
    float interestRate;
    float minbal;
    
    public:
    savings(string n, string h, float b, float r, float min):account(n,h,b),interestRate(r), minbal(min) {
        account::setaccounttype("savings");
    }
    
    ~savings(){
        cout<<"destructor: savings class."<<endl;
    }
    
     void calculateInterest(int sum) override{
        float b;
        b=interestRate * sum;
        cout<<"interest amount: "<<b<<endl;
    }
   
   void printStatement() override{
       account::printStatement();
       cout<<"Interestrate: "<<interestRate<<endl;
   }
};

class fixedDeposit:public account{
    string maturityDate;
    float fixedInterest;
    
    public:
    fixedDeposit(string n, string h, float b, string d, float i):account(n,h,b), maturityDate(d), fixedInterest(i){
        
        account::setaccounttype("Fixed desposit account");
    }
    
    ~fixedDeposit(){
        cout<<"destructor: fixed deposit class."<<endl;
    }
    
    void calculateInterest(int sum) override{
        float b;
        b=fixedInterest * sum;
        cout<<"interest amount: "<<b<<endl;
    }
    
     void printStatement() override{
       account::printStatement();
       cout<<"Fixed Interest Rate: "<<fixedInterest<<endl;
       cout<<"maturity Date: "<<maturityDate<<endl;
   }
};

int main(){
    account* a;
    account* a2;
    savings s("num", "name", 350.0, 2, 20.0);
    fixedDeposit d("num fixed deposit","name fixed deposit", 760.2, "26th jan", 3.0);
    a=&s;
    a2=&d;
    cout<<"savings account: "<<endl;
    a->calculateInterest(30); //calls this function for the savings account class.
    a->printStatement();
    
    
    cout<<"\n\nfixed deposit account: "<<endl;
    a2->calculateInterest(30); //calls this function for the fixed deposit class.
    
    a2->printStatement();
}
