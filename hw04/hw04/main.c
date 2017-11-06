/**
* @author Pavel Korzhenko
* @version 0.3 2017/11/06
* @task 04
* @mark
*/

#include "utils.h"

/*
* 1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и
* нахождение количество маршрутов.
*	Например, карта:
*		3 3
*		1 1 1
*		0 1 0
*		0 1 0
*/
void task01(int x, int y, int **A, int** M)
{
	for (int j = 0; j < y; j++) {
		if (M[0][j] == 0) A[0][j] = 0;
		else A[0][j] = 1;
	}

	for (int i = 1; i < x; i++) {
		A[i][0] = 1;
		for (int j = 1; j < y; j++) {
			if (M[i][j] == 0) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			}
		}
	}
	printmatrix(x, y, A);
}

/*
*2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
*/
int task02(char *A, char *B)
{
	int *X, *Y;

	int m = strlen(A);
	int n = strlen(B);

	X = (int*)malloc(m * sizeof(int));
	Y = (int*)malloc(n * sizeof(int));

	for (int i = m; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			if (A[i] == '\0' || B[j] == '\0') X[j] = 0;
			else if (A[i + 1] == B[j + 1]) X[j] = 1 + Y[j + 1];
			else X[j] = max(Y[j], X[j + 1]);
		}
		Y = X;
	}
	return X[0];
}

/**
* 3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по
* одному разу. Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке
* положения коня.
*
* возвращает 1, если доска заполнена, 0 - если нет продолжений
*/
// valid moves
int moves[8][2] = {
	{ -2,  1 },{ -1,  2 },{ 1,  2 },{ 2,  1 },
	{ 2, -1 },{ 1, -2 },{ -1, -2 },{ -2, -1 }
};

int valid(int x, int y, int **board, int a, int b)
{
	return
		x >= 0 && x < a &&
		y >= 0 && y < b &&
		board[y][x] == 0;
}

// compare 
int compar(const void *a, const void *b)
{
	return ((int *)a)[0] - ((int *)b)[0];
}

// solve board 8x8
int task03(int x, int y, int n, int **board, int a, int b)
{
	board[y][x] = n;
	if (n == a * b)
		return 1;

	int i, j, valids[8][3];
	for (i = 0; i < 8; i++) {
		valids[i][0] = 0;
		valids[i][1] = x + moves[i][0];
		valids[i][2] = y + moves[i][1];
		if (valid(valids[i][1], valids[i][2], board, a, b)) {
			for (j = 0; j < 8; j++) {
				if (valid(valids[i][1] + moves[j][0],
					valids[i][2] + moves[j][1], board, a, b))
					valids[i][0]++;
			}
		}
	}

	qsort(&valids[0][0], 8, 3 * sizeof(int), &compar);
	for (i = 0; i < 8; i++) {
		if (valid(valids[i][1], valids[i][2], board, a, b) &&
			task03(valids[i][1], valids[i][2], n + 1, board, a, b))
			return 1;
	}

	board[y][x] = 0;
	return 0;
}

int main()
{
	// task01
	int x, y;
	x = 4;  y = 5;

	// array with path
	int** A = (int **)malloc(x * sizeof(int*));
	for (int i = 0; i < y; i++) {
		A[i] = (int *)malloc(y * sizeof(int));
		memset(A[i], 0, sizeof(int));
		for (int j = 0; j < x; j++) {
			A[i][j] = 0;
		}
	}
	// map arrray with obstacles
	int** M = (int **)malloc(x * sizeof(int*));
	for (int i = 0; i < y; i++) {
		M[i] = (int *)malloc(y * sizeof(int));
		memset(M[i], 0, sizeof(int));
		for (int j = 0; j < x; j++) {
			M[i][j] = 1;
		}
	}

	//task01(x, y, A, M);
	//printf("\n");
	// init obstacles
	M[0][3] = 0;
	M[2][2] = 0;
	M[3][1] = 0;
	task01(x, y, A, M);
	printf("\n");

	// task02 
	char *string = "ABCEDFG";
	char *subque = "ABE";
	printf("Max common subsequence (%s -> %s) = %d\n\n", string, subque, task02(string, subque));
	printf("\n");
	
	// task03
	x = 8;	// x
	y = 8;	// y

			// init [][] array
	int** board = (int **)malloc(x * sizeof(int*));
	for (int i = 0; i < y; i++) {
		board[i] = (int *)malloc(y * sizeof(int));
		memset(board[i], 0, sizeof(int));
		for (int j = 0; j < x; j++) {
			board[i][j] = 0;
		}
	}

	if (task03(5, 0, 1, board, x, y)) {
		printmatrix(x, y, board);
	}
	else {
		printf("No solution.\n");
	}
	return 0;
}
