/**
 * @author Pavel Korzhenko
 * @version 0.1 2017/11/19
 * @task 08
 * @mark
 *
 *
 * 5. Проанализировать время работы каждого из вида сортировок 
 *    для 100, 10000, 1000000 элементов. Заполнить таблицу (см. методичку)
 *    Записывайте в начало программы условие и свою фамилию. Все решения 
 *	  создавайте в одной программе.
 *
 *@see profiling.txt
 */

#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"
#define SIZE	1000000

/*
 * 1. Реализовать сортировку подсчетом.
 *
 *  простой алгоритм
 int k;
 for (int i = 0; i < n; i++)
 {
	k = 0;
	for (int j = 0; j < n; j++) {
		if (arr[i] > arr[j])
			k++;
 }
 retArr[k] = arr[i];
 }
 */
int* task01(int* arr, int n)
{
	int* retArr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		//memset(retArr[i], 0, sizeof(int));
		retArr[i] = 0;
	}
	/* квадратичный алгоритм */
	int c;

	for (int i = 0; i < n; i++) {
		c = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] <= arr[i]) {
				c++;
			}
		}
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				c++;
			}
		}
		retArr[c] = arr[i];
	}
	return retArr;
}

/*
 * 2. Реализовать быструю сортировку.
 */
void task02(int* arr, int n)
{
	int i = 0;
	int j = n - 1;

	int mid = arr[n / 2];

	do {
		while (arr[i] < mid) { i++; }
		while (arr[j] > mid) { j--; }
		if (i <= j) {
			if (arr[i] > arr[j]) { swap(&arr[i], &arr[j]); }
			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0) {
		task02(arr, j + 1);
	}
	if (i < n) {
		task02(&arr[i], n -  i);
	}
}

/*
 * 3. *Реализовать сортировку слиянием.
 */
void task03(int* arr, int l, int n)
{
	if (l == n) return; 
	int mid = (l + n) / 2;

	task03(arr, l, mid);
	task03(arr, mid + 1, n);

	int i = l;  
	int j = mid + 1; 
	int *tmp = (int*)malloc(n * sizeof(int));

	for (int step = 0; step < n - l + 1; step++) {
		if ((j > n) || ((i <= mid) && (arr[i] < arr[j]))) {
			tmp[step] = arr[i];
			i++;
		}
		else {
			tmp[step] = arr[j];
			j++;
		}
	}
	for (int step = 0; step < n - l + 1; step++) {
		arr[l + step] = tmp[step];
	}
}

/*
 * 4. **Реализовать алгоритм сортировки со списком
 */
void task04(int* arr, int n)
{
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < n; i++) 	{
		if (arr[i] < min)	{
			min = arr[i];
		}
		if (arr[i] > max)	{
			max = arr[i];
		}
	}

	int *current = arr;
	int size = max - min + 1, count = 0, i;
	int* holes = malloc(size * sizeof(int));

	for (i = 0; i < size; i++) {
		holes[i] = 0;
	}

	for (i = 0; i < size; i++, current++) {
		holes[*current - min] += 1;
	}

	for (count = 0, current = &arr[0]; count < size; count++)	{
		while (holes[count]--> 0) {
			*current++ = count + min;
		}
	}
}

int main()
{
	int* arr = malloc(SIZE * sizeof(int));
	int* arr1 = malloc(SIZE * sizeof(int));
	int* arr2 = malloc(SIZE * sizeof(int));
	int* sortArr;

	fill_array(arr, SIZE);
	memcpy(arr1, arr, sizeof(int) * SIZE);
	memcpy(arr2, arr, sizeof(int) * SIZE);

	//printarray(arr, SIZE);
	double start = clock();
	sortArr = task01(arr, SIZE);
	time_t t02 = time(0);
	printf("Count Sort = %.8lf\n", (clock() - start) / CLOCKS_PER_SEC);
	//printarray(sortArr, SIZE);

	printf("\n");

	//printarray(arr, SIZE);
	start = clock();
	task02(arr, SIZE);
	printf("QSort = %.8lf\n", (clock() - start) / CLOCKS_PER_SEC);
	//printarray(arr, SIZE);

	printf("\n");

	//printarray(arr1, SIZE);
	start = clock();
	task03(arr1, 0, SIZE - 1);
	//printarray(arr1, SIZE);
	printf("MergeSort = %.8lf\n", (clock() - start) / CLOCKS_PER_SEC);

	printf("\n");

	//printarray(arr2, SIZE);
	start = clock();
	task04(arr2, SIZE);
	//printarray(arr2, SIZE);
	printf("ListSort = %.8lf\n", (clock() - start) / CLOCKS_PER_SEC);

	printf("\n");

	return 0;
}