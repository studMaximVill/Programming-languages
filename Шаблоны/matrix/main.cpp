#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

int main() {
    system("chcp 65001");

    // Числовой тип данных
    cout << "Числовая матрица:" << endl;
    Matrix<int> mat1(2, 2, 1);
    Matrix<int> mat2(2, 2, 2);

    cout << "Матрица 1:" << endl;
    cout << mat1;

    cout << "Матрица 2:" << endl;
    cout << mat2;

    Matrix<int> sum = mat1 + mat2;
    cout << "\nСумма:" << endl;
    cout << sum;

    Matrix<int> product = mat1 * mat2;
    cout << "Произведение:" << endl;
    cout << product;

    // Строковый тип данных
    cout << "\nСтроковая матрица:" << endl;
    Matrix<std::string> mat3(2, 2, "a");
    Matrix<std::string> mat4(2, 2, "b");

    cout << "Матрица 3:" << endl;
    cout << mat3;

    cout << "Матрица 4:" << endl;
    cout << mat4;

    Matrix<std::string> sumStrings = mat3 + mat4;
    cout << "\nСумма:" << endl;
    cout << sumStrings;

    // Ввод матрицы из потока
    cout << "\nВведите числовую матрицу 2х2:" << endl;
    Matrix<int> mat5(2, 2);
    cin >> mat5;
    cout << "Вы ввели:" << endl;
    cout << mat5;

    return 0;
}