#include<iostream>
using namespace std;


class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day(d) , month(m) , year(y) { }
    int getDay()const{
        return day;
    }
    int getMonth()const{
        return month;
    }
    int getYear()const{
        return year;
    }
    void print()const{
        cout << day << "/" << month << "/" << year << "\t";
    }

};

class Time{
private:
    int hour;
    int min;
    int sec;
public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
    int getHour()const{
        return hour;
    }
    int getMin()const{
        return min;
    }
    int getSec()const{
        return sec;
    }
    void print()const{
        cout << hour << ":" << min << ":" << sec << endl;
    }

};

class DateTime : public Date, public Time
{
public:
    DateTime(int d, int m, int y, int h, int mi, int s)
        : Date(d,m,y) , Time(h,mi,s) {}
    void showFormatedDate()
    {
        if(getMonth()==1){
            cout << "January " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }

        else if(getMonth()==2){
            cout << "February " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;     
        }

        else if(getMonth()==3){
            cout << "March " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }

        else if(getMonth()==4){
            cout << "April " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }

        else if(getMonth()==5){
            cout << "May " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==6){
            cout << "June " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==7){
            cout << "July " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==8){
            cout << "August " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==9){
            cout << "September " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==10){
            cout << "October " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==11){
            cout << "November " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
        else if(getMonth()==12){
            cout << "December " << getDay() << ", " << getYear() << " " << getHour()
            << ":" << getMin() << ":" << getSec() << endl;  
        }
    }

    void printDateTime(){
        cout << getDay() << "/" << getMonth() << "/" << getYear() << "  " << 
        getHour() << ":" << getMin() << ":" << getSec() << endl;  
    }

};


int main()
{
    // Date(d,m,y) , Time(h,mi,s)
    int day;
    cout << "Enter Day: ";
    while(1){
        cin >> day;
        if(day>=1 && day<=30){
            break;
        }
        cout << "Enter day again" << endl;
    }
    int month;
    cout << "Enter month: ";
    while(1){
        cin >> month;
        if(month>=1 && month<=12){
            break;
        }
        cout << "Enter month again" << endl;
    }
    int Year;
    cout << "Enter Year: ";
    while(1){
        cin >> Year;
        if(Year>=1){
            break;
        }
        cout << "Enter Year again" << endl;
    }

    int hour;
    cout << "Enter hours" << endl;
    while(1){
        cin >> hour;
        if(hour>=1 && hour<=12){
            break;
        }
        cout << "Enter Hours again" << endl;
    }
    int min;
    cout << "Enter min" << endl;
    while(1){
        cin >> min;
        if(min>=1 && min<=59){
            break;
        }
        cout << "Enter min again" << endl;
    }
    int sec;
    cout << "Enter sec" << endl;
    while(1){
        cin >> sec;
        if(min>=1 && min<=59){
            break;
        }
        cout << "Enter sec again" << endl;
    }
    
    DateTime d (day,month,Year,hour,min,sec);
    cout << "Formated Date: ";
    d.showFormatedDate();
    cout << "\nPrint Date: ";
    d.printDateTime();
    

    return 0;
}