#pragma once
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
#include <stdint.h>
#include <sys/timeb.h>
#include <time.h>
#include <stdbool.h>

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

void fill_array(int *arr, int len)
{
	//srand(time(NULL));
	for (int i = 0; i < len; i++) {
		//arr[i] = rand() % RAND_MAX;
		///arr[i] = rand() % 100;
		arr[i] = rand() % len;
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

typedef unsigned long long ull;

/*
__declspec(naked) unsigned __int64 rdtsc(void)
{
	__asm rdtsc;
	__asm retn;
}
*/
