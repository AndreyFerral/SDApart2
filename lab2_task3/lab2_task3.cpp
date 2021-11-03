/*
29. Найти гамильтонов цикл в простом графе, имеющий максимальную длину.
*/

#include <iostream>
using namespace std;

class HamiltonCircle {

	static const int sizeGraph = 10; // размер графа
	int startVertex = 2;			 // начальная вершина

	int color[sizeGraph]; // номер хода, на котором посещается вершина
	int path[sizeGraph];  // номера посещаемых вершин

	// Матрица смежности
	int matrixAdjacency[sizeGraph][sizeGraph] =
	{
		0,0,0,0,0,1,0,0,0,0,
		0,0,1,0,0,0,1,0,0,0,
		0,1,0,1,0,0,0,1,0,0,
		0,0,1,0,1,0,0,0,1,0,
		1,0,0,1,0,0,0,0,0,1,
		0,0,0,0,0,0,1,0,0,1,
		0,0,0,1,0,0,0,1,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,0
	};

public:

	// Переопределенный конструктор класса
	HamiltonCircle() {

		// Заполняем массив значением -1
		for (int i = 0; i < sizeGraph; i++)
		{
			color[i] = -1;
		}

		// Задаем изначения значения
		path[0] = startVertex;
		color[startVertex] = startVertex;
	}

	void outputPath()
	{
		// Выводим на экран весь путь
		for (int i = 0; i < sizeGraph; i++)
		{
			cout << path[i] << " ";
		}
		// Выводим на экран завершающую путь координату
		cout << path[0] << "\n";
	}

	// подпрограмма нахождения гамильтонова цикла
	bool gamilton(int step)
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
					path[step] = vertex; // Добавляем в массив посещенную вершину

					// cout << color[vertex] << " номер хода, " << path[step] << " посещенная вершина\n";

					// Проверяем следующую вершину на соответствие
					isGamiltonCircleFind = gamilton(step + 1);

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
	setlocale(LC_ALL, "Russian");

	HamiltonCircle hamilton;
	const int firstStep = 1; // первый шаг для функции поиска цикла

	cout << "Гамильтонов цикл: \n";

	// Если функцию составила путь, то выводим его
	if (hamilton.gamilton(firstStep)) hamilton.outputPath();
	else cout << "Нет решений \n";

}
