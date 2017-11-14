#pragma once

#define STACK_INIT_SIZE 100

// stack
typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

// queue node
typedef struct _Node {
	void *value;
	struct _Node *next;
	struct _Node *prev;
} qNode;

// queue
typedef struct _queLinkedList {
	size_t size;
	qNode *head;
	qNode *tail;
} queLinkedList;
