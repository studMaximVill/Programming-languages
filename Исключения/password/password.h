#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <stdexcept>

class PasswordError : public std::exception {
public:
    virtual const char* message() const = 0;
};

class LengthError : public PasswordError {
public:
    const char* message() const override {
        return "Ошибка: Пароль должен содержать не менее 9 символов.";
    }
};

class RegisterError : public PasswordError {
public:
    const char* message() const override {
        return "Ошибка: Пароль должен содержать буквы разных регистров.";
    }
};

class DigitError : public PasswordError {
public:
    const char* message() const override {
        return "Ошибка: Пароль должен содержать хотя бы одну цифру.";
    }
};

class ForbiddenLetterError : public PasswordError {
public:
    const char* message() const override {
        return "Ошибка: Пароль содержит запрещённые символы (l, I, 1, o, O, 0).";
    }
};

std::string get_password();

#endif // PASSWORD_H