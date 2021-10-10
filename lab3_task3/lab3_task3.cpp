/*
29.	Сортировка быстрым и пирамидальным методом
*/

#include <iostream>
#include <chrono>
using namespace std;

int countCompare = 0; // количество сравнений
int countSwap = 0;    // количество перестановок

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

// Функция для обмена элементов
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

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

// Функция быстрой сортировки
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


// Функция для построения максимальной кучи в переданном поддереве
void heapify(int array[], int size, int root)
{
    int largest = root;   // Инициализируем корень наибольшим элементом
    int l = 2 * root + 1; // Индекс левого поддерева корня
    int r = 2 * root + 2; // Индекс правого поддерева корня

    // Увеличиваем счетчик сравнений
    countCompare += 2; // Два сравнения происходит в функции

    // Если левое поддерево больше корня
    if (l < size && array[l] > array[largest])
    {
        largest = l;
    }

    // Если правое поддерево больше текущего наибольшего элемента (или корень, или левое поддерево)
    if (r < size && array[r] > array[largest])
    {
        largest = r;
    }

    // Если наибольший элемент не корень, то меняем элементы местами 
    if (largest != root)
    {
        swap(&array[root], &array[largest]);

        // Рекурсивно вызываем функцию для поддерева,
        // пока оно не будет являться максимальной кучей
        heapify(array, size, largest);
    }
}

// Функция пирамидальной сортировки
void heapSort(int array[], int size)
{
    // Строим максимальную кучу - у каждого
    // родителя корни меньше его самого
    // n / 2 - 1 - и меньше это корни, элементы справа - не корни

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);

        // Для отладки 
        // printArray(arr, n);
    }

    // Для отладки 
    // cout << "Максимальная куча построена\n";

    // По одному элементы с корня перемещаем в конец
    for (int i = size - 1; i > 0; i--) {

        // Перемещаем текущий корень в конец
        // ps Текущий корень - максимальное число

        // Следовательно, постепенно максимальные 
        // элементы будут перемещены в конец

        swap(&array[0], &array[i]);

        // Для отладки
        // printArray(arr, n);

        // Строим максимальную кучу в измененнем поддереве
        heapify(array, i, 0);

        // Для отладки
        // printArray(arr, n);
        // cout << "Следующая итерация\n";
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
    printArray(аrray, sizeArray);

    auto begin1 = chrono::high_resolution_clock::now();
    quickSort(аrray, 0, sizeArray - 1);
    auto end1 = chrono::high_resolution_clock::now(); // конечное время
    auto time1 = chrono::duration_cast<chrono::nanoseconds>(end1 - begin1).count(); // искомое время

    cout << "\n";
    cout << "Отсортированный массив быстрой сортировкой:\n";
    printArray(аrray, sizeArray);

    cout << "\n";
    cout << "  Количество сравнений:    " << countCompare << "\n";
    cout << "  Количество перестановок: " << countSwap << "\n";
    cout << "  Время работы сортировки: " << time1 << " ns" << endl;

    // Обнуляем счетчики
    countCompare = 0;
    countSwap = 0;

    // Копирование массива
    int* bаrray = new int[sizeArray];
    for (int i = 0; i < sizeArray; i++) {
        bаrray[i] = аrray[i];
    }

    cout << "\n";
    cout << "Первоначальный массив:\n";
    printArray(bаrray, sizeArray);

    auto begin2 = chrono::high_resolution_clock::now();
    heapSort(bаrray, sizeArray);
    auto end2 = chrono::high_resolution_clock::now(); // конечное время
    auto time2 = chrono::duration_cast<chrono::nanoseconds>(end2 - begin2).count(); // искомое время

    cout << "\n";
    cout << "Отсортированный массив пирамидальной сортировкой:\n";
    printArray(bаrray, sizeArray);

    cout << "\n";
    cout << "  Количество сравнений:    " << countCompare << "\n";
    cout << "  Количество перестановок: " << countSwap << "\n";
    cout << "  Время работы сортировки: " << time2 << " ns" << endl;
}