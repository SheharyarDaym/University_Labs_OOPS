#include<iostream>
using namespace std;

class square{
private:
    int side;

public:
    square(int s){
        side = s;
    }
    friend class Rectangle;
    
};

class Rectangle{
private:
    int height;
    int width;
    
public:
    Rectangle(int h, int w){
        height = h;
        width = w;
    }
    void areaSquare(square a){
        cout << a.side * a.side << endl;
    }
    void areaRectangle(){
        cout <<  height*width << endl;
    }

};

int main(){

    square a(3);
    Rectangle b(4,2);
    b.areaRectangle();
    b.areaSquare(a);




    return 0;
}