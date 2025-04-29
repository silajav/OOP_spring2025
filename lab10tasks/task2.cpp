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
       istringstream iss(line);
       string name;
       string model;
       string feature;
       string year;
       string battery;
       string cert;
       getline(iss,name,',');//enter a delimiter into getline.
       getline(iss,model, ',');
       getline(iss, feature, ',');
       getline(iss, year, ',');
       getline(iss, battery, ',');
       getline(iss,cert, ',');
       cout<<"Name: "<<name<<"\nModel: "<<model<<"\nFeature: "<<feature<<"\nYear: "<<year<<"\nBattery: "<<battery<<"\ncert: "<<cert<<endl;            
       if (line.empty()|| line[0]=='#'){
           continue;
       }else{
           cout<<line<<endl;
       }
   }
   
   file.close();
    return 0;
}
