#include "inicializations.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<Car> readFile(const string& file) {
    vector<Car> cars;
    ifstream File(file);
    if (!File.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return cars;
    }

    Car car;
    while (File >> car.brand >> car.model >> car.year >> car.price) {
        string electricCarStr;
        File >> electricCarStr;
        car.electricCar = (electricCarStr == "true");
        cars.push_back(car);
    }
    File.close();
    return cars;
}

void sortByYear(vector<Car>& cars) {
    int n = cars.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (cars[j].year < cars[j + 1].year) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }
}

void sortByBrand(vector<Car>& cars) {
    int n = cars.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (cars[j].brand > cars[j + 1].brand) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }
}

void printCars(const vector<Car>& cars) {
    cout << "Марка\tМодель\tГод\tЦена\tЭлектрокар" << endl;
    for (const auto& car : cars) {
        cout << car.brand << '\t' << car.model << '\t' << car.year << '\t' << car.price << '\t'
            << (car.electricCar ? "Да" : "Нет") << endl;
    }
}