#include <iostream>
#include <vector>
#include <algorithm> // std::sort() для внутренней сортировки внутри баков

// Функция для выполнения блочной сортировки
void bucketSort(std::vector<int>& array) {
    if (array.empty()) {  // Проверяем, пустой ли массив
        return;
    }

    size_t n = array.size();          // Получаем длину массива
    double maxValue = *std::max_element(array.begin(), array.end()); // Находим максимальный элемент
    double minValue = *std::min_element(array.begin(), array.end()); // Находим минимальный элемент

    // Вычисляем ширину интервала для разделения элементов по бакам
    double interval = (maxValue - minValue) / static_cast<double>(n);

    // Создаем вектор баков размером n
    std::vector<std::vector<int>> buckets(n);  

    // Заполняем баки элементами
    for (size_t i = 0; i < n; ++i) {
        // Индекс бака определяется относительно ширины интервала
        size_t index = static_cast<size_t>((array[i] - minValue) / interval);
        
        // Обрабатываем случай последнего индекса
        if (index >= n) {
            index = n - 1;
        }
        
        // Добавляем элемент в соответствующий бак
        buckets[index].push_back(array[i]);
    }

    // Сортируем элементы внутри каждого бака
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // Склеиваем отсортированные баки в исходный массив
    size_t idx = 0;
    for (const auto& bucket : buckets) {
        for (int val : bucket) {
            array[idx++] = val;
        }
    }
}

// Основная программа для тестирования
int main() {
    std::vector<int> inputArray = {8, 2, 9, 5, 1, 3};

    std::cout << "Исходный массив:\n";
    for (int x : inputArray) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // Выполнение блочной сортировки
    bucketSort(inputArray);

    std::cout << "\nОтсортированный массив:\n";
    for (int x : inputArray) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}