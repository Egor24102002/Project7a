#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define HEADER ("Лабораторная работа №7\nВыполнил:Пантюшов Е.\n\n")
#include <queue>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <limits.h>
using namespace std;
void bfs(int** G, int* DIST, int v, int n)
{
	queue <int> q;
	q.push(v);
	DIST[v] = 0;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		printf(" %d ", v);
		for (int i = 0; i < n; i++)
		{
			if ((G[v][i] > 0) && (DIST[i] > DIST[v] + G[v][i]))
			{
				q.push(i);
				DIST[i] = DIST[v] + G[v][i];
			}
		}
	}
}
void v_graph(int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			G[i][j] = rand() % 10;
			if (G[i][j] < 5)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = rand() % 5;
			}
		}
	}
}
void nv_graph(int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			G[i][j] = rand() % 2;
		}
	}
}
void no_graph(int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = G[j][i];
			}
			printf(" %d ", G[i][j]);
		}
		printf("\n");
	}
}

void o_graph(int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			printf(" %d ", G[i][j]);
		}
		printf("\n");
	}
}
void task(int** G, int n)
{
	int* DIST = (int*)malloc(n * sizeof(int));
	int v;
	for (int i = 0; i < n; i++)
	{
		DIST[i] = INT_MAX;
	}
	printf("\nВведите точку входа: ");
	scanf("%d", &v);
	printf("Результат работы алгоритма обхода в ширину(матрица):\n ");
	bfs(G, DIST, v, n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (DIST[i] == INT_MAX)
		{
			DIST[i] = 0;
		}
		printf("Кратчайшее расстояние от %dой вершины до %dой вершины=%d\n", v, i, DIST[i]);
	}
	free(DIST);
}
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	printf(HEADER);
	printf("Введите размерность матрицы: ");
	int n;
	scanf("%d", &n);
	int** G = (int**)malloc(n * sizeof(int*));

	if ((strcmp(argv[1], "-v") == 0) && (argc > 1))
	{
		v_graph(G, n);
	}
	else
	{
		nv_graph(G, n);
	}
	if ((strcmp(argv[2], "-o") == 0) && (argc > 1))
	{
		o_graph(G, n);
	}
	else
	{
		no_graph(G, n);
	}
	task(G, n);
	system("PAUSE");
	return 0;
}
