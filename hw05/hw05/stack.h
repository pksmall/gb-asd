#pragma once
#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

#ifndef TCH
#define TCH char
#endif // !TCH

struct TNode {
	TCH value;
	struct TNode *next;
};
typedef struct TNode Node;

// Stack
struct Stack {
	Node *head;
	int size;
	int maxsize;
};
typedef struct Stack TStack;

bool stkEmpty(TStack *stack)
{
	if (stack->size > 0) return false;
	return true;
}

TCH stkTop(TStack *stack)
{
	TCH ret;

	if (stack->size == 0) {
		printf("Queue is empty.\n");
		return (TCH)NULL;
	}

	ret = stack->head->value;
	return ret;
}

void stkPush(TCH value, TStack *current)
{
	if (current->size >= current->maxsize) {
		printf("Error stack size.\n");
		return;
	}
	Node *tmp = (Node *) malloc(sizeof(Node));
	//check memory
	if (tmp == NULL) {
		printf("Out of memory.\n");
		exit(-1);
	}
	tmp->value = value;
	tmp->next = current->head;
	current->head = tmp;
	current->size++;
}

TCH stkPop(TStack *cur)
{
	TCH value;

	if (cur->size == 0) {
		printf("Stack is empty.\n");
		return (char) NULL;
	}
	Node *next = cur->head;
	value = cur->head->value;
	cur->head = cur->head->next;
	free(next);
	cur->size--;
	return value;
}

// copy stack, return number's stored elements
int copyStack(TStack *src, TStack *dst)
{
	int i = 0;
	TStack tail;

	dst->head = NULL;
	tail.head = NULL;
	dst->maxsize = src->maxsize;
	tail.maxsize = src->maxsize;
	Node *current = src->head;
	while (current != NULL) {
		if (dst->head == NULL) {
			dst->head = (Node *)malloc(sizeof(Node));
			dst->head->value = current->value;
			tail.head = dst->head;
		}
		else {
			tail.head->next = (Node *)malloc(sizeof(Node));
			tail.head = tail.head->next;
			tail.head->value = current->value;
			tail.head->next = NULL;

		}
		current = current->next;
		i++;
	}
	return i;
}

void printStack(TStack *cur)
{
	Node *current = cur->head;

	while (current != NULL) {
		printf("%c", current->value);
		current = current->next;
	}
}
