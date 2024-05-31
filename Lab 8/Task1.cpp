#include <iostream>
using namespace std;


class IntArray
{
private:
    int *aptr;
    int arraySize;

public:
    IntArray(int size = 0)
    {
        arraySize = size;
        aptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            aptr[i] = 0;
        }
    }

    void setSize(int size)
    {
        arraySize = size;
    }
    int getSize() const
    {
        return arraySize;
    }

    void set_aptr(int *a)
    {
        aptr = a;
    }
    int *get_aptr() const
    {
        return aptr;
    }

    int operator[](int i) const
    {
        if (i < arraySize && i >= 0)
        {
            return aptr[i];
        }
        else
        {
            return -999;
        }
    }

    void operator+=(const IntArray &a)
    {
        int s = arraySize + a.arraySize;
        IntArray p(s);
        for (int i = 0; i < arraySize; i++)
        {
            p.aptr[i] = aptr[i];
        }
        int j = 0;
        for (int i = arraySize; i < s; i++)
        {
            p.aptr[i] = a.aptr[j];
            j++;
        }
        p.display();
    }

    IntArray &operator=(const IntArray &a)
    {
        if (this == &a)
            return *this;
        if (a.arraySize != arraySize)
        {
            // if(aptr!=nullptr){
            delete[] aptr;
            aptr = nullptr;
            // }

            aptr = new int(a.arraySize);
        }
        arraySize = a.arraySize;
        for (int i = 0; i < arraySize; i++)
        {
            aptr[i] = a.aptr[i];
        }

        return *this;
    }

    friend ostream &operator<<(ostream &, IntArray &);

    void display() const
    {
        for (int i = 0; i < arraySize; i++)
        {
            cout << aptr[i] << " ";
        }
    }

    ~IntArray()
    {
        if (aptr != nullptr)
        {
            delete[] aptr;
            aptr = nullptr;
        }
    }
};

ostream &operator<<(ostream &o, IntArray &a)
{
    for (int i = 0; i < a.arraySize; i++)
    {
        o << a.aptr[i] << " ";
    }
    o << endl;
    return o;
}

int main()
{
    int size;
    cout << "Enter size : ";
    cin >> size;

    int *arr1 = new int[size];

    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }

    IntArray a1(size);
    a1.set_aptr(arr1);

    cout << "Enter size : ";
    cin >> size;

    int *arr2 = new int[size];

    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i];
    }

    IntArray a2(size);
    a2.set_aptr(arr2);

    int index;
    cout << "Enter index of arr1 : ";
    cin >> index;
    cout << a1[index];
    cout << endl;

    cout << "+=" << endl;
    a1 += a2;

    cout << "\n=" << endl;
    a2 = a1;
    cout << a2;

    return 0;
}