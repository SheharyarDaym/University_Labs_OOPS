#include<iostream>
using namespace std;

class Book{
private:
    string title;
    string author;
    const int publicationYear;
    float &price;
    int pageCount;
    char **contents;
public:
// Constructor
    Book(string t, string a, const float p, float&pr, int pc, char**c) :title(t), publicationYear(p),
         author(a), price(pr), pageCount(pc)
    {
        // DMA
        contents = new char*[pageCount];
        for(int i=0; i<pageCount; i++){
            contents[i] = new char[pageCount];
        }

    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    int getPublicationYear(){
        return publicationYear;
    }
    float getPrice(){
        return price;
    }
    int getPageCount(){
        return pageCount;
    }
    // Additional
    void setPageContents(int page, const string& content){
        if(page>=0 && page<=pageCount){

        }
    }

    void displayPageContent(int page){
        
    }


    ~Book(){
        if(contents!=nullptr){
            for(int i=0; i<pageCount; i++){
                delete[] contents[i];
            }
            delete[] contents;
        }
    }

};

int main(){

    return 0;
}