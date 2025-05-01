// Online C++ compiler to run C++ program online
#include <iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

int main() {
   ifstream file("vehicles.txt");
   string line;
   
   if (!file.is_open()){
       cout<<"file could not be open!"<<endl;
       return 1;
   }
   while (getline(file, line)){
        if (line.empty()|| line[0]=='#'){
           continue;
       }
       istringstream iss(line);
       string name;
       string model;
       string feature;
       string year;
       string extra;
       string cert;
       getline(iss,name,',');//enter a delimiter into getline.
       getline(iss,model, ',');
       getline(iss, feature, ',');
       getline(iss, year, ',');
       getline(iss, extra, ',');
       getline(iss,cert, ',');
       cout<<"Name: "<<name<<"\nModel: "<<model<<"\nFeature: "<<feature<<"\nYear: "<<year<<"\nBattery: "<<extra          <<"\ncert: "<<cert<<endl;            
      
    if (name=="Hybrid truck"){
        string cargo;
        string battery;
        int c;
        int b;
        size_t poscolon=extra.find(':');//plus 1 to start
        size_t pospipe=extra.find('|');//minus poscolon to find length.
        size_t posbattery=extra.find("battery:") //plus 8 to get the battery value.
        if (poscolon==npos || pospipe==npos){
            cout<<"colon or pipe not found!!"<<endl;
        }else{
            cargo=extra.substr(poscolon+1, pospipe-poscolon);
            battery=extra.substr(posbattery+8);
            c=stoi(cargo);
            b=stoi(battery);
            cout<<"(int) cargo: "<<c<<"\n(int battery): "<<b<<endl;
        }
        
    }
   }
   
   
   file.close();
    return 0;
}
