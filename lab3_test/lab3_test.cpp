// Radix Sort in C++ Programming

#include <iostream>
using namespace std;

// Функция для получения максимального элемента из массива
int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Функция сортировки. Сортирует массив по заданному индексу цифры в массиве
void countingSort(int array[], int size, int place) {

    const int max = 10; // максимальная длина числа
    int* output = new int[size]; // выходной массив
    int count[max]; // количество индексов у чисел 

    // Заполняем массив нулями
    for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }
        
    // Подсчитываем количество одинаковых индексов у чисел
    // Пример: a[i] = m; i индекс встречается m раз
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    // Для отладки
    // printArray(count, size);

    // Изменим значения так, чтобы они содержали
    // фактическое положение цифры в массиве output
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    // Для отладки
    // printArray(count, size);

    // Формируем отсортированный массив с помощью count массива
    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];

        // Для отладки
        // cout << output[count[(array[i] / place) % 10] - 1] << " " << count[(array[i] / place) % 10] - 1 << "\n";

        count[(array[i] / place) % 10]--;
    }

    // Для отладки - промежуточные массивы
    // printArray(output, size);

    // Копируем отсортированный массив в наш массив
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void radixsort(int array[], int size) {

    // Получаем максимальный элемент в массиве
    // Необходим для подсчета количества цифр в числе
    int max = getMax(array, size);

    // Используем сортировку по индексу цифры в массиве
    // 0 - последнее число в цифре, 10 - второе и т.д.
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

int main() {
    int array[] = { 121, 432, 23, 33, 3, 789, 788 };
    int n = sizeof(array) / sizeof(array[0]);
    radixsort(array, n);
    printArray(array, n);
}