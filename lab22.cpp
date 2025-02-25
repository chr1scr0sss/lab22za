#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber {
public:
    double real;
    double imag;
    
    ComplexNumber(double x = 0, double y = 0);
    
    ComplexNumber operator+(const ComplexNumber&);
    ComplexNumber operator-(const ComplexNumber&);
    ComplexNumber operator*(const ComplexNumber&);
    ComplexNumber operator/(const ComplexNumber&);
    bool operator==(const ComplexNumber&);
    double abs();
    double angle();
    
    ComplexNumber operator+(double a);
    ComplexNumber operator-(double a);
    ComplexNumber operator*(double a);
    ComplexNumber operator/(double a);

    friend ComplexNumber operator+(double a, const ComplexNumber &c);
    friend ComplexNumber operator-(double a, const ComplexNumber &c);
    friend ComplexNumber operator*(double a, const ComplexNumber &c);
    friend ComplexNumber operator/(double a, const ComplexNumber &c);
    
    friend bool operator==(double a, const ComplexNumber &c);
};

// Constructor
ComplexNumber::ComplexNumber(double x, double y) {
    real = x; imag = y;
}

// Operator overloads for complex numbers
ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}

//Write your code here
// Comparison operator
bool ComplexNumber::operator==(const ComplexNumber &c) {
    return real == c.real && imag == c.imag;
}

// Absolute value of the complex number
double ComplexNumber::abs() {
    return sqrt(real * real + imag * imag);
}

// Angle of the complex number
double ComplexNumber::angle() {
    return atan2(imag, real) * (180 / M_PI);
}

ComplexNumber ComplexNumber::operator+(double a) {
    return ComplexNumber(real + a, imag);
}

ComplexNumber ComplexNumber::operator-(double a) {
    return ComplexNumber(real - a, imag);
}

ComplexNumber ComplexNumber::operator*(double a) {
    return ComplexNumber(real * a, imag * a);
}

ComplexNumber ComplexNumber::operator/(double a) {
    return ComplexNumber(real / a, imag / a);
}

ComplexNumber operator+(double a, const ComplexNumber &c) {
    return ComplexNumber(a + c.real, c.imag);
}

ComplexNumber operator-(double a, const ComplexNumber &c) {
    return ComplexNumber(a - c.real, -c.imag);
}

ComplexNumber operator*(double a, const ComplexNumber &c) {
    return ComplexNumber(a * c.real, a * c.imag);
}

ComplexNumber operator/(double a, const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((a * c.real) / denominator, (-a * c.imag) / denominator);
}

// Comparison operator for double and ComplexNumber
bool operator==(double a, const ComplexNumber &c) {
    return a == c.real && c.imag == 0;
}

// Output operator
ostream& operator<<(ostream &os, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) {
        os << 0;
    } else if (c.real == 0) {
        os << c.imag << "i";
    } else if (c.imag == 0) {
        os << c.real;
    } else {
        os << c.real;
        if (c.imag > 0) {
            os << "+" << c.imag << "i";
        } else {
            os << c.imag << "i";
        }
    }
    return os;
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}