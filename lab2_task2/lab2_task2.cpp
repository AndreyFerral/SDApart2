/*
19.	В центре шахматной доски стоит конь. 
Найти все расположения восьми ладей, не угрожающих друг другу, 
при которых конь не угрожает ни одной из ладей.
*/

#include <iostream>
using namespace std;

int number = 0;
const int sizeBoard = 8;
bool board[sizeBoard][sizeBoard], a[sizeBoard];

void output()
{
    cout << endl;

    // Выводим номер перестановки
    number = number + 1;
    cout << "Шахматная доска №" << number << "\n";

    // Выводим шахматную доску на экран
    for (int i = 0; i < sizeBoard; i++) {

        for (int j = 0; j < sizeBoard; j++) {

            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

void rec(int i)
{
    // Если шахматная доска заполнена, то выводим её
    if (i == 8)
    {
        output();
        return;
    }

    // Устанавливаем следующую ладью на всевозможные позиции (максимум 7, т.к. первая задана в точке входа)
    for (int j = 0; j < sizeBoard; j++)
    {
        // Проверяем, является ли это поле уже занятым (с учетом того, что это ладья) 
        if (!a[j])
        {
            // Устанавливаем ладья на позицию
            a[j] = true;
            board[i][j] = true;

            // Расстанавливаем ладьи на следующей горизонтале
            rec(i + 1);

            // Очищаем шахматную доску
            board[i][j] = false;
            a[j] = false;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // i - главная горизонталь, на остальных будут перестановки
    for (int i = 0; i < sizeBoard; i++)
    {
        // Устанавливаем ладья на позицию
        a[i] = true;
        board[0][i] = true;

        // Расстанавливаем ладьи на следующей горизонтале
        rec(1);

        // Очищаем шахматную доску
        board[0][i] = false;
        a[i] = false;
    }

    return 0;
}