// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class movie{
    string title;
    string director;
    string duration;
    
    public:
    movie(string t, string d, string dr): title(t), director(d), duration(d) {}
    
    movie(){
        title="unknown";
        director="unknown";
        string duration="unknown";
    }
    ~movie(){
        cout<<"movie destructor."<<endl;
    }
    string getname(){
        return title;;
    }
    string getdirector(){
        return director;
    }
    
    string getduration(){
        return duration;
    }
    void setname(string n){
        title=n;
    }
    void setdirector(string d){
        director = d;
    }
    
    void setduration(string dr){
        duration=dr;
    }
    
};

class cinema{
    string name;
    movie movies[10];//max.
    int count;
    public:
    cinema(string n): name(n), count(0){}
    
    void add(string t, string d, string dr){
        if (count>=10){
            cout<<"No more movies can be added."<<endl;
    }else{
        movies[count].setname(t);
        movies[count].setdirector(d);
        movies[count].setduration(dr);
        count++;
    }
    }
    void display(){
        cout<<"Cinema Hall "<<name<<endl;
        cout<<"currently screening: "<<endl;
        for(int i=0; i<count; i++){
            cout<<movies[i].getname()<<" -- "<<movies[i].getdirector()<<"  --  "<<movies[i].getduration()<<". \n";
        }
    }

};

int main(){
    cinema c("super cinema");
    c.add("frozen","andrew","1 hour 25 mins");
    c.add("it ends w us ", "john", "2 hours");
    c.add("hello", "steven", "1 hour 30 mins");
    c.add("shutter island ", "silz", "3 hours");
    c.display();
    return 0;
}
