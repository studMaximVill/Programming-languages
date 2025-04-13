#include <iostream>
#include "Complex.h"

int main() {
    // Создание объектов
    Complex z1(2, 3);
    Complex z2(1, 4);

    // Вывод начальных значений
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;

    std::cout << '\n';

    // Тестирование арифметических операций
    Complex sum = z1 + z2;
    std::cout << "z1 + z2 = " << sum << std::endl;

    Complex diff = z1 - z2;
    std::cout << "z1 - z2 = " << diff << std::endl;

    Complex prod = z1 * z2;
    std::cout << "z1 * z2 = " << prod << std::endl;

    Complex quot = z1 / z2;
    std::cout << "z1 / z2 = " << quot << std::endl;

    std::cout << '\n';

    // Тестирование инкремента и декремента
    ++z1;
    std::cout << "After ++z1: " << z1 << std::endl;

    z2--;
    std::cout << "After z2--: " << z2 << std::endl;

    std::cout << '\n';

    // Тестирование логических операций
    std::cout << "z1 > z2: " << (z1 > z2 ? "true" : "false") << std::endl;
    std::cout << "z1 < z2: " << (z1 < z2 ? "true" : "false") << std::endl;
    std::cout << "z1 == z2: " << (z1 == z2 ? "true" : "false") << std::endl;
    std::cout << "z1 != z2: " << (z1 != z2 ? "true" : "false") << std::endl;

    std::cout << '\n';

    // Тестирование ввода
    Complex z3;
    std::cout << "Enter a complex number for z3: " << std::endl;
    std::cin >> z3;
    std::cout << "You entered: " << z3 << std::endl;

    return 0;
}