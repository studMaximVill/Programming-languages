#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template <typename T>
class Matrix {
    size_t rows;    // Количество строк
    size_t cols;    // Количество столбцов
    std::vector<std::vector<T>> data; // Двумерный массив для хранения данных

public:
    // Конструктор по умолчанию
    Matrix() : rows(0), cols(0) {}

    // Конструктор с параметрами
    Matrix(size_t r, size_t c, const T& defaultValue = T());

    // Деструктор
    ~Matrix() {}

    // Методы Set и Get
    void Set(size_t i, size_t j, const T& value);
    T Get(size_t i, size_t j) const;

    // Оператор сложения двух матриц
    Matrix operator+(const Matrix& other) const;

    // Оператор умножения двух матриц
    Matrix operator*(const Matrix& other) const;

    // Операторы потокового ввода-вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    // Геттеры для размеров матрицы
    size_t Rows() const { return rows; }
    size_t Cols() const { return cols; }
};

// Реализация конструктора с параметрами
template <typename T>
Matrix<T>::Matrix(size_t r, size_t c, const T& defaultValue) : rows(r), cols(c), data(r, std::vector<T>(c, defaultValue)) {}

// Реализация метода Set
template <typename T>
void Matrix<T>::Set(size_t i, size_t j, const T& value) {
    if (i >= rows or j >= cols) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    data[i][j] = value;
}

// Реализация метода Get
template <typename T>
T Matrix<T>::Get(size_t i, size_t j) const {
    if (i >= rows or j >= cols) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return data[i][j];
}

// Реализация оператора сложения
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
    if (rows != other.rows or cols != other.cols) {
        throw std::invalid_argument("Размер должен быть одинаковым");
    }
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Реализация оператора умножения
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Кол-во столбцов в первой должно быть = кол-ву строк во второй");
    }
    Matrix result(rows, other.cols, T());
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

#endif // MATRIX_H