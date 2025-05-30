#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t original_size = v.size(); // Запоминаем исходный размер вектора
    for (size_t i = 0; i < original_size; ++i) {
        v.push_back(v[i]); // Добавляем элементы в конец
    }
}

int main() {
    // Целые числа
    std::vector<int> numbers = {1, 2, 3};
    Duplicate(numbers);
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";

    // Строки
    std::vector<std::string> words = {"hello", "world"};
    Duplicate(words);
    for (const std::string& word : words) {
        cout << word << " ";
    }
    cout << "\n";

    return 0;
}