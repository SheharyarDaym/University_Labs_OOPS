#include<iostream>
using namespace std;

class Circle{
private: 
    double radius;
    const double pi = 3.14159;
public:
    Circle(){   // default constructor
        radius = 0.0;        
    }
    Circle(double a){   // overloaded constructor
        radius = a;
    }

    void setRadius(double r){
        radius = r;
    }
    double getRadius(){
        return radius;
    }
    double getArea(){
        return pi * radius * radius;
    }
    double getDiameter(){
        return radius * 2;
    }
    double getCircumference(){
        return 2 * pi * radius;
    }
};


int main(){
    int n;
    cout << "Enter radius here: ";
    while(1){
        cin >> n;
        if(n>0) break;
        cout << "Please enter again! " << endl;

    }
    
    Circle a(n);
    cout << "Area of the circle is: " << a.getArea() << endl;
    cout << "Diameter of the circle is: " << a.getDiameter() << endl;
    cout << "Circumference of the circle is: " << a.getCircumference() << endl;



    return 0;
}