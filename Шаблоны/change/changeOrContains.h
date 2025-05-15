#ifndef CHANGEORCONTAINS_H
#define CHANGEORCONTAINS_H

#include <iostream>

// contains
template <typename T>
bool contains(const T& element, const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// change
template <typename T>
bool change(const T& elem1, const T& elem2, T* array, size_t size) {
    // Проверяем, есть ли оба элемента в массиве
    if (!contains(elem1, array, size)) {
        std::cout << "Элемент '" << elem1 << "' не найден." << std::endl;
        return false;
    }
    if (!contains(elem2, array, size)) {
        std::cout << "Элемент не найден '" << elem2 << "' не найден." << std::endl;
        return false;
    }

    // Находим индексы элементов
    size_t index1 = 0, index2 = 0;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == elem1) {
            index1 = i;
        }
        if (array[i] == elem2) {
            index2 = i;
        }
    }

    // Меняем местами
    std::swap(array[index1], array[index2]);

    std::cout << "Элементы '" << elem1 << "' и '" << elem2 << "' поменялись местами." << std::endl;
    return true;
}

#endif //CHANGEORCONTAINS_H
