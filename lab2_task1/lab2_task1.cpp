/*
9.	Кликой называется множество вершин графа, любые две из которых смежны. 
	Найти клику, имеющую максимальное количество вершин.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int sizeArray = 10;

	// Матрица смежности
	int matrixAdjacency[sizeArray][sizeArray] =
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

	// Выводим исходный граф
	cout << "Исходный граф: " << "\n";
	for (int i = 0; i < sizeArray; ++i)
	{
		for (int j = 0; j < sizeArray; ++j)
		{
			cout << matrixAdjacency[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	vector<vector<int>> adjacentVertexs;
	vector<int> help;

	// Вектор вектором - первый вектор означает вершину,
	// вложенный - смежные с этой вершиной вершины

	// Заполняем вектор вектором
	for (int i = 0; i < sizeArray; ++i)
	{
		for (int j = 0; j < sizeArray; ++j)
		{
			if (matrixAdjacency[i][j] == 1 || matrixAdjacency[j][i]) 
			{
				help.push_back(j); 
			}
		}
		adjacentVertexs.push_back(help);
		help.clear();
	}

	// Выводим на экран вектор векторов
	cout << "Вершины со смежными вершинами: " << "\n";
	for (int i = 0; i < adjacentVertexs.size(); ++i)
	{
		cout << i << " -> ";
		for (int j = 0; j < adjacentVertexs[i].size(); ++j)
		{
			cout << adjacentVertexs[i][j] << " ";
		}
		cout << "\n";
	}




}
