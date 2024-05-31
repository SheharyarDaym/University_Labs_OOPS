#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    Complex(double r) : real(r)
    {
        imaginary = 0;
    }
    Complex(double r, double i)
    {
        real = r;
        imaginary = i;
    }
    Complex(const Complex &c)
    {
        real = c.real;
        imaginary = c.imaginary;
    }
    Complex operator+(Complex c)
    {
        Complex sum;
        sum.real = real + c.real;
        sum.imaginary = imaginary + c.imaginary;
        return sum;
    }
    Complex operator-(Complex c)
    {
        Complex minus;
        minus.real = real - c.real;
        minus.imaginary = imaginary - c.imaginary;
        return minus;
    }
    Complex operator*(Complex c)
    {
        Complex mul;
        mul.real = (real * c.real) - (imaginary * c.imaginary);
        mul.imaginary = (real * c.imaginary) + (imaginary * c.real);
        return mul;
    }
    Complex operator/(Complex c)
    {
        Complex div;
        div.real = real * c.real - imaginary * -c.imaginary;
        div.imaginary = real * -c.imaginary + c.real * imaginary;
        double d;
        d = c.real * c.real + c.imaginary * c.imaginary;
        Complex r;
        r.real = div.real / d;
        r.imaginary = div.imaginary / d;

        return r;
    }
    Complex conjugate(Complex c)
    {
        Complex con;
        con.real = c.real;
        con.imaginary = -c.imaginary;
        return con;
    }
    void print() const
    {
        if (imaginary > 0)
        {
            cout << real << "+" << imaginary << "i" << endl;
        }
        else if (imaginary < 0)
        {
            cout << real << imaginary << "i" << endl;
        }
    }
    void setReal(double r)
    {
        real = r;
    }
    double getReal() const
    {
        return real;
    }
    void setImaginary(double i)
    {
        imaginary = i;
    }
    double getImaginary() const
    {
        return imaginary;
    }

    ~Complex()
    {
    }
};

int main()
{
    double r, i;
    cout << "Enter real: ";
    cin >> r;
    cout << "Enter imaginary: ";
    cin >> i;
    Complex c(r, i);
    c.print();

    cout << "After" << endl;
    cout << "Enter real: ";
    cin >> r;
    cout << "Enter imaginary: ";
    cin >> i;

    cout << "ADD Complex number" << endl;
    Complex c1(r, i);
    Complex Test = c + c1;
    Test.print();

    cout << "Subtract Complex Number" << endl;
    Complex c2(r, i);
    Complex Test1 = c - c2;
    Test1.print();

    cout << "Multiply Complex Number" << endl;
    Complex c3(r, i);
    Complex Test2 = c * c3;
    Test2.print();

    cout << "Divide Complex Number" << endl;
    Complex c4(r, i);
    Complex Test3 = c / c4;
    Test3.print();

    cout << "Conjugate" << endl;
    Complex c5(r, i);
    Complex Test4 = c.conjugate(c5);
    Test4.print();

    return 0;
}