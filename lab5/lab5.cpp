#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <random>
//#include <time.h>
#include <conio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n = 10, **G=NULL, size = 0, size2 = 0, *deg = NULL;

	printf("Введите количество вершин: \n");
	scanf("%d", &n);
	
	G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {

		G[i] = (int*)malloc(n * sizeof(int));
	
	}

	deg = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){

		deg[i] = 0;

	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];

			if (i == j) G[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			printf("%d", G[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			//size2 = size2 + G[i][j];

			if (G[i][j] != 0) size++;

		}
	}
	size = size/2;
	printf("Размер графа = %d \n", size);

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (G[i][j] != 0) deg[i]++;

		}
	}

	for (int i = 0; i < n; i++) {

		printf("Степень вершины %d = %d \n", i, deg[i]);

	}

	for (int i = 0; i < n; i++) {

		if(deg[i] == 0) printf("Вершина %d, - изолированная \n", i);
		if (deg[i] == 1) printf("Вершина %d, - концевая \n", i);
		if (deg[i] == n-1) printf("Вершина %d, - доминирующая \n", i);
	}

	return 0;

}