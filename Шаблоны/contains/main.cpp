#include "contains.h"
#include <iostream>
#include <string>

template <typename T>
void showArray(const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    system("chcp 65001");
    // Тип инт
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    int searchInt = 3;
    std::cout << "Содержится ли " << searchInt << " в списке?: " << (contains(searchInt, intArray, intSize) ? "Да" : "Нет") << std::endl;
    showArray(intArray, intSize);

    std::cout << '\n';

    // Тип дабл
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double searchDouble = 5.5;
    std::cout << "Содержится ли " << searchDouble << " в списке?: " << (contains(searchDouble, doubleArray, doubleSize) ? "Да" : "Нет") << std::endl;
    showArray(doubleArray, doubleSize);

    std::cout << '\n';

    // Тип стринг
    std::string stringArray[] = {"Черемша", "гофрированная бумага", "ананас"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    std::string searchString = "Черемша";
    std::cout << "Содержится ли '" << searchString << "' в списке?: " << (contains(searchString, stringArray, stringSize) ? "Да" : "Нет") << std::endl;
    showArray(stringArray, stringSize);

    return 0;
}