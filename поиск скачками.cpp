#include <iostream>
#include <cmath> // sqrt()
#include <vector>
using namespace std;

// Основная функция поиска скачками
int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();                  // Длина массива
    int step = sqrt(n);                  // Величина шага равна корню из длины массива
    int prev = 0;                        // Начальное положение

    // Первый этап: прыгайте вперед по шагам, пока элемент меньше цели
    while (prev < n && arr[min(prev + step, n)-1] < target) {
        prev += step;                    // Переход на следующую точку
    }

    // Второй этап: теперь используем бинарный поиск на небольшом диапазоне
    int low = prev - step;               // Левая граница нового диапазона
    int high = min(prev, n);            // Правая граница нового диапазона

    // Обычная реализация бинарного поиска в найденном диапазоне
    while (low <= high) {
        int mid = low + (high - low) / 2; // Средняя точка
        if (arr[mid] == target) {
            return mid;                  // Нашли элемент!
        } else if (arr[mid] < target) {
            low = mid + 1;               // Продолжаем искать вправо
        } else {
            high = mid - 1;              // Продолжаем искать влево
        }
    }

    return -1;                          // Не нашли целевой элемент
}

// Тестовая функция для проверки работоспособности
int main() {
    vector<int> arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int key = 55;                       // Целевой элемент для поиска

    int result = jumpSearch(arr, key);  // Вызов функции поиска

    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        cout << "Элемент не найден." << endl;
    }

    return 0;
}