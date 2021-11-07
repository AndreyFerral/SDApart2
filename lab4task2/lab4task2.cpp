/*
19.	Нарисовать сортировочную сеть для алгоритма Бетчера сортировки восьми чисел.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string> 
using namespace std;

class BetcherNetwork {

	vector<vector<int>> all;		// Хранение массивов для вывода сортировочной сети
	static const int sizeArray = 8; // Размерность массива
	int array[sizeArray];			// Массив чисел

public:

	// Перегруженный конструктор класса
	BetcherNetwork() {
		// Заполняем массив случайными числами
		for (int i = 0; i < sizeArray; i++) {
			array[i] = rand() % 41 - 20;
		}
	}

	// Метод для получения размера массива
	int getSize() { return sizeArray; }

	// Метод для обмена элементов с учетом порядка возрастания или убывания
	void sortDir(int i, int j, int dir) {

		// cout << " Сравниваем " << array[i] << " и " << array[j] << " \n";

		// Закидываем массивы в вектор
		vector<int> oneArray;
		for (int cnt = 0; cnt < sizeArray; cnt++) {
			oneArray.push_back(array[cnt]);
		}
		all.push_back(oneArray);

		// В зависимости от передаваего параметра изменяется директория сортировки
		if (dir == (array[i] > array[j])) {

			// cout << "  Меняем местами " << array[i] << " и " << array[j] << " \n";

			swap(array[i], array[j]);

			// output();
		}
	}

	/* Pекурсивно сортирует последовательность в порядке возрастания (dir == 1), или убывания (dir == 0).
	   Сортируемая последовательность начинается с младшей позиции индекса - параметр low,
	   параметр cnt - это количество элементов для сортировки. */
	void merge(int low, int cnt, int dir) {
		if (cnt > 1) {

			// cout << "Вызван merge от " << low << " до " << low + cnt - 1 << endl;

			int half = cnt / 2;

			// Вызываем метод обмена элементов
			for (int i = low; i < low + half; i++) {
				sortDir(i, i + half, dir);
			}

			// Рекурсивно сортируем последовательность
			merge(low, half, dir);
			merge(low + half, half, dir);
		}
	}

	/* Создаём последовательность рекурсивно.
	   Сортируем две половинки, затем вызываем merge */
	void sort(int low, int cnt, int dir) {


		if (cnt > 1) {

			// cout << "Вызван sort от " << low << " до " << low + cnt - 1 << endl;

			int k = cnt / 2;

			// Рекурсивно строим сеть сортировки
			sort(low, k, 1);
			sort(low + k, k, 0);
			merge(low, cnt, dir);
		}
	}

	// Метод для вывода массива на экран
	void output() {

		for (int i = 0; i < sizeArray; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	// Метод для вывода вертикальной линии
	string outputVLine() {
		return "--- | -";
	}

	// Метод для вывода числа
	string oN(int numb) {

		string number;

		number = to_string(numb);
		if (number.size() == 1) number = " " + number + " ";
		else if (number.size() == 2) number = " " + number;
		string outputNumber = "-- " + number + " ";

		return outputNumber;
	}

	// Метод для вывода горизонтальной линии 
	string outputLine(int number) {

		string line = "-";
		string outputLine;

		for (int i = 0; i < number; i++) {
			outputLine += line;
		}

		return outputLine;
	}

	// Метод для вывода сортировочной сети на экран
	void outputNetwork() {

		cout << endl << endl;

		cout << "\t      " << outputLine(79) << "\n";
		cout << "\t 0.   " << oN(all[0][0]) << oN(all[2][0]) << outputLine(7) << oN(all[4][0]) << oN(all[12][0]) << outputLine(21) << oN(all[16][0]) << outputLine(7) << oN(all[18][0]) << outputLine(2) << "\n";
		cout << "\t      " << outputVLine() << outputVLine() << outputLine(7) << outputVLine() << outputVLine() << outputLine(21) << outputVLine() << outputLine(7) << outputVLine() << outputLine(2) << "\n";
		cout << "\t 1.   " << oN(all[0][1]) << outputVLine() << oN(all[3][1]) << oN(all[4][1]) << outputVLine() << oN(all[13][1]) << outputLine(14) << outputVLine() << oN(all[17][1]) << oN(all[18][1]) << outputLine(2) << "\n";
		cout << "\t      " << outputLine(7) << outputVLine() << outputVLine() << outputLine(7) << outputVLine() << outputVLine() << outputLine(14) << outputVLine() << outputVLine() << outputLine(9) << "\n";
		cout << "\t 2.   " << oN(all[1][2]) << oN(all[2][2]) << outputVLine() << oN(all[5][2]) << outputVLine() << outputVLine() << oN(all[14][2]) << outputLine(7) << oN(all[16][2]) << outputVLine() << oN(all[19][2]) << outputLine(2) << "\n";
		cout << "\t      " << outputVLine() << outputLine(7) << outputVLine() << outputVLine() << outputVLine() << outputVLine() << outputVLine() << outputLine(14) << outputVLine() << outputVLine() << outputLine(2) << "\n";
		cout << "\t 3.   " << oN(all[1][3]) << outputLine(7) << oN(all[3][3]) << oN(all[5][3]) << outputVLine() << outputVLine() << outputVLine() << oN(all[15][3]) << outputLine(7) << oN(all[17][3]) << oN(all[19][3]) << outputLine(2) << "\n";
		cout << "\t      " << outputLine(28) << outputVLine() << outputVLine() << outputVLine() << outputVLine() << outputLine(23) << "\n";
		cout << "\t 4.   " << oN(all[6][4]) << oN(all[8][4]) << outputLine(7) << oN(all[10][4]) << oN(all[12][4]) << outputVLine() << outputVLine() << outputVLine() << oN(all[20][4]) << outputLine(7) << oN(all[22][4]) << outputLine(2) << "\n";
		cout << "\t      " << outputVLine() << outputVLine() << outputLine(7) << outputVLine() << outputLine(7) << outputVLine() << outputVLine() << outputVLine() << outputVLine() << outputLine(7) << outputVLine() << outputLine(2) << "\n";
		cout << "\t 5.   " << oN(all[6][5]) << outputVLine() << oN(all[9][5]) << oN(all[10][5]) << outputLine(7) << oN(all[13][5]) << outputVLine() << outputVLine() << outputVLine() << oN(all[21][5]) << oN(all[22][5]) << outputLine(2) << "\n";
		cout << "\t      " << outputLine(7) << outputVLine() << outputVLine() << outputLine(21) << outputVLine() << outputVLine() << outputVLine() << outputVLine() << outputLine(9) << "\n";
		cout << "\t 6.   " << oN(all[7][6]) << oN(all[8][6]) << outputVLine() << oN(all[11][6]) << outputLine(14) << oN(all[14][6]) << outputVLine() << oN(all[20][6]) << outputVLine() << oN(all[23][6]) << outputLine(2) << "\n";
		cout << "\t      " << outputVLine() << outputLine(7) << outputVLine() << outputVLine() << outputLine(21) << outputVLine() << outputLine(7) << outputVLine() << outputVLine() << outputLine(2) << "\n";
		cout << "\t 7.   " << oN(all[7][7]) << outputLine(7) << oN(all[9][7]) << oN(all[11][7]) << outputLine(21) << oN(all[15][7]) << outputLine(7) << oN(all[21][7]) << oN(all[23][7]) << outputLine(2) << "\n";
		cout << "\t      " << outputLine(79) << "\n";
	}
};

int main() {
	srand(time(0)); // генерация случайных чисел
	setlocale(LC_ALL, "Russian");

	BetcherNetwork sortingNetwork;

	cout << setw(25) << "Изначальный массив: ";
	sortingNetwork.output();

	const int firstPosition = 0;

	const int ascendingand = 1; // Сортировка по возрастанию
	const int descending = 0;   // Сортировка по убыванию

	// Отсортировать массив по возрастанию (последний параметр)
	sortingNetwork.sort(firstPosition, sortingNetwork.getSize(), ascendingand);

	cout << setw(25) << "Отсортированный массив: ";
	sortingNetwork.output();

	cout << endl;
	cout << "\t Сортировочная сеть:";
	sortingNetwork.outputNetwork();

	return 0;
}