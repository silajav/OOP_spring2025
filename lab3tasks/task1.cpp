#include <iostream>
using namespace std;
class markerpens{
  
  string brand;
  string colour;
  int refillability;
  int inklevel=10; //max ink level set when new pen created.
  
  public:
  markerpens(string b, string c, int r){
      brand=b;
      colour=c;
      refillability=r;
  }
  
  void write(){
      if (inklevel<=0){
          cout<<"Ink finished. You need to refill or get a new marker."<<endl;
      }else{
          cout<<"writing"<<endl;
          inklevel--; //each call to write reduces the ink by one bar.
      }
  }
  
  void refill(){
      if (refillability==1){
          if (inklevel<10){
              cout<<"refilling..";
              inklevel=10;
          }else if (inklevel==10){
              cout<<"already full."<<endl;
          }
          cout<<"refillability not possible for this pen."<<endl;
      }
      inklevel=10;//makes ink level max;
  }
  
  void getstatus(){
      cout<<"the brand of the pen: "<<brand<<endl;
      cout<<"the colour of the pen is: "<<colour<<endl;
      cout<<"the ink level is: "<<inklevel<<endl;
      if (refillability==1){
          cout<<"the pen can be refilled."<<endl;
      }else if (refillability==0){
          cout<<"Not refillable."<<endl;
      }
}
    
};
int main() {
    //creating some pens for mr Ahmed:
    markerpens pen1("picasso","blue",1);
    markerpens pen2("abc","black",0);
    markerpens pen3("def", "red", 1);
    pen1.write();
    pen1.write();
    pen2.write();
    pen3.write();
    pen3.refill();
    pen2.refill();
    pen1.refill();
    cout<<"status of pen1  ";
    pen1.getstatus();
    cout<<"status of pen2  ";
    pen2.getstatus();
    cout<<"status of pen3  ";
    pen3.getstatus();
    
    

    return 0;
}
