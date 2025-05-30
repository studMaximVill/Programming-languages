#include <vector>
#include <list>
#include <array>
#include "print.h"

int main() {
    // Целые числв
    std::vector<int> digit = {1, 2, 3};
    Print(digit, ", ");

    // Дробные числа
    std::array<double, 4> fDigit = {1.1, 2.2, 3.3, 4.4};
    Print(fDigit, " | ");

    // Строки
    std::list<std::string> str = {"Vill", "Maxim", "Sergeevich"};
    Print(str, " - ");

    return 0;
}