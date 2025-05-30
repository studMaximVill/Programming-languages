#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    std::unordered_map<std::string, int> count; // Счетчики для каждого слова
    std::string word;

    while (std::cin >> word) {
        count[word]++;

        cout << count[word] << '\n';
    }

    return 0;
}