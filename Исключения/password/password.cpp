#include "password.h"
#include <iostream>
#include <cctype> // isdigit, isupper, islower

// Проверка на наличие запрещённых символов
bool hasForbiddenCharacters(const std::string& password) {
    const std::string forbidden = "lIoO01";
    for (char c : password) {
        if (forbidden.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

std::string get_password() {
    std::string password;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    // Проверка длины пароля
    if (password.length() < 9) {
        throw LengthError();
    }

    // Проверка регистра символов
    bool hasUpper = false, hasLower = false;
    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        if (std::islower(c)) hasLower = true;
    }
    if (!hasUpper || !hasLower) {
        throw RegisterError();
    }

    // Проверка наличия цифр
    bool hasDigit = false;
    for (char c : password) {
        if (std::isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        throw DigitError();
    }

    // Проверка на запрещённые символы
    if (hasForbiddenCharacters(password)) {
        throw ForbiddenLetterError();
    }

    return password;
}