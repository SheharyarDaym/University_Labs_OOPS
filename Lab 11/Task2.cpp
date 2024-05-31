#include <iostream>
using namespace std;

class Account
{
protected:
    int acc_num;
    int balance;
    int rate;

public:
    Account(int n = 0, int b = 0, int r = 0)
    {
        acc_num = n;
        balance = b;
        rate = r;
    }
    void deposit(int b)
    {
        balance = balance + b;
    }
    void withdraw(int b)
    {
        balance = balance - b;
    }
    virtual int display()
    {
        cout << "Account Interest: " << balance * (rate / 100) << endl;
    }
};

class savingsAccount : public Account
{
public:
    savingsAccount(int n, int b, int r) : Account(n, b, r) {}
    
    void display() const
    {
        cout << "Savings Interest: " << balance * (rate / 100) << endl;
    }
};

class checkingAccount : public Account
{
public:
    checkingAccount(int n, int b, int r) : Account(n, b, r) {}
    
    void display() const
    {
        cout << "Checking Interest: " << balance * (rate / 100) << endl;
    }
};

class Customer : public Account
{
private:
    string id;
    Account **arr;
    int num;

public:
    Customer(string i, int n)
    {
        id = i;
        num = n;
        *arr = new Account[n];
    }
    void createAccount()
    {
        int i = 0;
        int choice;
        do
        {
            cout << "1. Savings Account" << endl;
            cout << "2. Checking Account" << endl;
            cin >> choice;

            if (choice == 1)
            {
                arr[i] = new savingsAccount(876, 240, 25);
            }
            else if (choice == 2)
            {
                arr[i] = new checkingAccount(1090, 239, 15);
            }
            i++;
        } while (i < num);
    }
    void display() const
    {
        for (int i = 0; i < num; i++)
        {
            arr[i]->display();
        }
    }
};

int main(){
    int n;
    cout << "Number of accounts enter: ";
    cout << "PLEJ :) ";
    cin >> n;
    Customer c("ID",n);
    c.display();


}
