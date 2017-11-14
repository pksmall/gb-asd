#pragma once
#include <stdlib.h>
#include <malloc.h>
#include "nodedef.h"

typedef struct Stack {
	size_t size;
	size_t limit;
	Node **data;
} Stack;

Stack* createStack() {
	Stack *tmp = (Stack*)malloc(sizeof(Stack));
	tmp->limit = STACK_INIT_SIZE;
	tmp->size = 0;
	tmp->data = (Node**)malloc(tmp->limit * sizeof(Node*));
	return tmp;
}

void freeStack(Stack **s) {
	free((*s)->data);
	free(*s);
	*s = NULL;
}

void push(Stack *s, Node *item) {
	if (s->size >= s->limit) {
		s->limit *= 2;
		s->data = (Node**)realloc(s->data, s->limit * sizeof(Node*));
	}
	s->data[s->size++] = item;
}

Node* pop(Stack *s) {
	if (s->size == 0) {
		exit(-7);
	}
	s->size--;
	return s->data[s->size];
}

Node* peek(Stack *s) {
	return s->data[s->size - 1];
}
