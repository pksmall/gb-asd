#pragma once

#define STACK_INIT_SIZE 100

// bitree
typedef struct _bNode {
	int data;
	struct _bNode *left;
	struct _bNode *right;
	struct _bNode *parent;
} biNode;

// queue node
typedef struct _qNode {
	void *value;
	struct _qNode *next;
	struct _qNode *prev;
} qNode;

// queue
typedef struct _queLinkedList {
	size_t size;
	qNode *head;
	qNode *tail;
} queLinkedList;

// db biTree
typedef struct _dbNode {
	int idHash;
	char *name;
	int hashName;
	int age;
	int tabid;
	struct _dbNode *left;
	struct _dbNode *right;
	struct _dbNode *parent;
} dbNode;
