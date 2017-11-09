#pragma once
#include <stdio.h>
#include <malloc.h>

#ifndef TCH
#define TCH char
#endif // !TCH

//​​ Опишем​​ структуру​​ узла​​ списка
struct TQNode {
	TCH value;
	struct TQNode *next;
};
typedef struct TQNode QNode;

// Queue
struct Queue {
	QNode *head;
	QNode *tail;
	int size;
	int maxsize;
};
typedef struct Queue TQueue;

int queSize(TQueue *que)
{
	return que->size;
}

void queInit(TQueue *que, TCH value)
{
	que->head = (QNode *)malloc(sizeof(QNode));
	//check memory
	if (que->head == NULL) {
		printf("Out of memory.\n");
		exit(-1);
	}
	que->tail = que->head;
	que->head->value = value;
	que->head->next = NULL;
	que->size = 1;
}

// Добавляет(вталкивает) элемент в очередь
void quePush(TQueue *que, TCH value)
{
	QNode *temp = (QNode *)malloc(sizeof(QNode));
	if (temp == NULL) {
		printf("Out of memory.\n");
		exit(-1);
	}
	temp->next = NULL;
	temp->value = value;
	que->tail->next = temp; 
	que->tail = temp;
	que->size++;
}

// Удаляет элемент(выталкивает) и возвращает его
TCH  quePop(TQueue *que)
{
	TCH ret;

	if (que->size == 0) {
		printf("Queue is empty.\n");
		return (TCH) NULL;
	}

	QNode *temp = que->head;
	ret = que->head->value;
	que->head = que->head->next;
	free(temp); 
	que->size--;
	return ret;
}

// Выгружаем значение головы без удаления
TCH quePeek(TQueue *que)
{
	TCH ret;

	if (que->size == 0) {
		printf("Queue is empty.\n");
		return (TCH) NULL;
	}
	
	ret = que->head->value;
	return ret;
}

void quePrint(TQueue *cur)
{
	QNode *current = cur->head;

	while (current != NULL) {
		printf("%c", current->value);
		current = current->next;
	}
}
