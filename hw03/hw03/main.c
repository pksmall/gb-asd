/**
* @author Pavel Korzhenko
* @version 0.1 2017/11/01
* @task 03
* @mark
*/

// Visual Studio fix scanf
#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"

/**
* 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество
* операций сравнения оптимизированной и не оптимизированной программы. Написать
* функции сортировки, которые возвращают количество операций.
*/
// original bublesort
int task01a(int *arr, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	return count;
}

// optimaze bublesort
int task01b(int *arr, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++) {
		int flag = 0;
		for (int j = len - 1 - i; j > i; j--) {
			count++;
			if (arr[j - 1] > arr[j]) {
				swap(&arr[j - 1], &arr[j]);
				flag++;
			}
		}
		//Если было не больше одной перестановки
		if (flag <= 1) {
			break;
		}
	}
	return count;
}

/**
* 2. *Реализовать шейкерную сортировку.
*/
int task02(int *arr, int len)
{
	int count = 0;
	int left = 1;
	int right = len - 1;

	while (left <= right) {
		for (int i = right; i >= left; i--)
			if (arr[i - 1] > arr[i]) swap(&arr[i], &arr[i - 1]);
		left++;


		for (int i = left; i <= right; i++)
			if (arr[i - 1] > arr[i]) swap(&arr[i], &arr[i - 1]);
		right--;

		count += left - 1;
	}
	return count;
}

/**
* 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
* массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
*/
int task03(int x, int *arr, int len)
{
	int left = 0, right = len - 1;
	int m = right / 2;

	while (left <= right && arr[m] != x) {
		if (arr[m] < x) {
			left = m + 1;
		}
		else {
			right = m - 1;
		}
		m = left + (right - left) / 2;
	}
	if (arr[m] == x) {
		return m;
	}
	else {
		return -1;
	}
}

/**
* 4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
* сложностью алгоритма.
*/
void task04() {
	//original bubble sort O(n^2)
	//optimaze bubble sort O(n^2)/2
	//shaker sort O(log n)
}

int count_routes(int x)
{
	int **A = (int **)malloc(x * sizeof(int*));

	for (int i = 0; i < x; i++) {
		A[i] = (int*)malloc(x * sizeof(int));
		memset(A[i], 0, sizeof(int));
		A[0][i] = 1;
	}

	//printmatrix(x, x, A);
	//printf("%ld - %ld - %ld - %ld\n", sizeof(int*), sizeof(int), sizeof(char*), sizeof(char));
	//return 0;

	for (int i = 1; i < x; i++) {
		A[i][0] = 1;
		for (int j = 1; j < x; j++) {
			A[i][j] = A[i][j - 1] + A[i - 1][j];
		}
	}
	printmatrix(x, x, A);

	return A[x - 1][x - 1];
}

int main() {
	int x = 45;
	const int SIZE = 20;
	int *arr1 = calloc(SIZE, sizeof(int));
	int *arr2 = calloc(SIZE, sizeof(int));
	int *arr3 = calloc(SIZE, sizeof(int));

	fill_array(arr1, SIZE);
	memcpy(arr2, arr1, sizeof(int) * SIZE);
	memcpy(arr3, arr1, sizeof(int) * SIZE);
	printarray(arr1, SIZE);
	printarray(arr2, SIZE);
	printarray(arr3, SIZE);

	printf("Original bubble sort ended with %d iterations.\n", task01a(arr1, SIZE));
	printarray(arr1, SIZE);
	printf("Optimaze bubble sort ended with %d iterations.\n", task01b(arr2, SIZE));
	printarray(arr2, SIZE);

	printf("The shaker sort ended with %d iterations.\n", task02(arr3, SIZE));
	printarray(arr3, SIZE);

	printf("We had found the number %d at position %d.\n", x, task03(x, arr1, SIZE));

	task04();

	printf("Matrix 5x5 = %d\n", count_routes(8));

	return 0;
}
