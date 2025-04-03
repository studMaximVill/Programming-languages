#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"
using namespace std;

int main() {
    Summator summator;
    SquareSummator squareSummator;
    CubeSummator cubeSummator;

    int N = 3;
    cout << "Summator: " << summator.sum(N) << endl;
    cout << "SquareSummator: " << squareSummator.sum(N) << endl;
    cout << "CubeSummator: " << cubeSummator.sum(N) << endl;

    cout << '\n';

    Summator* laterSummator;
    laterSummator = &summator;
    cout << "Later Summator: " << laterSummator->sum(N) << endl;
    laterSummator = &squareSummator;
    cout << "Later SquareSummator: " << laterSummator->sum(N) << endl;
    laterSummator = &cubeSummator;
    cout << "Later CubeSummator: " << laterSummator->sum(N) << endl;

    return 0;
}