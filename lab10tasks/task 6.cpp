#include <iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

class inventory{
    int id;
    char name[50];
    public:
    inventory(int i, const char n[]):id(i){
        {
          strcpy(name,n,sizeof(name));
          name[sizeof(name)-1]='\0';
        }
    }
};
int main(){
    char n[]={'s','h','o','p'};
    inventory i(2, n);
    
    ostream file("inventory.dat", ios::binary);
    if(!file.is_open()){
        cout<<"unable to open file!!"<<endl; 
        return 1;
    }
    
    file.write((char*)&i, sizeof(i));
    file.close();
    
    
    istream file("inventory.dat", ios::binary);
    if (!file.is_open()){
        cout<<"unable to open file!!"<<endl;
    }
    file.read((char*)&i, sizeof(i));
}

    file.close();
