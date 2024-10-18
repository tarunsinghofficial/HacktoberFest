#include <iostream>
using namespace std;

struct ComplexNumber {
    double real;
    double imag;
};

// Function to add two complex numbers
ComplexNumber addComplexNumbers(const ComplexNumber& num1, const ComplexNumber& num2) {
    ComplexNumber sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    return sum;
}

int main() {
    ComplexNumber num1, num2, complexSum;

    cout << "\t<====This is for HacktoberFest===> " << endl << endl;

    cout << "For the 1st complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> num1.real >> num1.imag;

    cout << endl << "For the 2nd complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> num2.real >> num2.imag;

    // Call add function and store result in complexSum
    complexSum = addComplexNumbers(num1, num2);

    // Displaying the sum of the complex numbers
    cout << "Sum = " 
         << complexSum.real 
         << (complexSum.imag >= 0 ? '+' : '-') 
         << abs(complexSum.imag) << "i" 
         << endl;

    return 0;
}
