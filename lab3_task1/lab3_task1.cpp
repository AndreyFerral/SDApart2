/*
9.	Метод пузырьков и метод выбора
*/

#include <iostream>
#include <chrono>
using namespace std;

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

void printArray(int array[], int size)
{
    cout << "  ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } 
    cout << "\n";
}

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

void bubbleSort(int array[], int size) 
{
    int countCompare = 0; // количество сравнений
    int countSwap = 0;    // количество перестановок

    auto begin = chrono::high_resolution_clock::now();
    for (int step = 0; step < size - 1; ++step) 
    {
        for (int i = 0; i < size - (step + 1); ++i) 
        {
            countCompare++;
            if (array[i] > array[i + 1]) 
            {
                countSwap++;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    auto end = chrono::high_resolution_clock::now(); // конечное время
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

    printArray(array, size);

    cout << "\n";
    cout << "  Количество сравнений:    " << countCompare << "\n";
    cout << "  Количество перестановок: " << countSwap << "\n";
    cout << "  Время работы сортировки: " << time << " ns" << endl;

}

void bubbleSortOld(int array[], int size) 
{
    int secondToLast = size - 1; // Индекс предпоследнего элемента
    int countCompare = 0; // количество сравнений
    int countSwap = 0;    // количество перестановок

    bool isSwap = false; // Произошла ли перестановка

    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0; i < secondToLast; i++) {
        countCompare++;

        if (array[i] > array[i + 1]) {

            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;

            isSwap = true;
            countSwap++;

        }

        if (i == secondToLast-1) {
            if (isSwap) { 
                i -= secondToLast; 
                isSwap = false;
            }
        }
    }
    auto end = chrono::high_resolution_clock::now(); // конечное время
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

    printArray(array, size);

    cout << "\n";
    cout << "  Количество сравнений:    " << countCompare <<"\n";
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
        аrray[i] = rand() % 41 - 20;
    }

    //int array[10] = {-5, 6, -7, 8, -9, 10, -11, 12, -13, 10};

    cout << "\n";
    cout << "Первоначальный массив:\n";
    printArray(аrray, sizeArray); cout << "\n";

    int* bаrray = new int[sizeArray];
    for (int i = 0; i < sizeArray; i++) {
        bаrray[i] = аrray[i];
    }

    cout << "Отсортированный массив методом пузырька:\n";
    bubbleSort(аrray, sizeArray);

    cout << "\n";
    cout << "Первоначальный массив:\n";
    printArray(bаrray, sizeArray); cout << "\n";

    cout << "Отсортированный массив методом выборки:\n";
    selectionSort(bаrray, sizeArray);



}
