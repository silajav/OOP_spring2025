#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    string input;
    ofstream file("data.txt");
    if (!file.is_open()){
        cerr<<"----error----"<<endl;
    }else{
        for (int i=0; i<5; i++){
            cout<<"---enter input---: "<<endl;
            cin>>input;
            file<<input<<endl;
        }
        
    file.close();
    
    ifstream filee("data.txt");
    if (!file.is_open()){
        cerr<<"---error2----"<<endl;
    }
    filee.seekg(0);
    size_t length=0;
    string line;
    for(int i=0; i<2; i++){
        getline(filee, line, '\n');
        length+=line.length()+1; //plus 1 for the newline character.
    }
    
    filee.seekg(length);
    getline(filee,line, '\n');
    cout<<line<<endl;
    filee.close();    
    }
    return 0;
}
