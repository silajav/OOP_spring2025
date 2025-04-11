#include "iostream"
using namespace std;
class humidity;
class temperature{
    int degree;
    public:
    temperature(int d):degree(d){}
    friend void calcHeatindex(temperature& obj, humidity& obj1);
    
};

class humidity{
    float percentage;
    public:
    humidity(float p):percentage(p){}
    friend void calcHeatindex(temperature& obj, humidity& obj1);
    
};

void calcHeatindex(temperature& obj, humidity& obj1){
    float index;
    cout<<"calculating heat index..."<<endl<<endl;
    cout<<"Heat index: "<<obj.degree * obj1.percentage/100<<endl;
    
}

int main(){
    temperature T(32);
    humidity h(70);
    calcHeatindex(T,h);
}
