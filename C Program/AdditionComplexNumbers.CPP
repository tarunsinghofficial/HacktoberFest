#include <iostream>
using namespace std;

struct Complex {
    float real;
    float imag;
};

Complex addComplexNumbers(const Complex& num1, const Complex& num2);

int main() {
    Complex num1, num2, complexSum;

    cout << "\t<==== This is for HacktoberFest ===> " << endl << endl;

    cout << "For the 1st complex number, enter the real and imaginary parts:" << endl;
    cin >> num1.real >> num1.imag;

    cout << endl << "For the 2nd complex number, enter the real and imaginary parts:" << endl;
    cin >> num2.real >> num2.imag;

    // Call add function and store result in complexSum
    complexSum = addComplexNumbers(num1, num2);

    // Determine the sign of the imaginary part
    char signOfImag = (complexSum.imag >= 0) ? '+' : '-';
    float adjustedImag = (complexSum.imag >= 0) ? complexSum.imag : -complexSum.imag;

    cout << "Sum = " << complexSum.real << " " << signOfImag << " " << adjustedImag << "i" << endl;

    return 0;
}

Complex addComplexNumbers(const Complex& num1, const Complex& num2) {
    Complex temp;
    temp.real = num1.real + num2.real;
    temp.imag = num1.imag + num2.imag;
    return temp;
}
