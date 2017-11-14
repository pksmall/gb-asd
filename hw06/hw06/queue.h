#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "nodedef.h"

// создания очереди
queLinkedList* createQueLinkedList() 
{
	queLinkedList *tmp = (queLinkedList*)malloc(sizeof(queLinkedList));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;

	return tmp;
}

// удаление
void deleteQueLinkedList(queLinkedList **list) 
{
	qNode *tmp = (*list)->head;
	qNode *next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

// поместить в начало
void pushFront(queLinkedList *list, void *data) {
	qNode *tmp = (qNode*)malloc(sizeof(qNode));
	if (tmp == NULL) {
		exit(-1);
	}
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head) {
		list->head->prev = tmp;
	}
	list->head = tmp;

	if (list->tail == NULL) {
		list->tail = tmp;
	}
	list->size++;
}

// вытащить из начала
void* popFront(queLinkedList *list) 
{
	qNode *prev;
	void *tmp;
	if (list->head == NULL) {
		exit(-2);
	}

	prev = list->head;
	list->head = list->head->next;
	if (list->head) {
		list->head->prev = NULL;
	}
	if (prev == list->tail) {
		list->tail = NULL;
	}
	tmp = prev->value;
	free(prev);

	list->size--;
	return tmp;
}

// поместить в конец
void pushBack(queLinkedList *list, void *value) 
{
	qNode *tmp = (qNode*)malloc(sizeof(qNode));
	if (tmp == NULL) {
		exit(3);
	}
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail) {
		list->tail->next = tmp;
	}
	list->tail = tmp;

	if (list->head == NULL) {
		list->head = tmp;
	}
	list->size++;
}

// вытащить из конца
void* popBack(queLinkedList *list) 
{
	qNode *next;
	void *tmp;
	if (list->tail == NULL) {
		exit(4);
	}

	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	tmp = next->value;
	free(next);

	list->size--;
	return tmp;
}

// выбрать нужный элемент по индексу
qNode* getNth(queLinkedList *list, size_t index) 
{
	qNode *tmp = list->head;
	size_t i = 0;

	while (tmp && i < index) {
		tmp = tmp->next;
		i++;
	}

	return tmp;
}

// улучшеный выбор по индуксу 
// Это позволяет всегда использовать не более N / 2 шагов.
qNode* getNthq(queLinkedList *list, size_t index) 
{
	qNode *tmp = NULL;
	size_t i;

	if (index < list->size / 2) {
		i = 0;
		tmp = list->head;
		while (tmp && i < index) {
			tmp = tmp->next;
			i++;
		}
	}
	else {
		i = list->size - 1;
		tmp = list->tail;
		while (tmp && i > index) {
			tmp = tmp->prev;
			i--;
		}
	}

	return tmp;
}

// вставим значение по индексу
void insert(queLinkedList *list, size_t index, void *value) {
	qNode *elm = NULL;
	qNode *ins = NULL;
	elm = getNth(list, index);
	if (elm == NULL) {
		exit(-5);
	}
	ins = (qNode*)malloc(sizeof(qNode));
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next) {
		elm->next->prev = ins;
	}
	elm->next = ins;

	if (!elm->prev) {
		list->head = elm;
	}
	if (!elm->next) {
		list->tail = elm;
	}

	list->size++;
}

// удалим значени по индексу
void* deleteNth(queLinkedList *list, size_t index) 
{
	qNode *elm = NULL;
	void *tmp = NULL;
	elm = getNth(list, index);
	if (elm == NULL) {
		exit(-5);
	}
	if (elm->prev) {
		elm->prev->next = elm->next;
	}
	if (elm->next) {
		elm->next->prev = elm->prev;
	}
	tmp = elm->value;

	if (!elm->prev) {
		list->head = elm->next;
	}
	if (!elm->next) {
		list->tail = elm->prev;
	}

	free(elm);

	list->size--;

	return tmp;
}

// печатаем весю очередь
void printQueLinkedList(queLinkedList *list, void(*fun)(void*)) {
	qNode *tmp = list->head;
	while (tmp) {
		fun(tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

// печать занчения Int
void printInt(void *value) {
	printf("%d ", *((int*)value));
}

// список из массива
queLinkedList* fromArray(void *arr, size_t n, size_t size) {
	queLinkedList *tmp = NULL;
	size_t i = 0;
	if (arr == NULL) {
		exit(7);
	}

	tmp = createQueLinkedList();
	while (i < n) {
		pushBack(tmp, ((char*)arr + i*size));
		i++;
	}

	return tmp;
}
