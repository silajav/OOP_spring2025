// Online C++ compiler to run C++ program online
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    //opening file for adding initial value:
    ofstream file("config.txt");
    if (!file.is_open()){
        cerr<<"file could not be creatred!!"<<endl;
    }
    file<<"AAAAA"<<endl;
    file<<"BBBBB"<<endl;
    file<<"CCCCC"<<endl;
    
    file.close();
    
    //reopen in read/write mode:
    fstream file1("config.txt", ios::in | ios::out);
    if (!file1.is_open()){
        cerr<<"file could not be created!!"<<endl;
    }
    file1.seekp(5);//absolute positioning.
    file1<<"ddddd"<<endl;
    file1.close();
    
    string content;
    ifstream file2("config.txt");
    if (!file2.is_open()){
        cerr<<"file not openening!!!"<<endl;
    }else{
        getline(file2, content, '\0');
        cout<<content<<endl;
        file2.close();
    }
     return 0;
}
