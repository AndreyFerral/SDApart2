/*
29.	Сортировка быстрым и пирамидальным методом
*/

#include <iostream>
#include <chrono>
using namespace std;

int countCompare = 0; // количество сравнений
int countSwap = 0;    // количество перестановок

// Функция для проверки вводимого значения
int inputInt() {
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

// Функция для обмена элементов
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;

    // Увеличваем счетчик перестановок
    countSwap++;
}

// Функция для поиска разделителя массива
int partition(int array[], int low, int high)
{
    int pivot = array[high]; // выбираем правый элемент как разделитель
    int i = (low - 1);       // индекс для наибольшего элемента

    // Обходим каждый элемента массива, сравнивая с разделителем
    for (int j = low; j < high; j++) {

        // Увеличваем счетчик сравнений
        countCompare++;

        if (array[j] <= pivot)
        {
            // Если найден элемент меньше разделителя,
            // то меняем местами элемент i с элементом j
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // меняем местами разделитель с наибольшим элементом 
    swap(&array[i + 1], &array[high]);

    // возвращаем разделитель
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // Находим индекс элемента, при котором
        // элементы слева - меньше его
        // элементы справа - больше его
        int pi = partition(array, low, high);

        // Рекурсивный вызов для левой части от разделителя
        quickSort(array, low, pi - 1);

        // Рекурсивный вызов для правой части от разделителя
        quickSort(array, pi + 1, high);
    }
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
        аrray[i] = rand() % 41 - 20;
    }

    cout << "\n";
    cout << "Первоначальный массив:\n";
    printArray(аrray, sizeArray); cout << "\n";

    auto begin = chrono::high_resolution_clock::now();
    quickSort(аrray, 0, sizeArray - 1);
    auto end = chrono::high_resolution_clock::now(); // конечное время
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

    cout << "\n";
    cout << "Отсортированный массив быстрой сортировкой:\n";
    printArray(аrray, sizeArray); cout << "\n";

    cout << "\n";
    cout << "  Количество сравнений:    " << countCompare << "\n";
    cout << "  Количество перестановок: " << countSwap << "\n";
    cout << "  Время работы сортировки: " << time << " ns" << endl;

    // Обнуляем счетчики
    countCompare = 0;
    countSwap = 0;

}