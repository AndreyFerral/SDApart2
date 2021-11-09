/*
29. Найти гамильтонов цикл в простом графе, имеющий максимальную длину.
*/

#include <iostream>
#include <chrono>
using namespace std;

class HamiltonCircle {

	static const int startVertex = 0; // начальная вершина

	int** matrixAdjacency; // матрица смежности
	int* color;			   // номер хода, на котором посещается вершина
	int* path;		       // номера посещаемых вершин

public:

	// Метод для проверки вводимого значения
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

	// Метод для вывода матрицы смежности
	void outputGraph(int sizeGraph)
	{
		for (int i = 0; i < sizeGraph; ++i)
		{
			for (int j = 0; j < sizeGraph; ++j)
			{
				cout << matrixAdjacency[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	// Метод для вывода пути
	void outputPath(int sizeGraph)
	{
		// Выводим на экран весь путь
		for (int i = 0; i < sizeGraph; i++)
		{
			cout << path[i] << " ";
		}
		// Выводим на экран завершающую путь координату
		cout << path[0] << "\n";
	}

	void start() {
	
		cout << "Введите размерность матрицы смежности: ";
		int sizeGraph = inputInt();
		cout << endl;

		// Указываем размер для матрицы смежности
		matrixAdjacency = new int*[sizeGraph];

		// Выделяем память под каждую строку массива 
		for (int i = 0; i < sizeGraph; i++) {
			matrixAdjacency[i] = new int[sizeGraph];
		}

		// Заполяем матрицу смежности 0 и 1
		for (int i = 0; i < sizeGraph; i++) {
			for (int j = 0; j < sizeGraph; j++) {
				matrixAdjacency[i][j] = rand() % 2;
			}
		} 

		// Выводим исходный граф на экран
		cout << "Исходный граф: \n";
		outputGraph(sizeGraph);

		// Указываем размеры для динамических массивов
		path = new int[sizeGraph];
		color = new int[sizeGraph];

		// Заполняем массив color значением -1
		for (int i = 0; i < sizeGraph; i++)
		{
			color[i] = -1;
		}

		// Задаем изначения значения
		path[0] = startVertex;
		color[startVertex] = startVertex;

		// Первый шаг для функции поиска цикла
		const int firstStep = 1;

		cout << "Гамильтонов цикл: \n";

		// Если функцию составила путь, то выводим его
		if (gamilton(firstStep, sizeGraph)) outputPath(sizeGraph);
		else cout << "Нет решений \n";

		cout << endl;
	}

	// Метод для нахождения гамильтонова цикла
	bool gamilton(int step, int sizeGraph)
	{
		bool isGamiltonCircleFind = false;

		// Перебираем все возможны вершины
		for (int vertex = 0; vertex < sizeGraph && !isGamiltonCircleFind; vertex++)
		{
			// Если между двумя вершинами есть путь
			if (matrixAdjacency[vertex][path[step - 1]] == 1 || matrixAdjacency[path[step - 1]][vertex] == 1)
			{
				// Если пройдены все вершины
				if (step == sizeGraph && vertex == startVertex) {
					isGamiltonCircleFind = true; // гамильтонов цикл найден
				}

				// Если есть не пройденные вершины
				else if (color[vertex] == -1)
				{
					color[vertex] = step; // Добавляем в массив номер хода
					path[step] = vertex;  // Добавляем в массив посещенную вершину

					// cout << color[vertex] << " номер хода, " << path[step] << " посещенная вершина\n";

					// Проверяем следующую вершину на соответствие
					isGamiltonCircleFind = gamilton(step + 1, sizeGraph);

					// Если далее невозможно построить гамильтонов цикл, то откатываемся
					if (!isGamiltonCircleFind) {
						color[vertex] = -1;
						// cout << "откат\n";
					}
				}
				else continue;
			}
		}
		return isGamiltonCircleFind;
	}
};

int main()
{
	srand(time(0)); // генерация случайных чисел
	setlocale(LC_ALL, "Russian");

	HamiltonCircle hamilton;

	auto begin = chrono::high_resolution_clock::now(); // начальное время

	hamilton.start();

	auto end = chrono::high_resolution_clock::now(); // конечное время
	auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

	cout << "Время работы: " << time << " ns" << endl;
}
