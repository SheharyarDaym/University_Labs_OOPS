#include<iostream>
using namespace std;

class Ship{
private:
    string ship;
    string year;
public:
    Ship(string s, string y) : ship(s), year(y) {}

    void setShip(string s){
        ship = s;
    }
    string getShip()const{
        return ship;
    }
    void setYear(string s){
        year = s;
    }
    string getYear()const{
        return year;
    }

    virtual void display(){
        cout << "Ship Name: " << ship << endl;
        cout << "Year: " << year << endl;
    }


};

class CruiseShip : public Ship{
private:
    int num;
public:
    CruiseShip(int n, string s, string y) : Ship(s,y), num(n) { }

    void setNum(int n){
        num = n;
    }
    int getNum() const{
        return num;
    }
    void display() override{
        cout << "Ship Name: " << getShip() << endl;
        cout << "Maximum number of passengers: " << num << endl; 
    }
};

class CargoShip : public Ship
{
public:
    int capacity;
public:
    CargoShip(int c, string s, string y) : Ship(s,y), capacity(c) {}
    void setCapacity(int c){
        capacity = c;
    }
    int getCapacity() const{
        return capacity;
    }
    void display() override{
        cout << "Ship Name: " << getShip() << endl;
        cout << "Cargo Capacity: " << capacity << endl; 
    }

};

class BattleShip : public Ship{
private:
    int missiles;
public:
    BattleShip(int m, string s, string y) : Ship(s,y), missiles(m) {}
    void setMissiles(int m){
        missiles = m;
    }
    int getMissiles()const{
        return missiles;
    }
    
    void display() override{
        cout << "Ship Name: " << getShip() << endl;
        cout << "Missiles Capacity: " << missiles << endl; 
    }
};

int main(){
    int select;
    Ship *arr[3];
    int i=0;
    do{
        cout << "1. Cruise Ship" << endl;
        cout << "2. Cargo Ship" << endl;
        cout << "3. Battle Ship" << endl;
        cout << "Select your Choice: ";
        cin >> select;

        if(select==1){
            arr[i] = new CruiseShip(100,"Cruise","1999");
        }
        else if(select==2){
            arr[i] = new CargoShip(10000,"Cargo","2003");
        }
        else if(select==3){
            arr[i] = new BattleShip(60,"Battle","2009");
        }


        i++;
    }while(i<3);

    for(int i=0; i<3; i++){
        arr[i]->display();
        cout << "--------------\n";
    }

    for(int i=0; i<3; i++){
        delete arr[i];
        arr[i] = nullptr;
    }
    
    return 0;
}