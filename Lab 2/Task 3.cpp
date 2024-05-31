#include<iostream>
using namespace std;

class Car{
private:
    int yearModel;
    string make;
    int speed;
public:
    Car(int y, string m){
        yearModel = y;
        make = m;
        speed = 0;
    }
    void setYearModel(int y){
        yearModel = y;
    }
    int getYearModel(){
        return yearModel;
    }
    void setMake(string m){
        make = m;
    }
    string getmake(){
        return make;
    }
    void setSpeed(int s){
        speed = s;
    }
    int getSpeed(){
        return speed;
    }
    int accelerate(){
        speed += 5;
        return speed;        
    }
    int brake(){
        speed -= 5;
        return speed;
    }

};


int main(){
    Car *arr = new Car(2003,"Lexus");
    for(int i=0; i<5; i++){
        cout << "Accelerated: " <<arr->accelerate() << endl;
    }

    cout << "Current Speed of the car is: " << arr->getSpeed() << endl;

    for(int i=0; i<5; i++){
        cout << "Brake: " << arr->brake() << endl;
    }
    cout << "Now, the Current Speed of the car is: " << arr->getSpeed() << endl;

    delete arr;
    arr = nullptr;

    return 0;
}