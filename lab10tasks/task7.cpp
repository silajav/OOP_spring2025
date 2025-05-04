// Online C++ compiler to run C++ program online
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
    ofstream file("sensor_log.txt", ios::binary);
    if (!file.is_open()){
        cerr<<"file not created!!"<<endl;
    }
    string name="abcd";
    string name2="defg";
    string name3="fijk";
    file<<name<<endl;
    file<<name2<<endl;
  
    streampos pos=file.tellp();
    cout<<"after two bytes addition: "<<pos<<endl;
    
    file<<name3<<endl;
    pos=file.tellp();
    cout<<"after the third byte: "<<pos<<endl;
    
    file.close();

    return 0;
}
