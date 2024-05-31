#include<iostream>
using namespace std;


class Student{
private: 
	int rollNumber;
	string name;
	string address;
	string phone;
	char grade;

public:
    void setRollNo(int x){
        rollNumber = x;
    }
    void setName(string n){
        name = n;
    }
    void setAddress(string a){
        address = a;
    }
    void setPhone(string p){
        phone = p;
    }
    void setGrade(char g){
        grade = g;
    }

    int getRollNo(){
        return rollNumber;
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    string getPhone(){
        return phone;
    }
    char getGrade(){
        return grade;
    }

    void display(){
        cout << "Name: " << getName() << endl;
        cout << "Roll Number: " << getRollNo() << endl;
        cout << "Grade: " << getGrade() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Phone: " << getPhone() << endl;
    }

};

int main(){
    Student s1;
    s1.setName("Sheharyar");
    s1.setAddress("Lahore");
    s1.setGrade('A');
    s1.setPhone("3085974310");
    s1.setRollNo(46);
    cout<<s1.getPhone();
    s1.display();



    return 0;
}