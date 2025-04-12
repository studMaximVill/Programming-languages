#include <iostream>
#include "Complex.h"

void TaskComplex() {
    // Вывод чисел
    std::cout << "Real and imaginary parts of the first complex number: " << std::endl;
    Complex z1{ 2, 3 };
    std::cout << "first complex number: ";
    z1.Print();

    std::cout << '\n';

    std::cout << "Real and imaginary parts of the second complex number: " << std::endl;
    Complex z2{ 2, 3 };
    std::cout << "second complex number: ";
    z2.Print();



    // Арифметические операции
    Complex sum = z1.Add(z2);
    std::cout << "\nSum: ";
    sum.Print();

    Complex diff = z1.Sub(z2);
    std::cout << "Difference: ";
    diff.Print();

    Complex prod = z1.Mult(z2);
    std::cout << "Work: ";
    prod.Print();

    Complex quot = z1.Div(z2);
    std::cout << "Private: ";
    quot.Print();
}

int main() {

    TaskComplex();

    return 0;
}