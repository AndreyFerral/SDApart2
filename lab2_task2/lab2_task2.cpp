/*
19.	В центре шахматной доски стоит конь.
Найти все расположения восьми ладей, не угрожающих друг другу,
при которых конь не угрожает ни одной из ладей.
*/

#include <iostream>
using namespace std;

class ChessBoard {

    int number = 0;                   // номер шахматной доски
    static const int sizeBoard = 8;   // размерность шахматной доски
    bool board[sizeBoard][sizeBoard]; // шахматная доска
    bool colorRook[sizeBoard];        // расположение ладьей

public:

    // Переопределенный конструктор класса
    ChessBoard() {

        // Заполняем массивы нулевыми значения
        for (int i = 0; i < sizeBoard; i++)
        {
            colorRook[i] = 0;

            for (int j = 0; j < sizeBoard; j++)
            {
                board[i][j] = 0;
            }
        }
    }

    // Метод, который располагает главные ладьи, от которых будет запущена рекурсия
    void setRooks() {

        // i - главная горизонталь, на остальных будут перестановки
        for (int i = 0; i < sizeBoard; i++)
        {
            // Устанавливаем ладья на позицию
            colorRook[i] = true;
            board[0][i] = true;

            // Расстанавливаем ладьи на следующей горизонтале
            nextRow(1);

            // Очищаем шахматную доску
            board[0][i] = false;
            colorRook[i] = false;
        }
    }

    // Метод, который вызывает рекурсию для каждой следующей ладьи
    void nextRow(int i)
    {
        // Если шахматная доска заполнена, то выводим её
        if (i == sizeBoard)
        {
            outputBoard();
            return;
        }

        // Устанавливаем следующую ладью на всевозможные позиции (максимум 7, т.к. первая задана в точке входа)
        for (int j = 0; j < sizeBoard; j++)
        {
            // Проверяем, является ли это поле уже занятым (с учетом того, что это ладья) 
            if (!colorRook[j])
            {
                // Устанавливаем ладья на позицию
                colorRook[j] = true;
                board[i][j] = true;

                // Расстанавливаем ладьи на следующей горизонтале
                nextRow(i + 1);

                // Очищаем шахматную доску
                board[i][j] = false;
                colorRook[j] = false;
            }
        }
    }

    // Метод, который выводит шахматную доску
    void outputBoard()
    {
        // Учитываем, что по середине стоит конь (3;4), остальные - его возможные ходы
        if (board[1][3] || board[1][5] ||
            board[2][2] || board[2][6] ||
            board[3][4] ||
            board[4][2] || board[4][6] ||
            board[5][3] || board[5][5])
        {
            // cout << "Поле является ошибочным!" << "\n";
            return;
        }

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
};

int main()
{
    setlocale(LC_ALL, "Russian");

    ChessBoard board;
    board.setRooks();

    return 0;
}