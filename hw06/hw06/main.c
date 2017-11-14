/**
* @author Pavel Korzhenko
* @version 0.2 2017/11/09
* @task 06
* @mark
*/

#include "utils.h"
#include "queue.h"
#include "stack.h"
#include "bitree.h"

/**
 * 1. Реализовать простейшую хэш-функцию. На вход функции подается строка,
 *    на выходе сумма кодов символов.
 *
 */
unsigned int task01(char *str, int len)
{
	unsigned int seed = 72231;
	unsigned int hash = 0;

	for (int i = 0; i < len; str++, i++)
	{
		// simple hash
		//	hash += *str;

		// improve hash
		hash = (hash + seed) + *str + i;
	}
	return hash;
}

/**
 * 2. Переписать программу, реализующее двоичное дерево поиска.
 *	   а) Добавить в него обход дерева различными способами;
 *	   б) Реализовать поиск в двоичном дереве поиска;
 *     в) *Добавить в программу обработку командной строки с помощью которой можно указывать
 *        из какого файла считывать данные, каким образом обходить дерево.
 */
void task02()
{

}

/**
* 3. *Разработать базу данных студентов из двух полей “Имя”, “Возраст”, “Табельный номер”
*    в которой использовать все знания, полученные на уроках.
*    Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю
*    базы данных (возраст, вес)
*/
void task03() 
{

}

int main()
{
	char *str = "Madison will meet you in the cafe opposite the hospital. ";
	printf("\"%s\" calculate hash -> %d\n", str, task01(str, strlen(str)));

	return 0;
}
