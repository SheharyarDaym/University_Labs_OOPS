#include<iostream>
using namespace std;

class Student{
private:
    string name;
    double cgpa;
    int rollNo;
    int noOfTests;
    int *Tests;
    double average;

public:
//  Constructor
    Student(string n="", double gpa=0, int roll=0, int noOFTests=0, int *t=0){
        name = n;   
        cgpa = gpa;     
        rollNo = roll;
        noOfTests = noOFTests;      
        Tests = t;
        Tests = new int[noOfTests];
        for(int i=0; i<noOfTests; i++){
            Tests[i] = 0;
        }
    }

    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
    void setCgpa(double gpa){
        cgpa = gpa;
    }
    double getCgpa(){
        return cgpa;
    }
    void setRollNo(int r){
        rollNo = r;
    }
    int getRollNo(){
        return rollNo;
    }
    void setNoOfTests(int t){
        noOfTests = t;
    }
    int getNoOfTests(){
        return noOfTests;
    }
    void setTests(int *t){
        Tests = t;
    }
    int* getTest(){
        return Tests;
    }
    double avg(){
        int sum = 0;
        for(int i=0; i<noOfTests; i++){
            sum = sum + Tests[i];
        }
        average = sum/noOfTests;
        return average;
    }
    

    void Display(){
        cout << "Name: " << getName() << endl;
        cout << "Roll No: " << getRollNo() << endl;
        cout << "CGPA" << getCgpa() <<  endl;
        cout << "Tests: " << endl;
        for(int i=0; i<noOfTests; i++){
            cout << Tests[i] << endl;
        }
        cout << "Average: " << average << endl;
        cout << endl;
    }

// Destructor
    ~Student(){
        if(Tests!=nullptr){
            delete[] Tests;
        }
    }


};

// Global Functions
void takeInformation(Student* students, int numOfStudents){
    string name;
    double cgpa;
    int rollNo;
    int noOfTests;
    for(int i=0; i<numOfStudents; i++){
        cout << "Student no. " << i+1 << endl;
        cout << "Enter name: ";
        cin >> name;
        students[i].setName(name);

        cout << "Enter RollNo: ";
        cin >> rollNo;
        students[i].setRollNo(rollNo);

        cout << "Enter CGPA: ";
        cin >> cgpa;
        students[i].setCgpa(cgpa);

        cout << "Number of Tests: ";
        cin >> noOfTests;
        students[i].setNoOfTests(noOfTests);

        int *marks = new int[noOfTests];
        cout << "Enter Marks(tests) " << endl;
        for(int j=0; j<noOfTests; j++){
            cout << "Enter marks of " << j+1 << " test" << endl;
            cin >> marks[i];
        }
        students[i].setTests(marks);

    }

}

void DisplayOneStudent(Student *students, int noOfStudents, int studentNo){
    if(studentNo > noOfStudents){
        cout << "Error" << endl;
        return;
    }
    students[studentNo].Display();
}

void DisplayAll(Student *students, int noOfStudents){
    for(int i=0; i<noOfStudents; i++){
        students[i].Display();
    }
}

void findTopper(Student* students, int noOfStudents){
    int *AVG = new int[noOfStudents];
    for(int i=0; i<noOfStudents; i++){
        AVG[i] = students[i].avg();
    }

    int max = AVG[0];
    int index = 0;
    for(int i=0; i<noOfStudents; i++){
        if(AVG[i]>max){
            max = AVG[i];
            index = i;
        }
    }
    cout << "\nTopper is: " << endl;
    students[index].Display();

    delete[] AVG;
}


// Main
int main()
{
    int n;
    cout << "Enter number of Students: ";
    cin >> n;
    Student *students = new Student[n];
    takeInformation(students,n);

    int studentNo;
    cout << "\nEnter student number you want to display: ";
    cin >> studentNo;
    DisplayOneStudent(students, n, studentNo);

    cout << "\nDisplay all students: " << endl;
    DisplayAll(students, n);

    findTopper(students, n);  

    delete[] students;
    return 0;
}