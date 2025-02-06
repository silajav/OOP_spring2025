// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class laptop{
    string brand;
    string model;
    string processor;
    string RAM;
    string storage;
    
    public:
    laptop(string b, string m, string p, string r, string s){
        brand=b;
        model=m;
        processor=p;
        RAM=r;
        storage=s;
    }
    
    void on(){
        cout<<"turning the computer on..."<<endl;
    }
    void off(){
        cout<<"turning the computer off..."<<endl;
    }
    
    void run(){
        cout<<"running program"<<endl;
    }
    
    void check(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"model: "<<model<<endl;
        cout<<"processor: "<<processor<<endl;
        cout<<"RAM: "<<RAM<<endl;
        cout<<"storage: "<<storage<<endl;
    }
};
int main() {
    string b,m,p,r,s;
    cout<<"enter specifications for ayesha's laptop: (all seperated by a space)"<<endl;
    cin>>b>>m>>p>>r>>s;
    laptop Ayesha(b,m,p,r,s);
    cout<<"enter specifications for Bilal's laptop: (all spaces seperated.)"<<endl;
    cin>>b>>m>>p>>r>>s;
    laptop Bilal(b,m,p,r,s);
    cout<<"COMPARISON: "<<endl;
    cout<<"Bilal's laptop: "<<endl;
    Bilal.check();
    cout<<"Ayesha's laptop: "<<endl;
    Ayesha.check();
