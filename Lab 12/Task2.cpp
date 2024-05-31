#include<iostream>
using namespace std;

template <class T>
T** add(T** matrix1, T** matrix2, int size){
    T** matrix = new T*[size];
    for(int i=0; i<size; i++){
        matrix[i] = new T[size];
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix;
}

template <class T>
T** subtract(T** matrix1, T** matrix2, int size){
    T** matrix = new T*[size];
    for(int i=0; i<size; i++){
        matrix[i] = new T[size];
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return matrix;
}

template <class T>
T** multiplication(T** matrix1, T** matrix2, int size){
    T** matrix = new T*[size];
    for(int i=0; i<size; i++){
        matrix[i] = new T[size];
        for(int j=0; j<size; j++){
            matrix[i][j] = 0; 
        }
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return matrix;
}


// Printint
template <class T>
void print(T** matrix, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl << endl;
    }
}

int main(){
    int size;
    cout << "Enter size of INT Matrix: ";
    cin >> size;

// DMA matrix 1
    int** matrix1 = new int*[size];
    for(int i=0; i<size; i++){
        matrix1[i] = new int[size];
    }
    cout << "Enter matrix 1: " << endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin >> matrix1[i][j];
        }
    }

// DMA matrix 2
    int** matrix2 = new int*[size];
    for(int i=0; i<size; i++){
        matrix2[i] = new int[size];
    }
    cout << "Enter matrix 2: " << endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin >> matrix2[i][j];
        }
    }

// -------------------------------------

    int size2;
    cout << "Enter size of FLOAT Matrix: ";
    cin >> size2;

// DMA matrix 1
    float** matrix3 = new float*[size2];
    for(int i=0; i<size2; i++){
        matrix3[i] = new float[size2];
    }
    cout << "Enter matrix 3: " << endl;
    for(int i=0; i<size2; i++){
        for(int j=0; j<size2; j++){
            cin >> matrix3[i][j];
        }
    }

// DMA matrix 2
    float** matrix4 = new float*[size2];
    for(int i=0; i<size2; i++){
        matrix4[i] = new float[size2];
    }
    cout << "Enter matrix 4: " << endl;
    for(int i=0; i<size2; i++){
        for(int j=0; j<size2; j++){
            cin >> matrix4[i][j];
        }
    }


    while(1)
    {
        int n;
        cout << "What do you want?" << endl;
        cout << "1) Addition " << endl;
        cout << "2) Subtraction " << endl;
        cout << "3) Multiplication " << endl;
        cout << "4) EXIT" << endl;
        cin >> n;

        if(n==1){
            cout << "----------INT----------" << endl;
            int** Matrix = add<int>(matrix1,matrix2,size);
            print<int>(Matrix,size);
            cout << "----------FLOAT----------" << endl;
            float** Matrix1 = add<float>(matrix3,matrix4,size);
            print<float>(Matrix1,size);            
        }
        else if(n==2){
            cout << "----------INT----------" << endl;
            int** Matrix = subtract<int>(matrix1,matrix2,size);
            print<int>(Matrix,size);
            cout << "----------FLOAT----------" << endl;
            float** Matrix1 = subtract<float>(matrix3,matrix4,size);
            print<float>(Matrix1,size);            

        }
        else if(n==3){
            cout << "----------INT----------" << endl;
            int** Matrix = multiplication<int>(matrix1,matrix2,size);
            print<int>(Matrix,size);
            cout << "----------FLOAT----------" << endl;
            float** Matrix1 = multiplication<float>(matrix3,matrix4,size);
            print<float>(Matrix1,size);            
        }
        else if(n==4){
            break;
        }
        else{
            cout << "Enter from(1-4)" << endl;
        }
    }

    


    return 0;
}