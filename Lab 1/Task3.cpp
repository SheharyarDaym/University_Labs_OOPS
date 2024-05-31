#include<iostream>
using namespace std;

class Book{
private: 
    string title;
    string author;
    string genre;
    string year;
    double price;

public:
    void setTitle(string t){
        title = t;
    }
    string getTitle(){
        return title;
    }
    void setAuthor(string a){
        author = a;
    }
    string getAuthor(){
        return author;
    }
    void setGenre(string g){
        genre = g;
    }
    string getGenre(){
        return genre;
    }
    void setYear(string y){
        year = y;
    }
    string getYear(){
        return year;
    }
    void setPrice(double p){
        price = p;
    }
    double getPrice(){
        return price;
    }
    double discount(){
        double x = price;
        price = price * 0.10;
        price = x - price;
        return price;
    }

};

int main(){
    Book a;
    a.setTitle("Doomsday Conspiracy");
    a.setAuthor("Sidney Sheldon");
    a.setGenre("Fiction");
    a.setYear("1990");
    a.setPrice(895.23);
    
    cout << "Title: " << a.getTitle() << endl;
    cout << "Author: " << a.getAuthor() << endl;
    cout << "Genre: " << a.getGenre() << endl;
    cout << "Year: " << a.getYear() << endl;
    cout << "Price: " << a.getPrice() << endl;
    cout << "(10%) Discount price: " << a.discount() << endl;


    return 0;
}