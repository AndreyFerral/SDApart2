/*
29. Найти гамильтонов цикл в простом графе, имеющий максимальную длину.
*/

#include <iostream>
using namespace std;

// Матрица смежности
int matrixAdjacency[10][10] =
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

void outputPath(int size, int *path)
{
	// Выводим на экран весь путь
	for (int i = 0; i < size; i++)
	{
		cout << path[i] << " ";
	}
	// Выводим на экран завершающую путь координату
	cout << path[0] << "\n";
}

// подпрограмма нахождения гамильтонова цикла
bool gamilton(int step, int size, int startVertex, int *path, int *color)
{
	bool isGamiltonCircleFind = false;

	// Перебираем все возможны вершины
	for (int vertex = 0; vertex < size && !isGamiltonCircleFind; vertex++)
	{
		// Если между двумя вершинами есть путь
		if (matrixAdjacency[vertex][path[step - 1]] == 1 || matrixAdjacency[path[step - 1]][vertex] == 1)
		{
			// Если пройдены все вершины
			if (step == size && vertex == startVertex) {
				isGamiltonCircleFind = true; // гамильтонов цикл найден
			}
			// Если есть не пройденные вершины
			else if (color[vertex] == -1)
			{
				color[vertex] = step; // Добавляем в массив номер хода
				path[step] = vertex; // Добавляем в массив посещенную вершину

				cout << color[vertex] << " номер хода, " << path[step] << " посещенная вершина\n";

				// Проверяем следующую вершину на соответствие
				isGamiltonCircleFind = gamilton(step + 1, size, startVertex, path, color);

				// Если далее невозможно построить гамильтонов цикл, то откатываемся
				if (!isGamiltonCircleFind) {
					color[vertex] = -1;
					cout << "откат\n";
				}
			}
			else continue;
		}
	}	
	return isGamiltonCircleFind;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int firstStep = 1; // первый шаг для функции поиска цикла
	const int size = 10;     // размер графа

	int color[size];     // номер хода, на котором посещается вершина
	int path[size];      // номера посещаемых вершин
	int startVertex = 2; // начальная вершина

	// Заполняем массив значением -1
	for (int i = 0; i < size; i++)
	{ 
		color[i] = -1; 
	}

	// Задаем изначения значения
	path[0] = startVertex;
	color[startVertex] = startVertex;

	cout << "Гамильтонов цикл: \n";
							 
	// Если функцию составила путь, то выводим его
	if (gamilton(firstStep, size, startVertex, path, color)) outputPath(size, path);
	else cout << "Нет решений \n";
	

}
