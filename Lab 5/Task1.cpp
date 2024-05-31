#include<iostream>
#include<stdbool.h>
using namespace std;

int inputValidation(int& number);

class IntArray {
private:
    int* arr;
    int size;
public:
    IntArray() {
        size = 0;
        arr = nullptr;
    }
    IntArray(int s) {
        size = s;
        arr = new int[size];
        for(int i=0;i<size;i++)
        {
            arr[i] = 0;
        }

    }
    IntArray(const IntArray& a) {
        size = a.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a.arr[i];
        }
    }
    void setSize(int s) {
        size = s;
    }
    void setArr(int* a) {
        arr = a;
    }
    int getSize()const {
        return size;
    }
    int* getArr()const {
        return arr;
    }
    void setValue(int value, int index) {
        arr[index] = value;
    }
    int getValue(int value)const {
        return arr[value];
    }
    void Display()const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~IntArray() {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr;
        }
    }

    IntArray addArray(const IntArray obj)const {
        if (size == obj.size) {
            for (int i = 0; i < size; i++) {
                arr[i] = arr[i] + obj.arr[i];
            }
            return *this;
        }
        else {
            cout << "Size not match" << endl;
        }
        return IntArray(0);
    }

    IntArray subArray(const IntArray obj)const {

        if (size == obj.size) {
            for (int i = 0; i < size; i++) {
                arr[i] = arr[i] - obj.arr[i];
            }
            return *this;
        }
        else {
            cout << "Size not match" << endl;
        }
        return IntArray(0);
    }

    IntArray mulArray(const IntArray obj)const {
        if (size == obj.size) {
            for (int i = 0; i < size; i++) {
                arr[i] = arr[i] * obj.arr[i];
            }
            return *this;
        }
        else {
            cout << "Size not match" << endl;
        }
        return IntArray(0);
    }

    bool palindrome()const {
        IntArray result(size);
    
        int j = 0;
        for (int i = size - 1; i >= 0; i--) {
            result.arr[j] = arr[i]  ;
            j++;
        }
        for(int i=0; i<size; i++){
            if(result.arr[i] != arr[i]){
                return false;
            }  
        }
        return true;
    }

    IntArray reverse() {
        IntArray result(size);
    
        int j = 0;
        for (int i = size - 1; i >= 0; i--) {
            result.arr[j] = arr[i]  ;
            j++;
        }
        return result;
    }

   IntArray cyclicRotate(int n) const {
        IntArray result;
        result.size = size;
        result.arr = new int[size];

        for (int i = 0; i < size; i++) {
            result.arr[(i + n) % size] = arr[i];
        }

        return result;
    }




};

int main() {
    cout << "----------Menu-----------" << endl;
    IntArray a1;
    int s;
    cout << "Enter Size: ";
    inputValidation(s);
    a1.setSize(s);
    cout << "Enter Array: ";
    int* ptr = new int[s];
    for (int i = 0; i < s; i++) {
        cin >> ptr[i];
    }
    a1.setArr(ptr);
    int option;

    do
    {
        cout << "-------- Operations Menu--------" << endl;
        cout << "1. Set Size" << endl;
        cout << "2. Set Array" << endl;
        cout << "3. Get Size" << endl;
        cout << "4. Set Value" << endl;
        cout << "5. Get Value" << endl;
        cout << "6. Display" << endl;
        cout << "7. Add Array" << endl;
        cout << "8. Subtract Array" << endl;
        cout << "9. Multiply Array" << endl;
        cout << "10. Palindrome" << endl;
        cout << "11. Reverse" << endl;
        cout << "12. Cyclic Rotate" << endl;
        cout << "13. Exit" << endl;
        cout << "------------------------------------" << endl;
        cout << "Select any option : ";
        inputValidation(option);

        switch (option) {
        case 1:
        {
            cout << "Set Size" << endl;
            cout << "Enter Size : ";
            int size;
            inputValidation(size);
            a1.setSize(size);
        }
        break;

        case 2:
        {
            cout << "Set Array" << endl;
            ptr = new int[s];
            for (int i = 0; i < s; i++) {
                cin >> ptr[i];
            }
            a1.setArr(ptr);
        }
        break;

        case 3:
        {
            cout << "Get Size" << endl;
            int size1 = a1.getSize();
            cout << "Size is: " << size1;
        }
        break;

        case 4:
        {
            cout << "Set Value" << endl;
            int v, i;
            cout << "Enter value: ";
            inputValidation(v);
            cout << "Enter index: ";
            inputValidation(i);
            a1.setValue(v, i);
        }
        break;

        case 5:
        {
            cout << "Get Value" << endl;
            int index;
            cout << "Enter index: ";
            inputValidation(index);
            cout << "Value at this index is: " << a1.getValue(index);
        }
        break;

        case 6:
            cout << "Display" << endl;
            a1.Display();
            break;

        case 7:
        {
            cout << "ADD" << endl;
            IntArray p1;
            int s1;
            cout << "Enter size of 2nd Array: ";
            inputValidation(s1);
            p1.setSize(s1);
            cout << "Enter 2nd array: ";
            int* ptr1 = new int[s];
            for (int i = 0; i < s; i++) {
                cin >> ptr1[i];
            }
            p1.setArr(ptr1);

            IntArray q1 = a1.addArray(p1);
            q1.Display();

            delete[] ptr1;
        }
        break;

        case 8:
        {
            cout << "Subtract" << endl;
            IntArray p1;
            int s1;
            cout << "Enter size of 2nd Array: ";
            inputValidation(s1);
            p1.setSize(s1);
            cout << "Enter 2nd array: ";
            int* ptr1 = new int[s];
            for (int i = 0; i < s; i++) {
                cin >> ptr1[i];
            }
            p1.setArr(ptr1);

            IntArray q1 = a1.subArray(p1);
            q1.Display();

            delete[] ptr1;
        }
        break;

        case 9:
        {
            cout << "Multiplication" << endl;
            IntArray p1;
            int s1;
            cout << "Enter size of 2nd Array: ";
            inputValidation(s1);
            p1.setSize(s1);
            cout << "Enter 2nd array: ";
            int* ptr1 = new int[s];
            for (int i = 0; i < s; i++) {
                cin >> ptr1[i];
            }
            p1.setArr(ptr1);

            IntArray q1 = a1.mulArray(p1);
            q1.Display();

            delete[] ptr1;
        }
        break;

        case 10:
        {
            cout << "Check Palindrome" << endl;
            int check = a1.palindrome();
            if (check == 1) cout << "True" << endl;
            else cout << "False" << endl;
        }
        break;


        case 11:
        {
            cout << "Reverse Array" << endl;
            IntArray p2 = a1.reverse();
            p2.Display();
        }
        break;


        case 12:
        {
            cout << "Cyclic Rotation" << endl;
            int n;
            cout << "Enter rotation time: ";
            inputValidation(n);
            IntArray p2 = a1.cyclicRotate(n);
            // a1.cyclicRotate(n);
            p2.Display();
        }
        break;

        case 13:
            cout << "Exit" << endl;
            break;


        default:
        
            cout << "Error! PLease Enter Again! " << endl;
            break;


        }
    } while (option != 13);





    delete[] ptr;
    ptr = nullptr;
    return 0;
}


int inputValidation(int& number) {
    bool validInput = false;
    while (!validInput) {
        if (cin >> number) {
            if (number < 0) {
                cout << "Enter positive number: " << endl;
            }
            else {
                validInput = true;
            }
        }
        else {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}