#include <iostream>
#include "inicializations.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    vector<Car> cars = readFile("cars.txt");

    if (cars.empty()) {
        cout << "Файл пуст" << endl;
        return 1;
    }

    cout << "Список автомобилей:" << endl;
    printCars(cars);

    sortByYear(cars);
    cout << "\nПо дате выпуска:" << endl;
    printCars(cars);

    sortByBrand(cars);
    cout << "\nПо алфавиту:" << endl;
    printCars(cars);

    return 0;
}