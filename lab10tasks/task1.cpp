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
       string a;
       iss>>a;
       if (line.empty()|| a=="#"){
           continue;
       }else{
           cout<<line<<endl;
       }
   }
   
   file.close();
    return 0;
}
