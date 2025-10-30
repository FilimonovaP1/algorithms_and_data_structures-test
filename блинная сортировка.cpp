#include <iostream>
#include <vector>
using namespace std;

// Вспомогательная функция для перевертывания подмассива
void flip(vector<int>& arr, int endIndex) {
    int start = 0;
    while (start < endIndex) {
        swap(arr[start], arr[endIndex]); // Меняем местами первый и последний элементы подмассива
        start++;                         // Переходим к следующему элементу слева
        endIndex--;                      // Уменьшаем конец подмассива справа
    }
}

// Основная функция для блиновой сортировки
void pancakeSort(vector<int>& arr) {
    int currentSize = arr.size();      // Текущий размер несортированного участка массива
    while (currentSize > 1) {           // Пока есть хотя бы два элемента для сортировки
        // Шаг 1: Находим индекс самого большого элемента в текущей несортированной части
        int maxElementIndex = 0;
        for (int j = 1; j < currentSize; j++) {
            if (arr[j] > arr[maxElementIndex]) {
                maxElementIndex = j;     // Запоминаем позицию максимального элемента
            }
        }
        
        // Шаг 2: Переворачиваем массив так, чтобы самый большой элемент стал первым
        if (maxElementIndex != currentSize - 1) {
            flip(arr, maxElementIndex);  // Переворот первого отрезка массива до максимальной позиции
            
            // Шаг 3: Переворачиваем всю текущую несортированную часть массива, чтобы поставить наибольший элемент на своё место
            flip(arr, currentSize - 1); // Переворот всей текущей несортированной части
        }
    }
