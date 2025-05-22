#include <iostream>
#include "password.h"

int main() {
    system("chcp 65001");

    try {
        std::string password = get_password();

        std::cout << "Пароль корректен: " << password << std::endl;
    } catch (const PasswordError& e) {
        std::cerr << e.message() << std::endl;
    }

    return 0;
}