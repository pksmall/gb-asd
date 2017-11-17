/**
* @author Pavel Korzhenko
* @version 0.2 2017/11/16
* @task 07
* @mark
*/

/** 
 * 4. *Создать библиотеку функций для работы с графами 
 *
 * @see graphlib.h
 */

#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"
#include "graphlib.h"

/*
 * 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран
 */
void task01()
{
	int **adjMatrix; // without init. It will do in the function
	int x; // size of matrix
	char *fileName = "adjmatrix.txt";

	adjMatrix = graphReadAdjacencyMatrix(fileName, &x);
	printMatrix(x, x, adjMatrix);
}

/*
 * 2. Написать рекурсивную функцию обхода графа в глубину.
 */
void task02()
{
	int **adjMatrix; // without init. It will do in the function
	int x; // size of matrix
	char *fileName = "adjmatrix-deep.txt";
	int start = 2;

	adjMatrix = graphReadAdjacencyMatrix(fileName, &x);
	printMatrix(x, x, adjMatrix);
	printf("\n");
	deepStepGraph(x, start, adjMatrix);
}

/*
 * 3. Написать функцию обхода графа в ширину.
 */
void task03()
{
	int **adjMatrix; // without init. It will do in the function
	int x; // size of matrix
	char *fileName = "adjmatrix-width.txt";
	int start = 2;

	adjMatrix = graphReadAdjacencyMatrix(fileName, &x);
	printMatrix(x, x, adjMatrix);
	printf("\n");
	widthStepGraph(x, start, adjMatrix);
}

int main()
{
	//task01();

	printf("\n");

	task02();

	printf("\n");

	//task03();

	return 0;
}