#include<iostream>
using namespace std;

class BankAccount{
private: 
    string acc_no;
    string name;
    double balance;
public:
    void setAccount(string a){
        acc_no = a;
    }
    string getAccountNo(){
        return acc_no;
    }
    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
    void deposite(double x){
        balance = x;
    }
    double getDesposite(){
        return balance;
    }
    void setWithDraw(double x){
        balance = balance - x;
    }
    double getWithDraw(){
        cout << balance;
        if(balance >= 0){
            return balance;
        }
        else{
            cout << "Low Balance!!! " << endl;
            return -1;
        }
        return balance;
    }
    // double Balance(){
    // }

};

int main(){
    BankAccount a;
    a.setName("Sheharyar");
    a.setAccount("IB56952R3464");
    a.deposite(12.256) ;
    
    
    cout << "Account holder's Name: " << a.getName() << endl;
    cout << "Account No: " << a.getAccountNo() << endl;
    cout << "Desposite: " << a.getDesposite() << endl;
    a.setWithDraw(14);
    cout << "Withdraw: " << a.getWithDraw() << endl;

    

    return 0;
}