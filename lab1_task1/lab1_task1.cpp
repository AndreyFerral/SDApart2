/*
9.	Перебрать все монотонно невозрастающие сюръекции f: [m] -> [n].
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

    /*
    cout << "Введите количество значений в первом множестве:\n  > ";
    int firstCountNumbers = inputInt();

    cout << "Введите количество значений во втором множестве:\n  > ";
    int secondCountNumbers = inputInt();
    */

    int firstSetNumbers[3] = { 5, 8, 9 };
    int secondSetNumbers[4] = { 5, 10, 12, 15 };

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            int f = i % 3;
            cout << "{" << firstSetNumbers[f] << ", " << secondSetNumbers[j] << "}" << " ";
        }
        cout << "\n";
    }

    //std::cout << "Вариант 9\n";
    //std::cout << firstSet << " " << secondSet;
}