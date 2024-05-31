#include<iostream>
using namespace std;

template <class T>
T* Sum(T* arr1, T* arr2, int size){
    T* arr3 = new T[size];
    for(int i=0; i<size; i++){
        arr3[i] = arr1[i] + arr2[i]; 
    }
    return arr3;
}


int main(){
// For INT
    int size;
    cout << "Enter size of INT ARRAY: ";
    cin >> size;

    int* arr1 = new int[size];
    cout << "Enter ARRAY 1: ";
    for(int i=0; i<size; i++){
        cin >> arr1[i];
    }

    int* arr2 = new int[size];
    cout << "Enter ARRAY 2: ";
    for(int i=0; i<size; i++){
        cin >> arr2[i];
    }

    int* arr3 = Sum<int>(arr1,arr2,size);
    cout << "Sum of both array are: ";
    for(int i=0; i<size; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "----------------------\n\n";
// For Float
    int size2;
    cout << "Enter size of FLOAT ARRAY: ";
    cin >> size2;

    float* arr4 = new float[size2];
    cout << "Enter ARRAY 3: ";
    for(int i=0; i<size2; i++){
        cin >> arr4[i];
    }

    float* arr5 = new float[size2];
    cout << "Enter ARRAY 4: ";
    for(int i=0; i<size2; i++){
        cin >> arr5[i];
    }

    float* arr6 = Sum<float>(arr4,arr5,size2);
    cout << "Sum of both array are: ";
    for(int i=0; i<size2; i++){
        cout << arr6[i] << " ";
    }
    cout << endl;



// Memory deallocation
    delete[] arr1;
    delete[] arr2;
    delete[] arr4;
    delete[] arr5;
    return 0;
}