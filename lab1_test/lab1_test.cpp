// gamiltg1.cpp -- гамильтонов путь
#include <stdio.h>
#include <conio.h>
#include <iostream>
//#include <alloc.h>
#define n 10

int c[n];   // номер хода, на котором посещается вершина
int path[n]; // номера посещаемых вершин
int v0 = 2;    // начальная вершина

//Матрица смежности
int a[n][n] =
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

void prnt(void)
{
	int p;
	for (p = 0; p < n; p++)
		printf("%d ", path[p]);
	printf("%d ", path[0]);
	printf("\n");
}

//подпрограмма нахождения гамильтонова цикла
int gamilton(int k)
{
	int v, q1 = 0;
	//, n=sizeof(a)/2;

	for (v = 0; v < n && !q1; v++)
	{
		if (a[v][path[k - 1]] || a[path[k - 1]][v])
		{
			if (k == n && v == v0) q1 = 1;
			else if (c[v] == -1)
			{
				c[v] = k; path[k] = v;
				q1 = gamilton(k + 1);
				if (!q1) c[v] = -1;
			}
			else continue;
		}
	}	return q1;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int j;
	//clrscr();
	printf("Гамильтонов цикл:\n");
	for (j = 0; j < n; j++) c[j] = -1;
	path[0] = v0;
	c[v0] = v0;
	if (gamilton(1)) prnt(); else printf("Нет решений\n");
	return 0;
}
