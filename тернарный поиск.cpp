#include <iostream>
#include <cmath> // Для abs()
using namespace std;

// Конкретная функция для оптимизации (пример выпуклой функции)
double convexFunction(double x) {
    return pow(x, 2) + 5*x + 6; // Простая парабола y=x^2+5x+6
}

// Основная функция тернарного поиска минимума
double ternarySearch(double lo, double hi, double epsilon=1e-6) {
    while ((hi - lo) > epsilon) { // Остановимся, когда интервал сузился до заданной точности
        double third = (hi - lo) / 3.0; // Треть интервала
        double m1 = lo + third;         // Первая контрольная точка
        double m2 = hi - third;         // Вторая контрольная точка
        
        // Сравниваем значения функции в точках m1 и m2
        if (convexFunction(m1) < convexFunction(m2)) {
            hi = m2; // Минимум находится левее второй точки
        } else {
            lo = m1; // Минимум находится правее первой точки
        }
    }
    return (lo + hi) / 2.0; // Вернуть среднее арифметическое концов интервала
}

// Тестовая функция
int main() {
    double lowerBound = -10.0; // Нижняя граница интервала
    double upperBound = 10.0;  // Верхняя граница интервала
    double minimumPoint = ternarySearch(lowerBound, upperBound);

    cout << "Минимум функции достигается в точке: " << minimumPoint << endl;
    cout << "Значение функции в этой точке: " << convexFunction(minimumPoint) << endl;

    return 0;
}