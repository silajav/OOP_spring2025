#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    ifstream file("vehicles.txt");
    string line;
    
    if (!file.is_open()){
        cout<<"file not found!\n";
        return 1;
        }
    
     while (getline(file, line)){
         if (line.empty() || line[0]=='#'){
             continue;
         }
         istringstream iss(line);
         string word;
         string extraData;
         string name;
         int index=0;
         
         //extract the name and extradata from the line.
         while (getline(iss, word, ',')){
             if (index==0){
                 name=word;
             }else if (index==4){
                 extraData=word;
             }
             index++;
         }
         
         if (name=="Autonomous Car"){
             size_t num=extraData.find(':');
             string newstring=extraData.substr(num+1);
             float sw=stof(newstring);
             cout<<"(float) software version: "<<sw<<endl;
         }else if (name=="Electric vehicle"){
             size_t num=extraData.find(':');
             string newstring=extraData.substr(num+1);
             int battery=stoi(newstring);
             cout<<"(int) battery: "<<battery<<endl;
         }
         
     }    
    return 0;
}
