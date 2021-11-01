/*
9.	Для заданных входных данных продемонстрировать метод простых пузырьков.
*/

#include <iostream>
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

// Функция пузырьковой сортировки
void bubbleSort(int array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - (step + 1); ++i)
        {
            if (array[i] > array[i + 1])
            {
                cout << "  ";
                cout << "Перестановка " << array[i] << " и " << array[i + 1] << ":\n";

                // Перестановка чисел в массиве
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                printArray(array, size);
            }
        }
    }

    cout << "\n";
    cout << "Отсортированный массив пузырьковой сортировкой:\n";
    printArray(array, size);
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
    printArray(аrray, sizeArray);

    cout << "\n";
    bubbleSort(аrray, sizeArray);
}
