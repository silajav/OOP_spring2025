#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    ofstream file("log.txt", ios::append);
    if (file.is_open()){
        for (int i=0; i<19;i++){
            file<<"filee"<<endl;
        }
    }else{
        cerr<<"file not created!!---error-----"<<endl;
    }
    
    char buffer[11]={0};
    ifstream file1("log.txt");
    if (!file2.is_open()){
        cout<<"----error----"<<endl;
    }
    file2.read(buffer,10);
    streampos pos=file2.tellg();
    cout<<"first 10 bytes"<<pos<<endl;
    file2.read(buffer,10);
    pos=file2.tellg();
    cout<<"second 10 bytes: "<<pos<<endl;
    return 0;
}
