/*
19.	Сортировки методом выборки и поразрядной
*/

#include <iostream>
#include <chrono>
using namespace std;

// Функция для проверки вводимого значения
int inputInt() 
{
    int number;

    // Проверка на соответствие типу Integer
    while ((!(cin >> number) || (cin.peek() != '\n'))) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Повторите ввод:\n  > ";
    }

    // Проверка числа на положительность
    if (number <= 0) {
        cout << "Повторите ввод:\n  > ";
        number = inputInt();
    }

    return number;
}

// Функция вывода массива
void printArray(int array[], int size)
{
    cout << "  ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

// Функция сортировки выборки
void selectionSort(int array[], int size)
{
    int countCompare = 0; // количество сравнений
    int countSwap = 0;    // количество перестановок

    auto begin = chrono::high_resolution_clock::now();
    for (int step = 0; step < size - 1; ++step)
    {
        int minIndex = step;

        for (int i = step + 1; i < size; ++i)
        {
            countCompare++;
            if (array[i] < array[minIndex]) {
                countSwap++;
                minIndex = i;
            }
        }

        // Перестановка чисел в массиве
        int temp = array[minIndex];
        array[minIndex] = array[step];
        array[step] = temp;
    }
    auto end = chrono::high_resolution_clock::now(); // конечное время
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

    printArray(array, size);

    cout << "\n";
    cout << "  Количество сравнений:    " << countCompare << "\n";
    cout << "  Количество перестановок: " << countSwap << "\n";
    cout << "  Время работы сортировки: " << time << " ns" << endl;
}

// Функция получения максимального числа в массиве
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

    // Для отладки - количество индексов у чисел
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

        // Для отладки - значение и его позиция
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

// Функция поразрядной сортировки
void radixsort(int array[], int size) 
{
    int countSwap = 0;    // количество перестановок

    auto begin = chrono::high_resolution_clock::now();

    // Получаем максимальный элемент в массиве
    // Необходим для подсчета количества цифр в числе
    int max = getMax(array, size);

    // Используем сортировку по индексу цифры в массиве
    // 0 - последнее число в цифре, 10 - второе и т.д.
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
        countSwap++;
    }
    auto end = chrono::high_resolution_clock::now(); // конечное время
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

    printArray(array, size);

    cout << "\n";
    cout << "  Количество сравнений:    Нет"  << "\n";
    cout << "  Количество перестановок: " << countSwap << "\n";
    cout << "  Время работы сортировки: " << time << " ns" << endl;
}

int main()
{
    srand(time(0)); // генерация случайных чисел
    setlocale(LC_ALL, "Russian");

    cout << "Правила: \n";
    cout << "  1. Значение должно быть положительным\n\n";

    cout << "Введите длину массива:\n  > ";
    int sizeArray = inputInt();

    // Заполнение массива рандомными числами
    int* аrray = new int[sizeArray];
    for (int i = 0; i < sizeArray; i++) {
        аrray[i] = rand() % + 40;
    }

    cout << "\n";
    cout << "Первоначальный массив:\n";
    printArray(аrray, sizeArray);

    // Копирование массива
    int* bаrray = new int[sizeArray];
    for (int i = 0; i < sizeArray; i++) {
        bаrray[i] = аrray[i];
    }

    cout << "\n";
    cout << "Отсортированный массив выборной сортировки:\n";
    selectionSort(аrray, sizeArray);

    cout << "\n";
    cout << "Первоначальный массив:\n";
    printArray(bаrray, sizeArray); 
    
    cout << "\n";
    cout << "Отсортированный массив поразрядной сортировкой:\n";
    radixsort(bаrray, sizeArray);
}
