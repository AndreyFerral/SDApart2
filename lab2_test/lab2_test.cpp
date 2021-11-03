

#include <iostream>
using namespace std;

int number = 0;
const int sizeBoard = 8;
bool board[sizeBoard][sizeBoard], a[sizeBoard];

void output()
{
    cout << endl;

    //if (board[1][3] || board[1][5] || board[2][2] || board[2][6] || board[3][4] || board[4][2] || board[4][6] || board[5][3] || board[5][5]) return;

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
/*
// Матрица смежности
bool board[sizeBoard][sizeBoard] =
{
    0,0,0,0,0,0,0,0,
    0,0,0,1,0,1,0,0,
    0,0,1,0,0,0,1,0,
    0,0,0,0,1,0,0,0,
    0,0,1,0,0,0,1,0,
    0,0,0,1,0,1,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};
*/

int main()
{
    setlocale(LC_ALL, "Russian");

    board[1][3] = 1;
    board[1][5] = 1; 
    board[2][2] = 1; 
    board[2][6] = 1; 
    board[3][4] = 1; 
    board[4][2] = 1; 
    board[4][6] = 1; 
    board[5][3] = 1; 
    board[5][5] = 1;

    /*
    for (int i = 0; i < sizeBoard; i++) {

        for (int j = 0; j < sizeBoard; j++) {

            board[i][j] = 1;
        }
        cout << endl;
    }
    */

    output();

    return 0;
}