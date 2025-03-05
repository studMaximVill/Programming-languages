#include <vector>
#include <string>
#include "car.h"
using namespace std;

vector<Car> readFile(const string& file);
void sortByYear(vector<Car>& cars);
void sortByBrand(vector<Car>& cars);
void printCars(const vector<Car>& cars);