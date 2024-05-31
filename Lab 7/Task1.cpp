#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class ObjectTracker{
private:
    static int t;

public:
    ObjectTracker(){
        ++t;
    }
    static int getT(){
        return t;
    }
    ~ObjectTracker(){
        --t;
    }
};
int ObjectTracker::t;

int main(){
    int size;
    srand(time(0));
    size = rand()%20+1;
    cout << "size:  "<< size << endl;

    ObjectTracker **arr = new ObjectTracker*[size];
    for(int i=0; i<size; i++){
        arr[i] = new ObjectTracker;
    }


    cout << ObjectTracker::getT() << endl;
    
    delete arr[2];

    cout << ObjectTracker::getT();
    
    
    for(int i=0; i<size; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
    cout << ObjectTracker::getT();
    

    return 0;
}