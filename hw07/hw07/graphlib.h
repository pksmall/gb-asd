#pragma once
// graphs lib
//
// @version 0.1 2017/11/16
// 

#include <stdbool.h>

/**
 *
 * read adjacency matrix from file
 *
 * @return  readed matrix
 *
 * @param fileName - file with matrix example:
 *						4
 *						0 1 0 1
 *						0 0 1 1
 *						0 1 0 1
 *						1 0 1 1
 * @param t - var where you store the matrix size
 * 
 * @use  int** matrix =  graphReadAdjacencyMatrix(char *fileName, int *t);
 *
 */
int** graphReadAdjacencyMatrix(char *fileName, int *t)
{
	int x, value;
	int** arr;
	FILE *file = fopen(fileName, "r");

	if (file == NULL) {
		printf("Can't open file.\n");
		exit(-1);
	}
	// size of matrix 
	fscanf(file, "%d", &x);
	// init matrix
	arr = (int **)malloc(x * sizeof(int*));
	for (int i = 0; i < x; i++) {
		arr[i] = (int *)malloc(x * sizeof(int));
		memset(arr[i], 0, sizeof(int));
		for (int j = 0; j < x; j++) {
			arr[i][j] = 0;
			fscanf(file, "%d", &value);
			arr[i][j] = value;
		}
	}
	fclose(file);

	// return size
	*t = x;

	return arr;
}

/**
 *
 * print matrix size of NxM
 * 
 */
int printMatrix(int n, int m, int** a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf(" %d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/**
 * deepStepGraph
 *
 * @param x - size of matrix
 *
 * @param start - start point of step
 *
 * @param arr - matrix
 *
 * @use deepStepGraph(x, start, adjMatrix);
 */
void _deepStepGraph(int x, int start, int** arr, bool *visited)
{
	printf("%d ", start + 1);

	visited[start] = true;

	for (int r = 0; r <= x; r++) {
		if ((arr[start][r] != 0) && (!visited[r])) {
			_deepStepGraph(x, r, arr, visited);
		}
	}
}

void deepStepGraph(int x, int start, int** arr)
{
	bool *visited = malloc(x * sizeof(bool));

	for (int i = 0; i < x; i++) {
		visited[i] = false;
	}
	_deepStepGraph(x, start - 1, arr, visited);

	printf("\n");
}

/**
 * widthStepGraph
 */
void _widthStepGraph(int x, int start, int** arr, bool *visited) 
{
	int *queue = malloc(x * sizeof(int));
	int count = 0;
	int head = 0;

	for (int i = 0; i < x; i++) {
		queue[i] = 0;
	}
	queue[count++] = start;

	visited[start] = true;
	while (head < count) {
		start = queue[head++];
		printf("%d ", start + 1);
		for (int i = 0; i < x; i++) {
			if (arr[start][i] && !visited[i]) {
				queue[count++] = i;
				visited[i] = true;
			}
		}
	}
}

void widthStepGraph(int x, int start, int** arr)
{
	bool *visited = malloc(x * sizeof(bool));

	for (int i = 0; i < x; i++) {
		visited[i] = false;
	}
	_widthStepGraph(x, start - 1, arr, visited);

	printf("\n");

}
