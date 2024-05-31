#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#define SIZE_NAME 31
#define SIZE_DEPT 41

class Employee{
private:
    int ID;
    char Name[SIZE_NAME];
    char Dept_Name[SIZE_DEPT];

public:
    Employee(){
        ID = 0;
        Name[0] = '\0';
        Dept_Name[0] = '\0';
    }
    Employee(int id, char* n, char* d){
        ID = id;
        strcpy(Name,n);
        strcpy(Dept_Name, d);
    }
    void setID(int id){
        ID = id;
    }
    int getID()const{
        return ID;
    }
    void setName(char* n){
        strcpy(Name, n);
    }
    const char* getName()const{
        return Name;
    }
    void setDept(char* d){
        strcpy(Dept_Name, d);
    }
    const char* getDept()const{
        return Dept_Name;
    }
    void Display()const{
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Department Name: " << Dept_Name << endl;
        cout << "---------------------------\n";
    }

    void storeInFile(ofstream& fout){
        fout << "ID: " << this->getID() << endl;
        fout << "Name: " << this->getName() << endl;
        fout << "Department Name: " << this->getDept() << endl;
    }

    void readFromFile(ifstream& fin){
        int i;
        char n[SIZE_NAME];
        char d[SIZE_DEPT];
        fin.ignore(4);
        fin>>i;
        setID(i);
        cout<<"ID: "<<getID()<<endl;
        fin.ignore(6);
        fin>>n;
        setName(n);
        cout<<"NAME: "<<getName()<<endl;
        fin.ignore(17);
        fin>>d;
        setDept(d);
        cout<<"DEPARTMENT: "<<getDept()<<endl;
    }
    
    

};

int main(){
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    Employee *a = new Employee[size];

    for(int i=0; i<size; i++){
        cout << "Value of Employee " << i+1 << endl;

        int id;
        cout << "Enter ID: ";
        cin >> id;
        a[i].setID(id);

        char name[SIZE_NAME];
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, SIZE_NAME-1);
        a[i].setName(name);

        char dept_name[SIZE_DEPT];
        cout << "Enter department name: ";
        cin.getline(dept_name, SIZE_DEPT-1);
        a[i].setDept(dept_name);
    }
    
    // for(int i=0; i<size; i++){
    //     a[i].Display();
    // }

    // Write to txt file
    ofstream fout;
    fout.open("Emps.txt");

    if(!fout){
        cout << "ERROR! FILE NOT WORKING" << endl;
    }
    else{
        for(int i=0; i<size; i++){
            a[i].storeInFile(fout);
        }
        fout.close();
    }

    ifstream fin;
    fin.open("Emps.txt");
    if(!fin){
        cout << "ERROR! FILE NOT WORKING" << endl;
    }
    else{
        for(int i=0; i<size; i++){
            a[i].readFromFile(fin);
        }
        fin.close();
    }

    delete[] a;
    a = NULL;
    return 0;
}