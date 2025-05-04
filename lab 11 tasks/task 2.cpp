#include<iostream>
#include<exception>
#include<fstream>
using namespace std;

class stackOverflowException:public exception{
    public:
    const char* what() const noexcept override{
        return "stack full---error!";
    }
};


class stackunderflowException:public exception{
    public:
    const char* what() const noexcept override{
        return "stack empty---error!";
    }
};


template<typename T>
class stack{
    T capacity;
    T count;
    public:
    stack(T c): capacity(c), count(0){}
    
    void push(){
        try{
            if (count>=capacity){
                throw stackOverflowException();
            }else{
                count++;
                cout<<"pushed into stack!"<<endl;
            }
        }catch(stackOverflowException& e){
            cout<<e.what();
        }
    }
    
    void pop(){
        try{
            if (count==0){
                throw stackunderflowException();
            }else{
                count--;
            }
        }catch(stackunderflowException& e){
            cout<<e.what();
        }
    }
};

int main(){
    stackOverflowException e;
    stackunderflowException e1;
    stack<int> s(3);
    s.pop();
    s.push();
    s.push();
    s.push();
    s.push();
    
    
    return 0;
}
