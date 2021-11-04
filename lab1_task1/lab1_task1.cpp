/*
9.	Перебрать все монотонно невозрастающие сюръекции f: [m] -> [n].
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Surjection {

    int countSurjection = 1; // подсчет количества сюръекций

    static const int maxSizeSet = 8; // максимальный размер множеств
    int sizeFirstSet = maxSizeSet;   // размерность первого множества
    int sizeSecondSet = maxSizeSet;  // размерность второго множества

    int numbersFirstSet[maxSizeSet] = { 1, 2, 3, 4, 5, 6, 7, 8 }; // элементы первого множества
    char lettersSecondSet[maxSizeSet] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' }; // элементы второго множества

    int* firstSet = new int[sizeSecondSet]; // элементы первого множества на позициях второго множества
    int* color = new int[sizeFirstSet];     // вспомогательный массив для проверки финального массива

public:

    Surjection() {

        // Заполняем массивы нулевыми значения
        for (int i = 0; i < maxSizeSet; i++)
        {
            color[i] = 0;
            firstSet[i] = 0;
        }
    }

    // Метод для проверки вводимого значения первого множества
    int inputInt() {
        int number;

        cout << "  Установите размерность для первого множества:\n  > ";

        // Проверка на соответствие типу Integer
        while ((!(cin >> number) || (cin.peek() != '\n'))) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  Установите размерность для первого множества:\n  > ";
        }

        // Число должно быть от 1 до 8
        if (number < 1 || number > maxSizeSet) number = inputInt();
        return number;
    }

    // Метод для проверки вводимого значения второго множества
    int inputInt(int firstNumber) {
        int number;

        cout << "  Установите размерность для второго множества:\n  > ";

        // Проверка на соответствие типу Integer
        while ((!(cin >> number) || (cin.peek() != '\n'))) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  Установите размерность для второго множества:\n  > ";
        }

        // Число должно быть от firstNumber до 8
        if (number < firstNumber || number > maxSizeSet) number = inputInt(firstNumber);
        return number;
    }

    // Метод, в котором устанавливается размерность множеств
    void setSizes() {

        cout << "Правила: \n";
        cout << "  1. Значения должны быть положительными\n";
        cout << "  2. Размерность второго множества должна быть >= первого\n";
        cout << "  3. Максимальная размерность множеств - 8\n\n";

        sizeFirstSet = inputInt();
        sizeSecondSet = inputInt(sizeFirstSet);

        cout << endl;

        const int firstPosition = 0;
        setElementOnPosition(firstPosition);
    }

    // Метод для проверки и вывода готового массива
    void output() {

        // Выводим только те массивы, которые является монотонно невозрастающими
        for (int i = 0; i < sizeSecondSet - 1; i++)
        {
            if (firstSet[i] < firstSet[i + 1]) return;
        }

        bool isWrongArray = false; // isWrongArray - массив не соответствует условиям

        // Заполняем вспомогательный массив, в котором
        // 1 - данная цифра имеется в массиве, 0 - не имеется
        for (int i = 0; i < sizeSecondSet; i++)
        {
            for (int j = 0; j < sizeFirstSet; j++)
            {
                if (firstSet[i] == numbersFirstSet[j]) color[j] = true;
            }
        }

        // Просматриваем каждый элемент вспомогательного массива
        for (int i = 0; i < sizeFirstSet; i++)
        {
            // Если в массиве не было найдено всех элементов из массива (значение 0)
            if (color[i] == false) isWrongArray = true;

            // cout << color[i] << " ";

            // Очищаем массив
            color[i] = false;
        }
        // cout << endl;

        // Не выводим массив на экран, если в нём не все элементы
        if (isWrongArray) {
            // Если сразу прерывать метод, то массив color[] не очистится
            return;
        }

        // Выводим номер массива на экран
        cout << setw(5) << countSurjection << ") ";
        countSurjection++;

        // Выводим массив на экран
        for (int i = 0; i < sizeSecondSet; i++)
        {
            cout << firstSet[i] << lettersSecondSet[i] << " ";
        }
        cout << endl;
    }

    // Рекурсивный метод для построения массива
    void setElementOnPosition(int position) {

        // Если на всех позициях установлены элементы
        if (position == sizeSecondSet) {

            output();
            return;
        }

        for (int i = 0; i < sizeFirstSet; i++)
        {
            // Устанавливаем элемент на позицию
            firstSet[position] = numbersFirstSet[i];

            // Вызываем рекурсию для последующих позиций
            setElementOnPosition(position + 1);

            // Очищаем массив
            firstSet[position] = 0;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");

    Surjection surjection;
    surjection.setSizes();
}