#include <iostream>
using namespace std;

// Structure to represent a complex number
typedef struct complex {
    float real;
    float imag;
} complexNumber;

// Function to add two complex numbers
complexNumber addComplexNumbers(complexNumber, complexNumber);

int main() {
    complexNumber num1, num2, complexSum;
    char signOfImag;

    cout << "\t<==== This is for HacktoberFest ===> " << endl << endl;

    // Input for the first complex number
    cout << "For the 1st complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> num1.real >> num1.imag;

    cout << endl << "For the 2nd complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> num2.real >> num2.imag;

    // Adding two complex numbers and storing the result in complexSum
    complexSum = addComplexNumbers(num1, num2);

    // Ternary operator to check and assign the sign of the imaginary part
    signOfImag = (complexSum.imag >= 0) ? '+' : '-';

    // Adjusting the sign of the imaginary part
    complexSum.imag = (complexSum.imag >= 0) ? complexSum.imag : -complexSum.imag;

    // Display the result in the format "a + bi" or "a - bi"
    cout << "Sum = " << complexSum.real << " " << signOfImag << " " << complexSum.imag << "i" << endl;

    return 0;
}

// Function definition to add two complex numbers
complexNumber addComplexNumbers(complexNumber num1, complexNumber num2) {
    complexNumber temp;
    temp.real = num1.real + num2.real;
    temp.imag = num1.imag + num2.imag;
    return temp;
}
