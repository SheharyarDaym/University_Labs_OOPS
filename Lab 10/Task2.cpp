#include<iostream>
using namespace std;

class Employee{
protected:
    string name;
    string ssn;
    double net_pay;
public:
    Employee() : name(""), ssn(""), net_pay(0) {}
    Employee(string n, string s, double net) : name(n), ssn(s), net_pay(net) {}
    string getName()const{
        return name;
    }
    string getSSN()const{
        return ssn;
    }
    double getNet_Pay()const{
        return net_pay;
    }
    void setName(string n){
        name = n;
    }
    void setSSN(string s){
        ssn = s;
    }
    void setNet_pay(double n){
        net_pay = n;
    }
    void print_check()const{
        cout << "Name: " << name << endl;
        cout << "SSN: " << ssn << endl;
        cout << "Net_Pay: " << net_pay << endl;
    }
};

class SalariedEmployee : public Employee
{
protected:
    double salary;
public:
    SalariedEmployee() : Employee() ,  salary(0) {}
    SalariedEmployee(string n, string s, double net, double sal) 
        : Employee(n,s,net) , salary(sal) {}
    double getSalary()const{
        return salary;
    }
    void setSalary(double s){
        salary = s;
    }
    void print_check()const{
        Employee::print_check();
        cout << "Salary: " << salary << endl;
    }

};

class Administrator : public SalariedEmployee
{
protected:
    string title;
    string responsibility;
    string adminSupervisor;
public:
    Administrator() : title("") {}
    Administrator(string n, string s, double net, double sal, string t,
                 string res, string ad)
        : SalariedEmployee(n,s,net,sal) , title(t), responsibility(res),
          adminSupervisor(ad) {}
        
    void setSupervisor(string n){
        adminSupervisor = n;
    }
    void readData(){
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee ssn: ";
        cin >> ssn;
        cout << "Net_Pay: ";
        cin >> net_pay;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Title: ";
        cin >> title;
        cout << "Enter responsibility: ";
        cin >> responsibility;
        cout << "Name of admin Supervisor: ";
        cin >> adminSupervisor;
    }

    void print()const{
        cout << "-------------------------\n";
        SalariedEmployee::print_check();
        cout << "Title: " << title << endl;
        cout << "Responsibility: " << responsibility << endl;
        cout << "Name of admin supervisor: " << adminSupervisor << endl;
    }

};

int main(){
    // string n, string s, double net
    string name;
    cout << "Enter employee name: ";
    cin >> name;
    string ssn;
    cout << "Enter employee ssn: ";
    cin >> ssn;
    double net_pay;
    cout << "Net_Pay: ";
    cin >> net_pay;
    Employee e(name,ssn,net_pay);
    e.print_check();
    cout << "-----------------\n";
    cout << "Enter salary: ";
    double salary;
    cin >> salary;
    SalariedEmployee s(name,ssn,net_pay,salary);
    s.print_check();
    cout << "-----------------\n";


    Administrator a;
    a.readData();
    a.print();

    return 0;
}