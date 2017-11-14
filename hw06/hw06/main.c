/**
* @author Pavel Korzhenko
* @version 0.5 2017/11/14
* @task 06
* @mark
*/

#define _CRT_SECURE_NO_WARNINGS

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
int task02(int argc, char **argv)
{
	biNode *tree1 = create_biNode(1);
	biNode *tmp;
	char *filename = "";
	int sortSwitch = 1;
	int idx=0;

	for (int i = 0; i < argc; i++) {
		// Выводим список аргументов в цикле
		printf("%d %d -> %s\n", argc, i, argv[i]);
	}

	if (argc <= 1 || !strcmp(argv[1], "--help")) {
		printf("%s --help or\n%s --file filename --travers [1..7]\n", argv[0], argv[0]);
		printf("\t filename - file contants number fo bitree (ex. 123456789)\n");
		printf("\t default travers: 1 - pre order\n");
		printf("\t travers: 2 - post order\n");
		printf("\t travers: 3 - in order\n");
		printf("\t travers: 4 - inter pre order\n");
		printf("\t travers: 5 - inter in order\n");
		printf("\t travers: 6 - inter post order\n");
		printf("\t travers: 7 - width travers\n");
		return 0;
	}
	if (argc > 1 && argc == 3) {
		if (!strcmp(argv[1], "--file")) {
			if (argv[2] != NULL) {
				filename = argv[2];
			}
			else {
				printf("'--file' requered file name.\n");
				return -1;
			}
		}
		else {
			printf("Unknown parameter: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
			return -1;
		}
	} else 	if (argc > 2 && argc == 5) {
		if (!strcmp(argv[1], "--file") && !strcmp(argv[3], "--travers")) {
			if (argv[2] != NULL) {
				filename = argv[2];
			}
			else {
				printf("'--file' requered file name.\n");
				return -1;
			}
			if (sscanf(argv[4], "%d", &idx) == 1) {
				if (idx >= 1 && idx <= 7) {
					sortSwitch = idx;
				}
				else {
					printf("'--travers' requered one int parametrs between 1 to 7.\n");
					return -1;
				}
			}
			else {
				printf("'--travers' requered one int parametrs between 1 to 7.\n");
				return -1;
			}
		}
		else {
			printf("Unknown parameter: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
			return -1;
		}
	}
	else {
		printf("Unknown parameter(s). Type %s --help for help.\n", argv[0]);
		return -1;
	}

	printf("file name: %s\tsortSwitch: %d\n\n", filename, sortSwitch);

	tmp = create_biNode(2);
	tree1->left = tmp;
	tmp = create_biNode(3);
	tree1->right = tmp;

	tmp = create_biNode(4);
	tree1->right->left = tmp;

	print_tree(tree1);

	switch (sortSwitch) {
	case 1:
		printf("\nPre Order\n");
		preorder_travers(tree1);
		break;
	case 2:
		printf("\nPost Order\n");
		postorder_travers(tree1);
		break;
	case 3:
		printf("\nIn Order\n");
		inorder_travers(tree1);
		break;
	case 4:
		printf("\nInter Pre Order\n");
		iterpreorder_travers(tree1);
		break;
	case 5:
		printf("\nInter In Order\n");
		iterinorder_travers(tree1);
		break;
	case 6:
		printf("\nInter Post Order\n");
		iterpostorder_travers(tree1);
		break;
	case 7:
		printf("\nWidth Travers\n");
		width_travers(tree1);
		break;
	default:
		printf("\nPre Order\n");
		preorder_travers(tree1);
		break;

	}
	printf("\n\n");

	//biNode *tree2 = Tree(strlen(a));
	//print_tree(tree2);

	return 0;
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

int main(int argc, char **argv)
{
	char *str = "Madison will meet you in the cafe opposite the hospital. ";
	printf("\"%s\" calculate hash -> %d\n", str, task01(str, strlen(str)));

	printf("\n");

	task02(argc, argv);

	return 0;
}
