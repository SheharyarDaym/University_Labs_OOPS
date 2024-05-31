#include<iostream>
using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    void setDay(int d){
        day = d;
    }
    int getDay()const{
        return day;
    }
    void setMonth(int m){
        month = m;
    }
    int getMonth()const{
        return month;
    }
    void setYear(int y){
        year = y;
    }
    int getYear()const{
        return year;
    }

    void displayDate()const{
        cout << getDay() << "/" << getMonth() << "/" << getYear() << endl;
    }

};

int main(){
    Date arr[5];
    arr[0].setDay(25); arr[0].setMonth(12); arr[0].setYear(1876);
    arr[1].setDay(9); arr[1].setMonth(11); arr[1].setYear(1877);
    arr[2].setDay(21); arr[2].setMonth(4); arr[2].setYear(1938);
    arr[3].setDay(14); arr[3].setMonth(8); arr[3].setYear(1947);
    arr[4].setDay(11); arr[4].setMonth(9); arr[4].setYear(1948);
    for(int i=0; i<5; i++){
        arr[i].displayDate();
    }
    int size;
    cout << "Enter size here: ";
    cin >> size;
    Date *array = new Date[size];

    int d,m,y;
    for(int i=0; i<size; i++){
        cout << "Enter day/month/year ! " << endl;
        while(1){
            cin >> d >> m >> y;
            if(d>0 && d<32 && m>=1 && m<=12){
                break;
            }
            cout << "ERROR!! Please enter again " << endl;
        }
        array[i].setDay(d);
        array[i].setMonth(m);
        array[i].setYear(y);
    }

    cout << "You entered: " << endl;
    for(int i=0; i<size; i++){
        array[i].displayDate();
    }

    delete[] array;
    array = nullptr;

    return 0;
}