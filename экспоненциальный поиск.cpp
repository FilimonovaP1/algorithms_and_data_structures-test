#include <iostream>
#include <vector>
#include <climits> // INT_MAX
using namespace std;

// Функция для бинарного поиска
int binarySearch(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Безопасный расчет середины
        if (arr[mid] == target) {
            return mid; // Нашли элемент
        } else if (arr[mid] < target) {
            left = mid + 1; // Продолжаем поиск в правой половине
        } else {
            right = mid - 1; // Продолжаем поиск в левой половине
        }
    }
    return -1; // Элемент не найден
}

// Основной алгоритм экспоненциального поиска
int exponentialSearch(const vector<int>& arr, int target) {
    int n = arr.size();                            // Размер массива
    if (n == 0 || arr.front() > target || arr.back() < target) {
        return -1;                                 // Массив пуст или элемент вне диапазона
    }

    // Ищем подходящую зону для дальнейшего бинарного поиска
    int bound = 1;                                 // Начальный шаг
    while (bound < n && arr[bound] <= target) {    // Удвоение шага, пока не выйдем за пределы массива или не перейдем цель
        bound *= 2;
    }

    // Границы для бинарного поиска определяются последним успешным шагом
    int left = bound / 2;                          // Левая граница — последняя успешная позиция
    int right = min(bound, n - 1);                 // Правая граница — минимальная из последней позиции или конца массива

    // Применяем бинарный поиск внутри найденного диапазона
    return binarySearch(arr, left, right, target);
}

// Тестовая функция
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int target = 15;                               // Искать будем число 15

    int result = exponentialSearch(arr, target);   // Запускаем экспоненциальный поиск

    if (result != -1) {
        cout << "Искомый элемент найден на позиции: " << result << endl;
    } else {
        cout << "Искомый элемент не найден." << endl;
    }

    return 0;
}