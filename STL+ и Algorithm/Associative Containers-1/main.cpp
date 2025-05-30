#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> seen_numbers; // Множество для хранения ранее встреченных чисел
    int number;

    // Чтение чисел из входного потока
    while (std::cin >> number) {
        if (seen_numbers.count(number) > 0) {
            std::cout << "YES\n"; // Число уже встречалось
        } else {
            std::cout << "NO\n"; // Число встречается впервые
            seen_numbers.insert(number); // Добавляем число в множество
        }
    }

    return 0;
}