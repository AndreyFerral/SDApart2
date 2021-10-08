/*
19.	Организовать перебор последовательностей целых чисел 
    n >= x1 >= … >= xm >= 0.
*/

#include <iostream>
using namespace std;

// Функция для проверки вводимого значения
int inputInt() {
    int number;

    cout << "Введите первое значение:\n  > ";

    // Проверка на соответствие типу Integer
    while ((!(cin >> number) || (cin.peek() != '\n'))) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите первое значение:\n  > ";
    }

    // Проверка числа на положительность
    if (number < 0) number = inputInt();
    return number;
}

// Функция для проверки вводимого значения
int inputInt(int firstNumber) {
    int number;

    cout << "Введите второе значение:\n  > ";

    // Проверка на соответствие типу Integer
    while ((!(cin >> number) || (cin.peek() != '\n'))) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите второе значение:\n  > ";
    }

    // Проверка числа - больше ли другого
    if (number <= firstNumber) number = inputInt(firstNumber);
    return number;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Правила: \n";
    cout << "  1. Первое значение должно быть меньше второго\n";
    cout << "  2. Значения должны быть положительными\n\n";

    int m = inputInt();
    int n = inputInt(m);

    cout << "\nВвёденные числа: " << m << " " << n << "\n\n";

    // Вывод чисел
    for (int number = m; number <= n; number++) {
        cout << number << " ";
    } cout << "\n";
}