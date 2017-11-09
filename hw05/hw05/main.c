/**
* @author Pavel Korzhenko
* @version 0.2 2017/11/09
* @task 04
* @mark
*/

#include "utils.h"
#include "stack.h"
#include "queue.h"
#include "rpe.h"

/*
 * 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 */
void task01(int x)
{
	TCH y;
	TStack stack;

	stack.maxsize = 100;
	stack.head = NULL;

	for (int i = x; i > 0; ) {
		if (i) {
			y = i % 2 ? '1' : '0';
			stkPush(y, &stack);
		}
		i /= 2;
	}
	stkPush('b', &stack);
	printStack(&stack);
	printf("\n");
}

/**
 * 2. Добавить в программу “реализация стека на основе односвязного списка” проверку
 *	  на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение.
 *    Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого
 *    количества данных).
 *
 * @see stack.h
 */
void task02()
{
	TStack stack;

	stack.maxsize = 100;
	stack.head = NULL;

	stkPush('a', &stack);
	stkPush('b', &stack);
	stkPush('c', &stack);
	stkPush('d', &stack);
	stkPush('e', &stack);
	stkPush('f', &stack);
	stkPush('g', &stack);
	printStack(&stack);
	printf("\n");
	printf("%c, ", stkPop(&stack));
	printf("%c, ", stkPop(&stack));
	printf("%c\n", stkPop(&stack));
	printStack(&stack);
	printf("\n");
}

/**
 * 3. Написать программу, которая определяет, является ли введенная скобочная последовательность
 *    правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
 *    неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
 *    Например: (2+(2*2)) или [2/{5*(4+7)}]
 */
char *task03(const char * s) {
	switch (*s) {
		case '\0':
		case ')':
		case '}':
		case ']':
			return (char*)s;
		case '(': {
			char *ret = task03(s + 1);
			return (*ret == ')') ? task03(ret + 1) : (char*)s;
		}
		case '{': {
			char *ret = task03(s + 1);
			return (*ret == '}') ? task03(ret + 1) : (char*)s;
		}
		case '[': {
			char *ret = task03(s + 1);
			return (*ret == ']') ? task03(ret + 1) : (char*)s;
		}
		default:
			return task03(s + 1);
	}
}

/*
 * 4. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного
 *    списка, без удаления первого списка).
 */
void task04()
{
	TStack st01;

	st01.maxsize = 100;
	st01.head = NULL;

	stkPush('a', &st01);
	stkPush('b', &st01);
	stkPush('c', &st01);
	stkPush('d', &st01);
	stkPush('e', &st01);
	stkPush('f', &st01);
	stkPush('g', &st01);
	printStack(&st01);

	TStack st02;

	printf("\nElements copied %d\n", copyStack(&st01, &st02));
	printStack(&st02);
	printf("\n");
}

/**
* 5. **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
*
* @see rpe.h
*/
void task05()
{
	//"2 + (3 + 4 * 6)";
	char *src = "( 8 + 2 * 5 ) / ( 1 + 3 * 2 - 4 )";
	char *dst = (char*)malloc(strlen(src) * sizeof(char));

	rpe(src, dst);
	printf("%s -> %s\n", src, dst);
}

/**
 * 6. *Реализовать очередь.
 *
 * @see queue.h
 */
void task06()
{
	TQueue que;
	
	queInit(&que, 'a');
	quePush(&que, 'b');
	quePush(&que, 'c');
	quePush(&que, 'd');
	quePush(&que, 'e');
	quePush(&que, 'f');
	quePush(&que, 'g');
	quePrint(&que);
	printf("\n");
	printf("%c, ", quePop(&que));
	printf("%c, ", quePop(&que));
	printf("%c\n", quePop(&que));
	quePrint(&que);
	printf("\n");
}

int main()
{
	//task01
	task01(25);
	printf("\n");

	//task02
	task02();
	printf("\n");

	//task03
	char *rightBuf = "(), ([])(), {}(), ([{}])";
	char *wrongBuf = ")(, ())({), (, ])}), ([(])";
	printf("The sequence \"%s\" is %s\n", rightBuf, (*task03(rightBuf)) ? "False" : "True");
	printf("The sequence \"%s\" is %s\n", wrongBuf, (*task03(wrongBuf)) ? "False" : "True");
	printf("\n");

	//task04
	task04();
	printf("\n");

	//task05
	task05();
	printf("\n");

	//task06
	task06();
	printf("\n");

	return 0;
}