/*
19.	В центре шахматной доски стоит конь. 
Найти все расположения восьми ладей, не угрожающих друг другу, 
при которых конь не угрожает ни одной из ладей.
*/

#include <iostream>
using namespace std;

void setRook(int& myarr, int sizeMatrix, int i)
{
	for (int j = 0; j < sizeMatrix; ++j)
	{
		if (myarr[i][j] != 1) {
			myarr[i][j] = 1;
			setRook(myarr, sizeMatrix, i);
			cout << i << " " << j << " ";
		}
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int sizeMatrix = 8;

	int chessBoard[sizeMatrix][sizeMatrix] =
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

	// Выводим на экран исходный граф
	cout << "Шахматная доска с конём: " << "\n";

	for (int i = 0; i < 2; ++i)
	{
		cout << "    ";
		for (int j = 0; j < sizeMatrix; ++j)
		{
			if (i == 0) cout << j + 1 << " ";
			if (i == 1) cout << "--";
		}
		cout << "\n";
	}

	for (int i = 0; i < sizeMatrix; ++i)
	{
		cout << i + 1 << " | ";
		for (int j = 0; j < sizeMatrix; ++j)
		{
			cout << chessBoard[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < sizeMatrix; ++i)
	{
		setRook(chessBoard, sizeMatrix, i);
	}
}
