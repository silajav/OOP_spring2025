#include "iostream"
using namespace std;

class shape{
    int position;
    string colour;
    int borderThickness;
    
    public:
    shape(int p, string c, int b=0):position(p), colour(c), borderThickness(b){}
    
    ~shape(){
        cout<<"destructor: shape class.\n";
    }
    
    virtual void draw(){
        cout<<"drawing shape.."<<endl;
    }
    virtual void calcArea(){
        cout<<"calculating area.."<<endl;
    }
    
    virtual void calcperimeter(){
        cout<<"calculating perimeter..."<<endl;
    }
    
    void setBt(int b){
        borderThickness=b;
    }
    
};

class rectangle: public shape{
  int width;
  int height;
  string topleftcornerposition;
  
  public:
  rectangle(int p, string c, int w, int h, string topleft, int b=0): shape(p,c,b),width(w), height(h), topleftcornerposition(topleft){}
  
  ~rectangle(){
      cout<<"destructor: class rectangle"<<endl;
  }
  
  void calcArea() override{
      shape::calcArea();
      cout<<"The shape's area is : "<<width*height<<endl;
  }
  
  void calcperimeter() override{
      shape::calcperimeter();
      cout<<"the perimeter is: "<<(2*width)+(2*height)<<endl;
  }
  
  void draw() override{
      shape::draw();
      cout << "*********" << endl;
      cout << "*       *" << endl;
      cout << "*       *" << endl;
      cout << "*********" << endl;
  }
  
};

class circle:public shape{
    int radius;
    int centre;
    
    public:
    circle(int p, string c, int r, int centre, int b=0):shape(p,c,b), radius(r), centre(centre){}
    
    ~circle(){
        cout<<"destructor: circle class."<<endl;
    }
    
    void calcArea() override{
        int pi=3;//assuming we take int valkue.
        shape::calcArea();
        cout<<"The area of the circle is: "<<(pi*(radius*radius))<<endl;
}

    void calcperimeter() override{
        int pi=3;
        shape::calcperimeter();
        cout<<"the perimeter of the circle is: "<<(2*pi*radius)<<endl;
        
    }
    
    void draw()  override {
        shape::draw();
          cout << "   ***   " << endl;
          cout << " *     * " << endl;
          cout << "*       *" << endl;
          cout << " *     * " << endl;
          cout << "   ***   " << endl;
    }
};

class pentagon: public shape{
    int sideLength;
    double apothem;

public:
    pentagon(int p, string c, int b = 0, int s = 1, double a = 1.0)
        : shape(p, c, b), sideLength(s), apothem(a) {}

    void calcArea() override {
        shape::calcArea();
        cout << "The area of the pentagon is: " << (5 * sideLength * apothem) / 2 << endl;
    }

    void calcperimeter() override {
        shape::calcperimeter();
        cout << "The perimeter of the pentagon is: " << (5 * sideLength) << endl;
    }

    void draw() override {
        shape::draw();
        cout << "  *  " << endl;
        cout << " * * " << endl;
        cout << "*   *" << endl;
        cout << "*****" << endl;
    }

};

int main(){
    cout<<"\n\nCircle: \n";
    circle c(20, "red",2, 5);
    shape* s1=&c;
    s1->calcArea();
    s1->calcperimeter();
    s1->draw();
    
    cout<<"\n\nRectangle: \n";
    rectangle r(10, "blue", 3, 4, "5");
    shape* s2=&r;
    s2->calcArea();
    s2->calcperimeter();
    s2->draw();
    
    cout<<"\n\npentagon: "<<endl;
    pentagon p(12, "black", 4);
    shape* s3=&p;
    s3->calcArea();
    s3->calcperimeter();
    s3->draw();
    
    
    
    return 0;
}
