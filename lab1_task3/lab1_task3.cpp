/*
29.	Найти сумму дробей 1/(i1, i2, … , im) 
по всем подмножествам {i1, i2, … , im} множества {1, 2, …, n}.
*/

#include <iostream>
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

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Правила: \n";
    cout << "  1. Значения должны быть положительными\n\n";

    cout << "Для корректного отображения результатов рекомендуется\n";
    cout << "вводить количество множеств больше суммы подмножеств\n\n";

    cout << "Введите количество подмножеств:\n  > ";
    int countSubset = inputInt();

    // Вычисление суммы подмножеств
    int sumSubset = 0;
    for (int currentSubset = 1; currentSubset <= countSubset; currentSubset++) {
        sumSubset += currentSubset;
    }
    std::cout << "\nСумма подмножеств: " << sumSubset << "\n\n";

    cout << "Введите количество множеств:\n  > ";
    int countSet = inputInt();

    // Вычисление суммы множеств
    double sumSet = 0;
    for (int currentSet = 1; currentSet <= countSet; currentSet++) {
        sumSet += currentSet/sumSubset;
    }
    std::cout << "\nСумма множеств: " << sumSet << "\n";

}