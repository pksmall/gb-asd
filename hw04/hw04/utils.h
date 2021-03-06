﻿#pragma once
/**
*
* utils.h
* @version 0.1
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>

struct timeval​ tv1, tv2, dtv;
struct timzone​ tz;

void printarray(int *arr, int len)
{
	printf("[");
	for (int i = 0; i < len; i++) {
		printf("%2i", arr[i]);
		if (i + 1 < len) {
			printf(", ");
		}
	}
	printf("]\n");
}

//srand(time(NULL));
void fill_array(int *arr, int len)
{
	//srand(time(NULL));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
}

void printmatrix(int n, int m, int** a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}

/*
* swap function
*/
void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;

}

//​time start
void time_start​()
{
	​gettimeofday(&tv1, &tz);
}

// time stop
long time_stop​()
{
	​gettimeofday(&tv2, &tz);
	dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
	dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
	if (dtv.tv_usec < 0) {
		dtv.tv_sec--;
		dtv.tv_usec += 1000000;
	}
	return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}