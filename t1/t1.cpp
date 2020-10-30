#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

int **mass, *visit;

void DFS(int p, int n) {
	int s;
	printf("%d  ", p);
	visit[p] = 1;
	for (s = 0; s < n;s++) {
		if (visit[s] == 0 && mass[p][s] == 1) {
			DFS(s, n);
		}
	}
}

int main() {
	setlocale(0, "rus");
	int p, k = 0, n;

	printf("Введите размер матрицы:");
	scanf_s("%d", &n);
	mass = (int **)malloc(n*sizeof(int));
	for (int i = 0; i<n;i++) {
		mass[i] = (int *)malloc(n*sizeof(int));
	}
	visit = (int *)malloc(n*sizeof(int));
	for (int i = 0; i<n;i++) {
		visit[i] = 0;
	}
	printf("Пути в графе:\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < i + 1;j++) {
			k = rand() % 101;
		if (k >= 20) {
				if (i != j) {
					mass[i][j] = 0;
					mass[j][i] = 0;
				}

				else {
					mass[i][j] = 0;
				}
			}
		else if (k < 20) {

				if (i != j) {
					mass[i][j] = 1;
					mass[j][i] = 1;
				}

				else {
					mass[i][j] = 0;
				}

			}
	}
	
	}
	for (int i = 0;i<n;i++) {
		for (int j = 0;j<n;j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (p = 0; p < n;)
	{
		printf("\n");
		DFS(p, n);
		p++;
	}
	/*for (int i = 0;i<1;i++) {
		printf("Введите вершину с которой начнется обход:");
		scanf_s("%d", &p);
		if (p <= n) {
			printf("\nВы проходите");

		}
		else {
			printf("Выберете новую координату\n");
			i--;
		}
	}*/
}
