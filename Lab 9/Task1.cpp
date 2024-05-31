#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Employee{
private:
    char name[50];
    int number;
public:
    Employee(char* n=0, int num=0){
        number = num;
        strcpy(name,n);
    }
    void setNumber(int n){
        number = n;
    }
    int getNumber(){
        return number;
    }
    void setName(char *n){
        strcpy(name,n);
    }
    char* getName(){
        return name;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
    Employee(const Employee& orig){
        number = orig.number;
        strcpy(name,orig.name);
    }
    Employee& operator = (const Employee& orig){
        if(this == &orig) return *this; // Self Assignment
        number = orig.number;
        strcpy(name,orig.name);
    }
};



class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;
public:
    ProductionWorker(int s=0, double h=0, char* n=0, int number=0) : Employee(n,number){
        shift = s;
        hourlyPayRate = h;
    }
    void setShift(int s){
        shift = s;
    }
    int getShift(){
        return shift;
    }
    void setHourlyPayRate(double h){
        hourlyPayRate = h;
    }
    double getHourlyPayRate(){
        return hourlyPayRate;
    }
    void display(){
        Employee::display();
        if(shift == 1){
            cout << "Day Shift" << endl; 
        }
        else if(shift == 2){
            cout << "Night Shift" << endl; 
        }
        cout << "Hourly Pay Rate: " << hourlyPayRate << endl;
    }
    ProductionWorker(const ProductionWorker& orig) : Employee(orig){
        shift = orig.shift;
        hourlyPayRate = orig.hourlyPayRate;        
    }
    ProductionWorker& operator = (const ProductionWorker& orig){
        Employee::operator=(orig);
        if(this == &orig) return *this;
        shift = orig.shift;
        hourlyPayRate = orig.hourlyPayRate;
    }

};


class TeamLeader : public ProductionWorker
{
private:
    double bonusAmount;
    int trainingHours;
    int attendedTrainingHours;
public:
    TeamLeader(double b=0, int t=0, int at=0, int s=0, double h=0, char* n=0, int number=0)
            : ProductionWorker(s, h, n, number)
    {
        bonusAmount = b;
        trainingHours = t;
        attendedTrainingHours = at;
    }
    void setBonusAmount(double b){
        bonusAmount = b;
    }
    double getBonusAmount(){
        return bonusAmount;
    }
    void setTrainingHours(int n){
        trainingHours = n;
    }
    int getTrainingHours(){
        return trainingHours;
    }
    void setAttendedTrainingHours(int n){
        attendedTrainingHours = n;
    }
    int getAttendedTrainingHours(){
        return attendedTrainingHours;
    }

    void Display(){
        ProductionWorker::display();
        cout << "Bonus Amount: " << bonusAmount << endl;
        cout << "Training Hours: " << trainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    } 
};



int main(){
    /*
    cout << "----------------Employee Stack----------------" << endl;
    char name[50];
    cout << "Enter name: " << endl;
    cin.getline(name,50);
    int number;
    cout << "Enter number of employees" << endl;
    cin >> number;

    Employee e1(name,number);
    cout << "Display-------------" << endl;
    e1.display();

    cout << "----------------Employee Heap----------------" << endl;
    char name2[50];
    cout << "Enter name: " << endl;
    cin.ignore();
    cin.getline(name2,50);
    int number2;
    cout << "Enter number of employees" << endl;
    cin >> number2;

    Employee* e2;
    e2 = new Employee(name2,number2);
    cout << "Display-------------" << endl;
    e2->display();


// Stack ProductionWorker
    cout << "----------------Production Stack----------------" << endl;
    int shift, number3;
    double hourlyRate;
    char name3[50];
    cout << "Enter name: " << endl;
    cin.ignore();
    cin.getline(name3,50);
    cout << "Enter number of employees" << endl;
    cin >> number3;
    cout << "Enter Shift (1) Day : Shift(2) Night";
    cin >> shift;
    cout << "Enter Hourly Rate: " << endl;
    cin >> hourlyRate;
    ProductionWorker p1(shift,hourlyRate,name3,number3);
    cout << "Display-------------" << endl;
    p1.display();

// Heap ProductionWorker
    cout << "----------------Production Heap----------------" << endl;
    int shift2, number4;
    double hourlyRate2;
    char name4[50];
    cout << "Enter name: " << endl;
    cin.ignore();
    cin.getline(name4,50);
    cout << "Enter number of employees" << endl;
    cin >> number4;
    cout << "Enter Shift (1) Day : Shift(2) Night";
    cin >> shift2;
    cout << "Enter Hourly Rate: " << endl;
    cin >> hourlyRate2;
    ProductionWorker* p2;
    p2 = new ProductionWorker(shift2,hourlyRate2,name4,number4);
    cout << "Display-------------" << endl;
    p2->display();
*/

    cout << "*************************Team Leader**************************" << endl;
    int n;
    cout << "How many team leader objects you want? " << endl;
    cin >> n;
    TeamLeader** t1;
    t1 = new TeamLeader*[n];
    for(int i=0; i<n; i++){
        cout << "**********************Team # "<< i+1 << "************************" << endl;
        int shift, number;
        double hourlyRate;
        cout << "Enter number of employees" << endl;
        cin >> number;
            char name[50];
        for(int i=0; i<number; i++){
            cout << "Enter name: " << i+1 << " member:"<<  endl;
            cin.ignore();
            cin.getline(name,50);
        }
        cout << "Enter Shift (1) Day : Shift(2) Night";
        cin >> shift;
        cout << "Enter Hourly Rate: " << endl;
        cin >> hourlyRate;
        double bonus;
        cout << "Enter Bonus Amount" << endl;
        cin >> bonus;
        int trainingHours;
        cout << "Enter Training hours" << endl;
        cin >> trainingHours;
        int attendedTrainingHours;
        cout << "Enter Attended Training Hours" << endl;
        cin >> attendedTrainingHours;
        t1[i]=new TeamLeader(bonus,trainingHours,attendedTrainingHours, shift, hourlyRate, name, number);
        t1[i]->display();
    }
//  TeamLeader(double b=0, int t=0, int at=0, int s=0, double h=0, char* n=0, int number=0)
//             : ProductionWorker(s, h, n, number)
//  double bonusAmount;
//     int trainingHours;
//     int attendedTrainingHours;

    for(int i=0; i<n; i++){
        delete[] t1[n];
    }
    delete[] t1;
    t1 = nullptr;
    // delete p2;
    // p2 = nullptr;
    // delete e2;
    // e2 = nullptr;
    return 0;
}