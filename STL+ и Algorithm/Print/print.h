#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
using namespace std;

template <typename Container>
void Print(const Container& container, const std::string& delimiter) {
    bool first = true; // Флаг для первого элемента
    for (const auto& element : container) {
        if (!first) {
            cout << delimiter; // Выводим разделитель перед каждым элементом, кроме первого
        }
        cout << element;
        first = false;
    }
    cout << '\n';
}

#endif // PRINT_H