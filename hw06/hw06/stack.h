#pragma once
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include "nodedef.h"

// stack for biNode
typedef struct Stack {
	size_t size;
	size_t limit;
	void **data;
} Stack;

Stack* createStack() 
{
	Stack *tmp = (Stack*)malloc(sizeof(Stack));
	tmp->limit = STACK_INIT_SIZE;
	tmp->size = 0;
	tmp->data = (biNode**)malloc(tmp->limit * sizeof(biNode*));
	return tmp;
}

void freeStack(Stack **s) 
{
	free((*s)->data);
	free(*s);
	*s = NULL;
}

void pushStack(Stack *s, void *item) 
{
	if (s->size >= s->limit) {
		s->limit *= 2;
		s->data = (biNode**) realloc(s->data, s->limit * sizeof(biNode*));
	}
	s->data[s->size++] = item;
}

biNode* popStack(Stack *s) 
{
	if (s->size == 0) {
		exit(-7);
	}
	s->size--;
	return s->data[s->size];
}

biNode* peekStack(Stack *s) 
{
	return s->data[s->size - 1];
}
