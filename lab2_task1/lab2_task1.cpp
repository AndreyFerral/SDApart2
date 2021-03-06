/*
9.	Кликой называется множество вершин графа, любые две из которых смежны.
	Найти клику, имеющую максимальное количество вершин.
*/

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Функция для проверки вводимого значения
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

// Функция, которая выводит вектор векторов
void outputVectorOfVectors(vector<vector<int>> vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		cout << i << " -> ";
		for (int j = 0; j < vector[i].size(); ++j)
		{
			cout << vector[i][j] << " ";
		}
		cout << "\n";
	}
}

// Функция, которая выводит первую максимальную клику
void outputMaxClique(vector<vector<int>> vector)
{
	int maxCliqueSize = 0;
	int maxCliqueIndex = 0;

	// Найдем первую максимальную клику
	for (int i = 0; i < vector.size(); ++i)
	{
		if (vector[i].size() > maxCliqueSize)
		{
			maxCliqueSize = vector[i].size();
			maxCliqueIndex = i;
		}
	}

	// Остановим функцию, если клик нет
	if (vector[maxCliqueIndex].size() == 1) {
		cout << "В графе не обнаружено клик " << "\n";
		return;
	}

	// Выведем первую максимальную клику
	cout << "Первая максимальная клика: " << "\n";

	for (int i = 0; i < vector[maxCliqueIndex].size(); ++i)
	{
		cout << vector[maxCliqueIndex][i] << " ";
	}
	cout << "\n";
}

// Функция, проверяющая две вершины - являеются ли они кликами
bool isClique(vector<vector<int>> graph, int vertex1, int vertex2)
{
	for (int i = 0; i < graph[vertex1].size(); ++i)
	{
		if (graph[vertex1][i] == vertex2) return true;
	}
	return false;
}


int main()
{
	srand(time(0)); // генерация случайных чисел
	setlocale(LC_ALL, "Russian");

	cout << "Введите размерность матрицы смежности: ";
	int sizeArray = inputInt();
	cout << endl;

	// Указываем размер для матрицы смежности
	int** matrixAdjacency = new int* [sizeArray];

	// Выделяем память под каждую строку массива 
	for (int i = 0; i < sizeArray; i++) {
		matrixAdjacency[i] = new int[sizeArray];
	}

	// Заполяем матрицу смежности 0 и 1
	for (int i = 0; i < sizeArray; i++) {
		for (int j = 0; j < sizeArray; j++) {
			matrixAdjacency[i][j] = rand() % 2;
		}
	}

	// Выводим на экран исходный граф
	cout << "Исходный граф: " << "\n";
	for (int i = 0; i < sizeArray; ++i)
	{
		for (int j = 0; j < sizeArray; ++j)
		{
			cout << matrixAdjacency[i][j] << " ";
		}
		cout << "\n";
	}

	auto begin = chrono::high_resolution_clock::now(); // начальное время

	vector<vector<int>> adjacentVertexs;
	vector<int> helpVertexs;

	// Заполняем вектор вектором, в котором вершина со смежными вершинами
	for (int i = 0; i < sizeArray; ++i)
	{
		for (int j = 0; j < sizeArray; ++j)
		{
			// Если значение 1, то добавляет в вспомогателей вектор
			// Последнее условие - не учитывать значения на главной диагонали
			if ((matrixAdjacency[i][j] == 1 || matrixAdjacency[j][i] == 1) && i != j)
			{
				helpVertexs.push_back(j);
			}
		}
		adjacentVertexs.push_back(helpVertexs);
		helpVertexs.clear();
	}

	/*
	// Выводим на экран вектор векторов, в котором вершина со смежными вершинами
	cout << "Вершины со смежными вершинами: " << "\n";
	outputVectorOfVectors(adjacentVertexs);
	*/

	vector<vector<int>> clique; // вектор клик
	vector<int> helpClique; // клика

	bool checkClique = true;

	// Заполняем вектор вектором кликами
	for (int i = 0; i < adjacentVertexs.size(); ++i)
	{
		// cout << "\nПроверка соседей вершины " << i << " \n";

		helpClique.push_back(i); // добавим первое значение в клику

		for (int j = 0; j < adjacentVertexs[i].size(); ++j)
		{
			for (int it = 0; it < helpClique.size(); ++it)
			{
				// cout << "Сравнение " << adjacentVertexs[i][j] << " и " << helpClique[it] << " \n";

				// Если эта вершина не является смежной со всеми вершинами в клике, то не будем добавлять её в клику
				if (isClique(adjacentVertexs, adjacentVertexs[i][j], helpClique[it]) == false)
				{
					checkClique = false;
				}

			}

			// Если вершина является смежной со всеми вершинами в клике, то добавим её к клике
			if (checkClique == true)
			{
				// cout << "Добавил " << adjacentVertexs[i][j] << " \n";

				helpClique.push_back(adjacentVertexs[i][j]);
			}
			else { checkClique = true; }

		}

		// Добавим клику в вектор клик
		clique.push_back(helpClique);

		// Очистим вектор клик для следующей итерации
		helpClique.clear();
	}
	cout << "\n";

	/*
	// Выводим на экран вектор векторов, в котором вершина со своей кликой
	cout << "Вершины с кликами: " << "\n";
	for (int i = 0; i < clique.size(); ++i)
	{
		cout << i << " -> ";
		for (int j = 1; j < clique[i].size(); ++j)
		{
			cout << clique[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	// Выводим на экран первую максимальную клику
	outputMaxClique(clique);

	auto end = chrono::high_resolution_clock::now(); // конечное время
	auto time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count(); // искомое время

	cout << "\n";
	cout << "Время работы: " << time << " ns" << endl;
}
